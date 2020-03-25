#pragma once

#include <SDL_GUI/inc/controllers/controller_base.h>
#include <SDL_GUI/inc/models/interface_model.h>

#include <models/game_model.h>

class GameController : public SDL_GUI::ControllerBase {
    GameModel *_game_model;
    SDL_GUI::InterfaceModel *_interface_model;
    void init();
public:
    GameController(GameModel *game_model, SDL_GUI::InterfaceModel *interface_model);

    void update() {}
};
