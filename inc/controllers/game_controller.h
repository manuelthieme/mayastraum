#pragma once

#include <SDL_GUI/inc/controllers/controller_base.h>
#include <SDL_GUI/inc/models/input_model.h>
#include <SDL_GUI/inc/models/interface_model.h>
#include <SDL_GUI/inc/gui/style.h>

#include <input_keys.h>
#include <models/game_model.h>

class GameController : public SDL_GUI::ControllerBase {
    GameModel *_game_model;
    SDL_GUI::InterfaceModel *_interface_model;
    const SDL_GUI::InputModel<InputKey> *_input_model;
    void init();
    SDL_GUI::Style _debug_style;
public:
    GameController(GameModel *game_model, SDL_GUI::InterfaceModel *interface_model, const SDL_GUI::InputModel<InputKey> *input_model);

    void update();
};
