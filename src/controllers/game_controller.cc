#include <controllers/game_controller.h>

#include <SDL_GUI/inc/gui/primitives/texture.h>
#include <SDL_GUI/inc/gui/drawable.h>

GameController::GameController(GameModel *game_model, SDL_GUI::InterfaceModel *interface_model, const SDL_GUI::InputModel<InputKey> *input_model) : _game_model(game_model), _interface_model(interface_model), _input_model(input_model) {
    this->init();
}

void GameController::init() {
    this->_debug_style._has_border = true;
    this->_debug_style._border_width = 5;
    this->_debug_style._border_color = SDL_GUI::RGB(255,0,0,125);
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
    if (this->_input_model->is_pressed(InputKey::UP)) {
        SDL_GUI::Drawable *cabin = this->_interface_model->find_first_drawable("cabin");
        cabin->set_y(cabin->position()._y - 1);
        //std::cerr << cabin->position() << "\n";
    }
    if (this->_input_model->is_pressed(InputKey::DOWN)) {
        SDL_GUI::Drawable *cabin = this->_interface_model->find_first_drawable("cabin");
        cabin->set_y(cabin->position()._y + 1);
        //std::cerr << cabin->position() << "\n";
    }
    if (this->_input_model->is_pressed(InputKey::LEFT)) {
        SDL_GUI::Drawable *cabin = this->_interface_model->find_first_drawable("cabin");
        cabin->set_x(cabin->position()._x - 1);
        //std::cerr << cabin->position() << "\n";
    }
    if (this->_input_model->is_pressed(InputKey::RIGHT)) {
        SDL_GUI::Drawable *cabin = this->_interface_model->find_first_drawable("cabin");
        cabin->set_x(cabin->position()._x + 1);
        //std::cerr << cabin->position() << "\n";
    }

    SDL_GUI::Position mouse_position = this->_input_model->mouse_position();
    this->_interface_model->drawable_tree()->map([](SDL_GUI::Drawable *drawable) {
            drawable->set_current_style(&drawable->_default_style);
            });
    SDL_GUI::Drawable *hovered = this->_interface_model->find_first_drawable_at_position(mouse_position);
    if (hovered) {
        hovered->set_current_style(&this->_debug_style);
    }
}
