#include <application.h>

#include <SDL_GUI/inc/controllers/input_controller.h>
#include <SDL_GUI/inc/controllers/interface_controller.h>
#include <SDL_GUI/inc/models/interface_model.h>
#include <SDL_GUI/inc/views/interface_view.h>

#include <config/input_config.h>
#include <controllers/game_controller.h>
#include <models/game_model.h>

void Application::update_running() {
    if (this->_input_model->is_down(InputKey::QUIT)) {
        this->_is_running = false;
    }
}

void Application::init_MVCs() {
    /**********
     * Models *
     **********/
    SDL_GUI::InterfaceModel *interface_model = new SDL_GUI::InterfaceModel();
    this->_model_list.push_back(interface_model);

    this->_input_model = new SDL_GUI::InputModel<InputKey>();
    this->_model_list.push_back(this->_input_model);

    GameModel *game_model = new GameModel();
    this->_model_list.push_back(game_model);

    /***************
     * Controllers *
     ***************/
    SDL_GUI::InputController<InputKey> *input_controller = new SDL_GUI::InputController<InputKey>(this->_input_model, keyboard_input_config, window_event_config, mouse_input_config);
    this->_controller_list.push_back(input_controller);

    GameController *game_controller = new GameController(game_model);
    this->_controller_list.push_back(game_controller);

    SDL_GUI::InterfaceController *interface_controller = new SDL_GUI::InterfaceController("templates/main.tpl", interface_model, this->_input_model);
    this->_controller_list.push_back(interface_controller);

    /*********
     * Views *
     *********/
    SDL_GUI::InterfaceView *interface_view = new SDL_GUI::InterfaceView(this->_renderer, interface_model);
    this->_view_list.push_back(interface_view);
}
