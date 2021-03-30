#include <controllers/game_controller.h>

#include <sstream>

#include <SDL_GUI/inc/gui/primitives/rect.h>
#include <SDL_GUI/inc/gui/primitives/text.h>
#include <SDL_GUI/inc/gui/primitives/texture.h>
#include <SDL_GUI/inc/gui/drawable.h>

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
    }

    if (this->_input_model->is_down(InputKey::TOGGLE_DEBUG_PIVOT)) {
        this->_game_model->_debugging_pivot = !this->_game_model->_debugging_pivot;
    }


    this->_character->tick();



    if (this->_debug) {
        this->update_debug();
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
        t->set_y(offset + 10);
        this->_debug_rect->add_child(t);
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
        }
        if (this->_input_model->is_pressed(InputKey::UP)) {
            this->_debug_active->move({0,-1});
        }
        if (this->_input_model->is_pressed(InputKey::DOWN)) {
            this->_debug_active->move({0,1});
        }
        if (this->_input_model->is_pressed(InputKey::LEFT)) {
            this->_debug_active->move({-1,0});
        }
        if (this->_input_model->is_pressed(InputKey::RIGHT)) {
            this->_debug_active->move({1,0});
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
