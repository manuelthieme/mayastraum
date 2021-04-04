#include <controllers/game_controller.h>

#include <sstream>

#include <SDL_GUI/gui/primitives/line.h>
#include <SDL_GUI/gui/primitives/rect.h>
#include <SDL_GUI/gui/primitives/text.h>
#include <SDL_GUI/gui/primitives/texture.h>
#include <SDL_GUI/gui/drawable.h>

#include <gui/gui_screen.h>
#include <gui/gui_screen_object.h>


GameController::GameController(SDL_GUI::ApplicationBase *application, GameModel *game_model, SDL_GUI::InterfaceModel *interface_model, SDL_GUI::InputModel<InputKey, InputState> *input_model) : _application(application), _game_model(game_model), _interface_model(interface_model), _input_model(input_model) {
    this->init();
}

void GameController::init() {
    this->init_view();
}

void GameController::init_view() {
    this->init_screen_view();
    this->init_screen_objects_view();
    this->init_character_view();
}

void GameController::init_screen_view() {
    /* set screen background */
    GuiScreen *screen_texture =
        new GuiScreen(this->_game_model->_active_screen, this->_interface_model->renderer());

    this->_game_model->_screen_texture = screen_texture;
    this->_game_model->_stats_rect     = screen_texture->stats_rect();
    this->_game_model->_debug_rect     = screen_texture->debug_rect();
    this->_game_model->_graph_rect     = screen_texture->graph_rect();

    this->init_debug_stats();

    screen_texture->set_width(1920);
    screen_texture->set_height(1080);
    screen_texture->add_attribute("screen");

    this->_game_model->_main = this->_interface_model->find_first_drawable("main");
    this->_game_model->_main->add_child(screen_texture);
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
}

void GameController::init_screen_objects_view() {
    /* init screenobjects */
    for (ScreenObject *screen_object: this->_game_model->_active_screen->screen_objects()) {
        GuiScreenObject *object_texture = new GuiScreenObject(this->_interface_model->renderer(),
                                                              screen_object, this->_game_model);
        object_texture->add_attribute(screen_object->_name);
        object_texture->_style._border_width = 5;

        this->_game_model->_screen_texture->add_child(object_texture);

        this->_game_model->_model_mapping.insert({object_texture, screen_object});
    }
}

void GameController::init_character_view() {
    /* init Character */
    GuiScreenObject *object_texture = new GuiScreenObject(this->_interface_model->renderer(),
                                                          this->_game_model->_character,
                                                          this->_game_model);
    object_texture->add_attribute("character");
    object_texture->_style._border_width = 5;

    this->_game_model->_screen_texture->add_child(object_texture);

    this->_game_model->_model_mapping.insert({object_texture, this->_game_model->_character});
}

