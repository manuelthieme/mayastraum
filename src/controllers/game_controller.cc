#include <controllers/game_controller.h>

#include <sstream>

#include <SDL_GUI/gui/primitives/line.h>
#include <SDL_GUI/gui/primitives/rect.h>
#include <SDL_GUI/gui/primitives/text.h>
#include <SDL_GUI/gui/primitives/texture.h>
#include <SDL_GUI/gui/drawable.h>

#include <gui/gui_screen.h>
#include <gui/gui_screen_object.h>


GameController::GameController(SDL_GUI::ApplicationBase *application, GameModel *game_model, SDL_GUI::InterfaceModel *interface_model, SDL_GUI::InputModel<InputKey> *input_model) : _application(application), _game_model(game_model), _interface_model(interface_model), _input_model(input_model) {
    this->_debug_active = this->_interface_model->null_drawable();
    this->init();
}
void GameController::init() {
    /* set screen background */
    GuiScreen *screen_texture = new
        GuiScreen(this->_game_model->_active_screen, this->_interface_model->renderer());

    this->_debug_rect = screen_texture->debug_rect();
    this->_graph_rect = screen_texture->graph_rect();

    this->init_debug_stats(screen_texture->stats_rect());

    screen_texture->set_width(1920);
    screen_texture->set_height(1080);
    screen_texture->add_attribute("screen");

    this->_main = this->_interface_model->find_first_drawable("main");
    this->_main->add_child(screen_texture);
    const std::map<SDL_GUI::Drawable *, ScreenObject *> *model_mapping =
        &this->_game_model->_model_mapping;
    screen_texture->add_recalculation_callback([model_mapping](SDL_GUI::Drawable *d){
        d->sort_children(
            [model_mapping](SDL_GUI::Drawable *a, SDL_GUI::Drawable *b){
                if (not model_mapping->contains(a) or not model_mapping->contains(b)) {
                    return false;
                }
                return model_mapping->at(a)->position().y() < model_mapping->at(b)->position().y();
            });
    });


    /* init screenobjects */
    for (ScreenObject *screen_object: this->_game_model->_active_screen->screen_objects()) {
        GuiScreenObject *object_texture = new GuiScreenObject(this->_interface_model->renderer(),
                                                              screen_object, this->_game_model);
        object_texture->add_attribute(screen_object->_name);
        object_texture->_style._border_width = 5;

        screen_texture->add_child(object_texture);

        this->_game_model->_model_mapping.insert({object_texture, screen_object});
    }

    /* init cursor debug information */
    auto * debug_cursor = new SDL_GUI::Rect();
    this->_debug_cursor = debug_cursor;
    this->_debug_cursor->add_attribute("debug_cursor");
    auto input_model = this->_input_model;
    this->_debug_cursor->add_recalculation_callback([input_model](SDL_GUI::Drawable *d){
            SDL_GUI::Position mouse_position = input_model->mouse_position();
            d->set_position(mouse_position);
            //std::cout << "cursor position: " << d->absolute_position() << "\n";
        });
    this->_main->add_child(this->_debug_cursor);

    /* init Character */
    this->_character = new Character("characters/strichmann.png", {500, 500}, 150, 180);
    this->_character->set_pivot({60, 175});

    GuiScreenObject *object_texture = new GuiScreenObject(this->_interface_model->renderer(),
                                                          this->_character, this->_game_model);
    object_texture->add_attribute("character");
    object_texture->_style._border_width = 5;

    screen_texture->add_child(object_texture);

    this->_game_model->_model_mapping.insert({object_texture, this->_character});
}

