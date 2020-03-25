#include <controllers/game_controller.h>

#include <SDL_GUI/inc/gui/primitives/texture.h>

GameController::GameController(GameModel *game_model, SDL_GUI::InterfaceModel *interface_model) : _game_model(game_model), _interface_model(interface_model) {
    this->init();
}

void GameController::init() {
    SDL_GUI::Texture *screen_texture = new SDL_GUI::Texture(this->_game_model->_active_screen->background_path(), this->_interface_model->renderer());

    screen_texture->set_width(1920);
    screen_texture->set_height(1080);

    this->_interface_model->find_first_tree_node("main")->add_child(screen_texture);

}
