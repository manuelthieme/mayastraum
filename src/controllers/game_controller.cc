#include <controllers/game_controller.h>

#include <SDL_GUI/inc/gui/primitives/texture.h>
#include <SDL_GUI/inc/gui/drawable.h>

GameController::GameController(GameModel *game_model, SDL_GUI::InterfaceModel *interface_model, const SDL_GUI::InputModel<InputKey> *input_model) : _game_model(game_model), _interface_model(interface_model), _input_model(input_model) {
    this->_drag = this->_interface_model->null_drawable();
    this->_debug_active = this->_interface_model->null_drawable();
    this->init();
}

void GameController::init() {
    this->_debug_hover_style._has_border = true;
    this->_debug_hover_style._border_width = 5;
    this->_debug_hover_style._border_color = SDL_GUI::RGB(255,0,0,125);

    this->_debug_active_style._has_border = true;
    this->_debug_active_style._border_width = 5;
    this->_debug_active_style._border_color = SDL_GUI::RGB(0,255,0,125);


    SDL_GUI::Texture *screen_texture = new SDL_GUI::Texture(this->_game_model->_active_screen->background_path(), this->_interface_model->renderer());

    screen_texture->set_width(1920);
    screen_texture->set_height(1080);
    screen_texture->add_attribute("screen");

    SDL_GUI::TreeNode<SDL_GUI::Drawable> *screen_node = this->_interface_model->find_first_tree_node("main")->add_child(screen_texture);

    for (ScreenObject *screen_object: this->_game_model->_active_screen->screen_objects()) {
        SDL_GUI::Texture *object_texture = new SDL_GUI::Texture(screen_object->path(), this->_interface_model->renderer());
        object_texture->set_position(screen_object->position());
        object_texture->set_width(screen_object->width());
        object_texture->set_height(screen_object->height());
        object_texture->add_attribute("cabin");

        screen_node->add_child(object_texture);
        this->_game_model->_model_mapping.insert({object_texture, screen_object});
    }

}

void GameController::update() {
    if (this->_input_model->is_down(InputKey::TOGGLE_DEBUG)) {
        this->_debug = not this->_debug;
    }
    if (this->_debug) {
        this->update_debug();
    }
}
void GameController::update_debug() {
    SDL_GUI::Position mouse_position = this->_input_model->mouse_position();
    SDL_GUI::Drawable *hovered = this->_interface_model->find_first_drawable_at_position(mouse_position);

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

    this->_interface_model->drawable_tree()->map([](SDL_GUI::Drawable *drawable) {
            drawable->set_current_style(&drawable->_default_style);
        });

    if (hovered) {
        hovered->set_current_style(&this->_debug_hover_style);
    }
    this->_debug_active->set_current_style(&this->_debug_active_style);

    if (this->_drag != nullptr) {
        this->_drag->move(this->_input_model->mouse_offset());
    }
    if (this->_input_model->is_down(InputKey::CLICK)) {
        this->_drag = hovered;
    }
    if (this->_input_model->is_up(InputKey::CLICK)) {
        this->_drag = nullptr;
    }
}
