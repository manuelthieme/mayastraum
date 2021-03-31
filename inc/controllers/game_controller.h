#pragma once

#include <SDL_GUI/inc/application.h>
#include <SDL_GUI/inc/controllers/controller_base.h>
#include <SDL_GUI/inc/models/input_model.h>
#include <SDL_GUI/inc/models/interface_model.h>
#include <SDL_GUI/inc/gui/primitives/rect.h>
#include <SDL_GUI/inc/gui/primitives/text.h>
#include <SDL_GUI/inc/gui/style.h>
#include <SDL_GUI/inc/input_keys.h>

#include <input_keys.h>
#include <models/character.h>
#include <models/game_model.h>

class GameController : public SDL_GUI::ControllerBase {
    SDL_GUI::ApplicationBase *_application;
    GameModel *_game_model;
    SDL_GUI::InterfaceModel *_interface_model;
    const SDL_GUI::InputModel<SDL_GUI::InputKey> *_default_input_model;
    const SDL_GUI::InputModel<InputKey> *_input_model;
    void init();

    bool _debug = false;
    ScreenObject *_drag = nullptr;
    SDL_GUI::Drawable *_main;
    SDL_GUI::Drawable *_debug_active;
    SDL_GUI::Drawable *_debug_cursor;

    Character *_character;

    SDL_GUI::Rect *_debug_rect;
    SDL_GUI::Text *_fps_text;
    SDL_GUI::Text *_tps_text;
    SDL_GUI::Rect *_graph_rect;

    void update_debug();

    void init_debug_stats(SDL_GUI::Rect *stats_rect);

    void update_debug_stats();

    void update_debug_graph();
public:
    GameController(SDL_GUI::ApplicationBase *application, GameModel *game_model, SDL_GUI::InterfaceModel *interface_model, SDL_GUI::InputModel<InputKey> *inputModel);

    void update();
};