void GameController::update() {
    if (this->_input_model->is_pressed(InputKey::QUIT)) {
        this->_application->_is_running = false;
    }
    if (this->_input_model->is_down(InputKey::RIGHT_CLICK)) {
        this->_character->set_target({Point(this->_input_model->mouse_position())});
        this->_character->start_running();
    }

    if (this->_input_model->is_down(InputKey::TOGGLE_DEBUG)) {
        this->_interface_model->toggle_debug_information_drawn();
        this->_debug = this->_interface_model->debug_information_drawn();
        if (not this->_debug) {
            /* reset border everywhere */
            this->_interface_model->drawable_root()->map([](SDL_GUI::Drawable *drawable) {
                    drawable->_style._has_border = false;
                });
        }
    }

    if (this->_input_model->is_down(InputKey::TOGGLE_DEBUG_PIVOT)) {
        this->_game_model->_debugging_pivot = !this->_game_model->_debugging_pivot;
    }

    if (this->_input_model->is_down(InputKey::TOGGLE_DEBUG_STATS)) {
        this->_game_model->_debugging_stats = !this->_game_model->_debugging_stats;
    }

    if (this->_input_model->is_down(InputKey::TOGGLE_DEBUG_GRAPH)) {
        this->_game_model->_debugging_graph = !this->_game_model->_debugging_graph;
    }

    if (this->_input_model->is_down(InputKey::TOGGLE_DEBUG_HITBOXES)) {
        this->_game_model->_debugging_hitboxes = !this->_game_model->_debugging_hitboxes;
    }


    this->_character->tick();



    if (this->_debug) {
        this->update_debug();
    }

    if (this->_game_model->_debugging_stats) {
        this->update_debug_stats();
    }

    if (this->_game_model->_debugging_graph) {
        this->update_debug_graph();
    }
}

void GameController::update_debug() {
    this->_debug_rect->remove_all_children();

    SDL_GUI::Position mouse_position = this->_input_model->mouse_position();
    SDL_GUI::Drawable *screen = this->_interface_model->find_first_drawable("screen");

    std::vector<SDL_GUI::Drawable *> all_hovered
        = this->_interface_model->find_drawables_at_position(mouse_position, screen);
    SDL_GUI::Drawable *hovered =
        this->_interface_model->find_first_drawable_at_position(mouse_position, screen);

    int offset = 0;
    for (SDL_GUI::Drawable *d: all_hovered) {
        std::vector<std::string> attributes = d->attributes();
        std::string name = attributes.size() ? attributes[0] : "--noname--";
        std::stringstream ss;
        ss << name << " (" << d->_type << ")";
        SDL_GUI::Text *t = new SDL_GUI::Text(this->_interface_model->font(), ss.str());
        t->set_y(offset);
        this->_debug_rect->add_child(t);
        offset += t->height();
    }

    if (this->_debug_active) {
        std::vector<std::string> attributes = this->_debug_active->attributes();
        std::string name = attributes.size() ? attributes[0] : "--noname--";
        std::stringstream ss;
        ss << name << " (" << this->_debug_active->_type << ")";
        SDL_GUI::Text *t = new SDL_GUI::Text(this->_interface_model->font(), ss.str());
        offset += 10;
        t->set_y(offset);
        offset += t->height();
        this->_debug_rect->add_child(t);

        ss.str("");
        ss << "Position: " << this->_debug_active->position();
        t = new SDL_GUI::Text(this->_interface_model->font(), ss.str());
        t->set_y(offset);
        offset += t->height();
        this->_debug_rect->add_child(t);

        ss.str("");
        ss << "Mouse relative: ";
        if (this->_debug_active->is_inside(mouse_position)) {
            ss << mouse_position - this->_debug_active->position();
        } else {
            ss << "--not inside--";
        }
        t = new SDL_GUI::Text(this->_interface_model->font(), ss.str());
        t->set_y(offset);
        offset += t->height();
        this->_debug_rect->add_child(t);

        if (this->_debug_screen_object) {
            ss.str("");
            ss << "Name: " << this->_debug_screen_object->_name;
            t = new SDL_GUI::Text(this->_interface_model->font(), ss.str());
            t->set_y(offset);
            offset += t->height();
            this->_debug_rect->add_child(t);
        }

    }


    /* reset border everywhere */
    this->_interface_model->drawable_root()->map([](SDL_GUI::Drawable *drawable) {
            drawable->_style._has_border = false;
        });

    /* activate border of debugging target */
    if (this->_debug_active) {
        this->_debug_active->_style._has_border = true;
    }

    if (hovered && hovered != this->_main) {
        /* draw border of hovered object */
        if (hovered != this->_debug_active) {
            hovered->_style._has_border = true;
            hovered->_style._border_color = SDL_GUI::RGB("red");
        }

        if (this->_input_model->is_down(InputKey::CLICK)) {
            this->_debug_active = hovered;
            this->_debug_active->_style._has_border = true;
            this->_debug_active->_style._border_color = SDL_GUI::RGB("green");

            if (this->_game_model->_model_mapping.contains(this->_debug_active)) {
                this->_debug_screen_object =
                    this->_game_model->_model_mapping.at(this->_debug_active);
            } else {
                this->_debug_screen_object = nullptr;
            }
        }
    }

    if (this->_debug_screen_object) {
        /* move active object */
        if (this->_input_model->is_pressed(InputKey::UP)) {
            this->_debug_screen_object->move({0,-1});
        }
        if (this->_input_model->is_pressed(InputKey::DOWN)) {
            this->_debug_screen_object->move({0,1});
        }
        if (this->_input_model->is_pressed(InputKey::LEFT)) {
            this->_debug_screen_object->move({-1,0});
        }
        if (this->_input_model->is_pressed(InputKey::RIGHT)) {
            this->_debug_screen_object->move({1,0});
        }

        /* print yaml to stdout */
        if (this->_input_model->is_down(InputKey::SERIALISE)) {
            std::cout << std::endl << this->_debug_screen_object->serialise() << std::endl;
        }
    }


    if (this->_drag != nullptr) {
        this->_drag->move(this->_input_model->mouse_offset());
    }
    if (this->_input_model->is_down(InputKey::CLICK)
        && hovered
        && hovered != this->_main
        && this->_game_model->_model_mapping.contains(hovered)) {
        this->_drag = this->_game_model->_model_mapping.at(hovered);
    }
    if (this->_input_model->is_up(InputKey::CLICK)) {
        this->_drag = nullptr;
    }
}

