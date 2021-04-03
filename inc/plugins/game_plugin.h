#pragma once

#include <SDL_GUI/application.h>
#include <SDL_GUI/plugins/plugin_base.h>
#include <SDL_GUI/plugins/default_plugin.h>

#include <config/input_config.h>
#include <controllers/game_controller.h>
#include <models/game_model.h>
#include <input_keys.h>

class GamePlugin : public SDL_GUI::PluginBase {
public:
    GamePlugin(): SDL_GUI::PluginBase("Game Plugin") {}

    template <typename ... Ts>
    void init(SDL_GUI::ApplicationBase *app, std::tuple<Ts...> previous, int argc, char *argv[]) {
        (void) argc;
        (void) argv;
        /* Models */
        SDL_GUI::InputModel<InputKey> *input_model = new SDL_GUI::InputModel<InputKey>();
        app->add_model(input_model);

        GameModel *game_model = new GameModel();
        app->add_model(game_model);

        /* Controllers */
        SDL_GUI::InputController<InputKey> *input_controller = new SDL_GUI::InputController<InputKey>(input_model, keyboard_input_config, window_event_config, mouse_input_config);
        app->add_controller(input_controller);

        SDL_GUI::DefaultPlugin &default_plugin = std::get<SDL_GUI::DefaultPlugin>(previous);
        SDL_GUI::InterfaceModel *interface_model = default_plugin.interface_model();

        GameController *controller = new GameController(app, game_model, interface_model, input_model);
        app->add_controller(controller);
    }
};
