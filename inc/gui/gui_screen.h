#pragma once

#include <string>

#include <SDL_GUI/gui/primitives/rect.h>

#include <models/screen.h>
#include <gui/gui_screen_object.h>

class GuiScreen : public GuiScreenObject {
    const Screen *_screen;
    SDL_GUI::Rect *_debug_rect;
    SDL_GUI::Rect *_stats_rect;
    SDL_GUI::Rect *_graph_rect;
    protected:
        GuiScreen(std::string type, SDL_Renderer *renderer, const Screen *screen, const GameModel *game_model);
    public:
        GuiScreen(SDL_Renderer *renderer, const Screen *screen, const GameModel *game_model)
            : GuiScreen("Screen", renderer, screen, game_model) {}

        SDL_GUI::Rect *debug_rect();
        SDL_GUI::Rect *stats_rect();
        SDL_GUI::Rect *graph_rect();
};