void GameController::init_debug_stats(SDL_GUI::Rect *stats_rect) {
    stats_rect->remove_all_children();

    SDL_GUI::Text *t = new SDL_GUI::Text(this->_interface_model->font(), "FPS:");
    stats_rect->add_child(t);

    int height = t->height();
    int width = t->width();

    t = new SDL_GUI::Text(this->_interface_model->font(), "TPS:");
    t->move({0, height});
    stats_rect->add_child(t);

    width = std::max(width, static_cast<int>(t->width()));

    std::stringstream ss;
    ss << this->_application->current_fps();
    t = new SDL_GUI::Text(this->_interface_model->font(), ss.str());
    t->move({width, 0});
    stats_rect->add_child(t);
    this->_fps_text = t;

    ss.str("");
    ss << this->_application->current_tps();
    t = new SDL_GUI::Text(this->_interface_model->font(), ss.str());
    t->move({width, height});
    stats_rect->add_child(t);
    this->_tps_text = t;

    height += t->height();

    stats_rect->set_height(height);

    stats_rect->set_width(2 * width);
    stats_rect->set_x(1920 - 2 * width);
}

void GameController::update_debug_stats() {
    std::stringstream ss;
    ss << this->_application->current_fps();
    this->_fps_text->set_text(ss.str());

    ss.str("");
    ss << this->_application->current_tps();
    this->_tps_text->set_text(ss.str());
}

void GameController::update_debug_graph() {
    this->_graph_rect->remove_all_children();
    Point from = this->_character->position();
    for (Point to: this->_character->path()) {
        SDL_GUI::Line *l = new SDL_GUI::Line({static_cast<int>(from.x()),
                                              static_cast<int>(from.y())},
                                             {static_cast<int>(to.x() - from.x()),
                                              static_cast<int>(to.y() - from.y())});
        l->_style._color = SDL_GUI::RGB("red");
        this->_graph_rect->add_child(l);
        from = to;
    }
}
