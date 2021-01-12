#pragma once

#include <SDL2/SDL.h>

#include <SDL_GUI/inc/gui/primitives/texture.h>

#include <models/screen_object.h>

class GuiScreenObject : public SDL_GUI::Texture {
    const ScreenObject *_screen_object;

    virtual void update() override;
public:
    GuiScreenObject(SDL_Renderer *renderer, const ScreenObject *screen_object);
};