void GameController::update() {
    if (this->_input_model->is_pressed(InputKey::QUIT)) {
        this->_application->_is_running = false;
    }
    if (this->_input_model->is_down(InputKey::MOVE_CHARACTER)) {
        this->_game_model->_character->set_target({Point(this->_input_model->mouse_position())});
        this->_game_model->_character->start_running();
    }

    if (this->_input_model->is_down(InputKey::TOGGLE_DEBUG)) {
        this->_interface_model->toggle_debug_information_drawn();
        this->_game_model->_debugging = this->_interface_model->debug_information_drawn();
        if (this->_game_model->_debugging) {
            this->_input_model->set_state(InputState::DEBUG);
        } else {
            this->_input_model->set_state(InputState::ALL);
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


    this->_game_model->_character->tick();



    if (this->_game_model->_debugging) {
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
    this->update_debug_rect();
    this->update_debug_borders();


    /* update hovered */
    SDL_GUI::Drawable *screen = this->_game_model->_screen_texture;
    SDL_GUI::Position mouse_position = this->_input_model->mouse_position();

    this->_game_model->_hovered =
        this->_interface_model->find_first_drawable_at_position(mouse_position, screen);
    this->_game_model->_all_hovered
        = this->_interface_model->find_drawables_at_position(mouse_position, screen);

    /* update active if click on hovered */
    SDL_GUI::Drawable *hovered = this->_game_model->_hovered;
    auto &debug_active = this->_game_model->_debug_active;
    if (this->_input_model->is_down(InputKey::CHANGE_DEBUG_OBJECT)
            && hovered
            && hovered != this->_game_model->_main) {
        this->_game_model->_debug_active = hovered;
        this->_game_model->_drag_movement = Point();
        this->_game_model->_dragging = false;

        if (this->_game_model->_model_mapping.contains(debug_active)) {
            this->_game_model->_debug_active_object =
                this->_game_model->_model_mapping.at(debug_active);
        } else {
            this->_game_model->_debug_active_object = nullptr;
        }
    }


    ScreenObject *debug_active_object = this->_game_model->_debug_active_object;
    if (debug_active_object) {
        /* move active object */
        if (this->_input_model->is_pressed(InputKey::MOVE_UP)) {
            debug_active_object->move({0,-1});
        }
        if (this->_input_model->is_pressed(InputKey::MOVE_DOWN)) {
            debug_active_object->move({0,1});
        }
        if (this->_input_model->is_pressed(InputKey::MOVE_LEFT)) {
            debug_active_object->move({-1,0});
        }
        if (this->_input_model->is_pressed(InputKey::MOVE_RIGHT)) {
            debug_active_object->move({1,0});
        }

        /* toggle hitbox creation */
        if (this->_input_model->is_down(InputKey::TOGGLE_EDIT_HITBOX)) {
            this->_game_model->_editing_hitbox = this->_game_model->_editing_hitbox;
            /* change input state */
            if (this->_game_model->_editing_hitbox) {
               this->_input_model->set_state(InputState::EDIT_HITBOX);
            } else {
               this->_input_model->set_state(InputState::DEBUG);
            }
        }



        /* drag active object */
        if (this->_input_model->is_pressed(InputKey::CHANGE_DEBUG_OBJECT)) {
            this->_game_model->_drag_movement += this->_input_model->mouse_offset();
            if (this->_game_model->_dragging
                    || this->_game_model->_drag_movement.magnitude() > 20) {
                debug_active_object->move(this->_game_model->_drag_movement);
                this->_game_model->_dragging = true;
                this->_game_model->_drag_movement = Point();
            }
        }

        /* print yaml to stdout */
        if (this->_input_model->is_down(InputKey::SERIALISE)) {
            std::cout << std::endl << debug_active_object->serialise() << std::endl;
        }
    }
}

void GameController::update_debug_rect() {
    this->_game_model->_debug_rect->remove_all_children();

    /* print information about all hovered objects */
    int offset = 0;
    for (SDL_GUI::Drawable *d: this->_game_model->_all_hovered) {
        std::vector<std::string> attributes = d->attributes();
        std::string name = attributes.size() ? attributes[0] : "--noname--";
        std::stringstream ss;
        ss << name << " (" << d->_type << ")";
        SDL_GUI::Text *t = new SDL_GUI::Text(this->_interface_model->font(), ss.str());
        t->set_y(offset);
        this->_game_model->_debug_rect->add_child(t);
        offset += t->height();
    }

    SDL_GUI::Drawable *debug_active = this->_game_model->_debug_active;
    /* abort if there is no active object */
    if (not debug_active) {
        return;
    }

    /* print information about active object */
    /* attribute */
    std::vector<std::string> attributes = debug_active->attributes();
    std::string name = attributes.size() ? attributes[0] : "--noname--";
    std::stringstream ss;
    ss << name << " (" << debug_active->_type << ")";
    SDL_GUI::Text *t = new SDL_GUI::Text(this->_interface_model->font(), ss.str());
    offset += 10;
    t->set_y(offset);
    offset += t->height();
    this->_game_model->_debug_rect->add_child(t);

    /* Position */
    ss.str("");
    ss << "Position: " << debug_active->position();
    t = new SDL_GUI::Text(this->_interface_model->font(), ss.str());
    t->set_y(offset);
    offset += t->height();
    this->_game_model->_debug_rect->add_child(t);

    /* mouse position inside */
    SDL_GUI::Position mouse_position = this->_input_model->mouse_position();
    ss.str("");
    ss << "Mouse relative: ";
    if (debug_active->is_inside(mouse_position)) {
        ss << mouse_position - debug_active->position();
    } else {
        ss << "--not inside--";
    }
    t = new SDL_GUI::Text(this->_interface_model->font(), ss.str());
    t->set_y(offset);
    offset += t->height();
    this->_game_model->_debug_rect->add_child(t);

    /* Name if exists */
    if (not this->_game_model->_debug_active_object) {
        return;
    }

    ss.str("");
    ss << "Name: " << this->_game_model->_debug_active_object->_name;
    t = new SDL_GUI::Text(this->_interface_model->font(), ss.str());
    t->set_y(offset);
    offset += t->height();
    this->_game_model->_debug_rect->add_child(t);
}

void GameController::update_debug_borders() {
    SDL_GUI::Drawable *hovered = this->_game_model->_hovered;

    /* reset border everywhere */
    this->_interface_model->drawable_root()->map([](SDL_GUI::Drawable *drawable) {
            drawable->_style._has_border = false;
        });

    SDL_GUI::Drawable *debug_active = this->_game_model->_debug_active;
    /* activate border of debugging target */
    if (debug_active) {
        debug_active->_style._has_border = true;
        debug_active->_style._border_color = SDL_GUI::RGB("green");
    }

    if (hovered && hovered != this->_game_model->_main) {
        /* draw border of hovered object */
        if (hovered != debug_active) {
            hovered->_style._has_border = true;
            hovered->_style._border_color = SDL_GUI::RGB("red");
        }

    }
}

void GameController::init_debug_stats() {
    SDL_GUI::Drawable *stats_rect = this->_game_model->_stats_rect;
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
    this->_game_model->_fps_text = t;

    ss.str("");
    ss << this->_application->current_tps();
    t = new SDL_GUI::Text(this->_interface_model->font(), ss.str());
    t->move({width, height});
    stats_rect->add_child(t);
    this->_game_model->_tps_text = t;

    height += t->height();

    stats_rect->set_height(height);

    stats_rect->set_width(2 * width);
    stats_rect->set_x(1920 - 2 * width);
}

void GameController::update_debug_stats() {
    std::stringstream ss;
    ss << this->_application->current_fps();
    this->_game_model->_fps_text->set_text(ss.str());

    ss.str("");
    ss << this->_application->current_tps();
    this->_game_model->_tps_text->set_text(ss.str());
}

void GameController::update_debug_graph() {
    this->_game_model->_graph_rect->remove_all_children();
    Point from = this->_game_model->_character->position();
    for (Point to: this->_game_model->_character->path()) {
        SDL_GUI::Line *l = new SDL_GUI::Line({static_cast<int>(from.x()),
                                              static_cast<int>(from.y())},
                                             {static_cast<int>(to.x() - from.x()),
                                              static_cast<int>(to.y() - from.y())});
        l->_style._color = SDL_GUI::RGB("red");
        this->_game_model->_graph_rect->add_child(l);
        from = to;
    }
}
