#include <controllers/game_controller.h>

#include <sstream>

#include <SDL_GUI/inc/gui/primitives/rect.h>
#include <SDL_GUI/inc/gui/primitives/text.h>
#include <SDL_GUI/inc/gui/primitives/texture.h>
#include <SDL_GUI/inc/gui/drawable.h>


GameController::GameController(SDL_GUI::ApplicationBase *application, GameModel *game_model, SDL_GUI::InterfaceModel *interface_model, SDL_GUI::InputModel<InputKey> *input_model) : _application(application), _game_model(game_model), _interface_model(interface_model), _input_model(input_model) {
    this->_drag = this->_interface_model->null_drawable();
    this->_debug_active = this->_interface_model->null_drawable();
    this->init();
}

void GameController::init() {
    /* init debug styles */
    this->_debug_hover_style._has_border = true;
    this->_debug_hover_style._border_width = 5;
    this->_debug_hover_style._border_color = SDL_GUI::RGB(255,0,0,125);

    this->_debug_active_style._has_border = true;
    this->_debug_active_style._border_width = 5;
    this->_debug_active_style._border_color = SDL_GUI::RGB(0,255,0,125);


    /* set screen background */
    SDL_GUI::Texture *screen_texture = new SDL_GUI::Texture(this->_game_model->_active_screen->background_path(), this->_interface_model->renderer());

    screen_texture->set_width(1920);
    screen_texture->set_height(1080);
    screen_texture->add_attribute("screen");

    this->_main = this->_interface_model->find_first_drawable("main");
    this->_main->add_child(screen_texture);


    /* init screenobjects */
    for (ScreenObject *screen_object: this->_game_model->_active_screen->screen_objects()) {
        SDL_GUI::Texture *object_texture = new SDL_GUI::Texture(screen_object->path(), this->_interface_model->renderer());
        object_texture->set_position(screen_object->position());
        object_texture->set_width(screen_object->width());
        object_texture->set_height(screen_object->height());
        object_texture->add_attribute("cabin");

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

    SDL_GUI::Texture *object_texture = new SDL_GUI::Texture("characters/strichmann.png", this->_interface_model->renderer());
    object_texture->set_position(this->_character->position());
    object_texture->set_width(this->_character->width());
    object_texture->set_height(this->_character->height());
    object_texture->add_attribute("character");

    screen_texture->add_child(object_texture);

    //this->_game_model->_model_mapping.insert({object_texture, screen_object});
    Character *character = this->_character;
    object_texture->add_recalculation_callback([character](SDL_GUI::Drawable *d){
        d->set_position(character->position());
    });
}

void GameController::update() {
    if (this->_input_model->is_pressed(InputKey::QUIT)) {
        this->_application->_is_running = false;
    }
    if (this->_input_model->is_down(InputKey::CLICK)) {
        this->_character->setTarget({Point(this->_input_model->mouse_position())});
        this->_character->startRunning();
    }

    if (this->_input_model->is_down(InputKey::TOGGLE_DEBUG)) {
        this->toggle_debug();
    }


    this->_character->tick();



    if (this->_debug) {
        this->update_debug();
    }
}

void GameController::toggle_debug() {
    this->_debug = not this->_debug;
    bool debug = this->_debug;
    this->_interface_model->drawable_root()->map([debug](SDL_GUI::Drawable *drawable) {
            drawable->set_debug_information_shown(debug);
        });
}

void GameController::update_debug() {
    SDL_GUI::Position mouse_position = this->_input_model->mouse_position();
    SDL_GUI::Drawable *hovered = this->_interface_model->find_first_drawable_at_position(mouse_position);

    if (hovered && hovered != this->_main) {
        if (this->_input_model->is_down(InputKey::CLICK)) {
            this->_debug_active = hovered;
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

    this->_interface_model->drawable_root()->map([](SDL_GUI::Drawable *drawable) {
            drawable->set_current_style(&drawable->_default_style);
        });

    if (hovered && hovered != this->_main) {
        hovered->set_current_style(&this->_debug_hover_style);
    }
    this->_debug_active->set_current_style(&this->_debug_active_style);

    if (this->_drag != nullptr) {
        this->_drag->move(this->_input_model->mouse_offset());
    }
    if (this->_input_model->is_down(InputKey::CLICK) && hovered && hovered != this->_main) {
        this->_drag = hovered;
    }
    if (this->_input_model->is_up(InputKey::CLICK)) {
        this->_drag = nullptr;
    }
}
