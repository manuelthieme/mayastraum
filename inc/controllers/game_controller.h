#pragma once

#include <SDL_GUI/application.h>
#include <SDL_GUI/controllers/controller_base.h>
#include <SDL_GUI/models/input_model.h>
#include <SDL_GUI/models/interface_model.h>
#include <SDL_GUI/gui/primitives/rect.h>
#include <SDL_GUI/gui/primitives/text.h>
#include <SDL_GUI/gui/style.h>
#include <SDL_GUI/config/input_config.h>

#include <config/input_config.h>
#include <models/character.h>
#include <models/game_model.h>

class GameController : public SDL_GUI::ControllerBase {
    SDL_GUI::ApplicationBase *_application;
    GameModel *_game_model;
    SDL_GUI::InterfaceModel *_interface_model;
    const SDL_GUI::InputModel<SDL_GUI::InputKey, SDL_GUI::InputState> *_default_input_model;
    SDL_GUI::InputModel<InputKey, InputState> *_input_model;

    void init();

    void init_view();

    void init_screen_view();

    void init_screen_objects_view();

    void init_character_view();

    void init_debug_stats();

    void update_debug();

    void update_debug_rect();

    void update_debug_borders();


    void update_debug_stats();

    void update_debug_graph();
public:
    GameController(SDL_GUI::ApplicationBase *application, GameModel *game_model, SDL_GUI::InterfaceModel *interface_model, SDL_GUI::InputModel<InputKey, InputState> *inputModel);

    void update();
};
