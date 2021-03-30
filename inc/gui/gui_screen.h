#pragma once

#include <string>

#include <SDL_GUI/inc/gui/primitives/texture.h>
#include <SDL_GUI/inc/gui/primitives/rect.h>

#include <models/screen.h>

class GuiScreen : public SDL_GUI::Texture {
    const Screen *_screen;
    SDL_GUI::Rect *_debug_rect;
    SDL_GUI::Rect *_stats_rect;
    protected:
        GuiScreen(std::string type, const Screen *screen, SDL_Renderer *renderer);
    public:
        GuiScreen(const Screen *screen, SDL_Renderer *renderer)
            : GuiScreen("Screen", screen, renderer) {}

        SDL_GUI::Rect *debug_rect();
        SDL_GUI::Rect *stats_rect();
};
