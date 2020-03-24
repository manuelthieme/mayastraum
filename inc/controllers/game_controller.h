#pragma once

#include <SDL_GUI/inc/controllers/controller_base.h>

#include <models/game_model.h>

class GameController : public SDL_GUI::ControllerBase {
    GameModel *_game_model;
public:
    GameController(GameModel *game_model) : _game_model(game_model) {}

    void update() {}
};
