#pragma once

#include <SDL2/SDL.h>

#include <SDL_GUI/gui/primitives/texture.h>

#include <models/game_model.h>
#include <models/screen_object.h>

class GuiScreenObject : public SDL_GUI::Texture {
    const ScreenObject *_screen_object;

    virtual void update() override;
protected:
    GuiScreenObject(std::string type, SDL_Renderer *renderer, const ScreenObject *screen_object,
                    const GameModel *game_model);
public:
    GuiScreenObject(SDL_Renderer *renderer, const ScreenObject *screen_object,
                    const GameModel *game_model)
        : GuiScreenObject("ScreenObject", renderer, screen_object, game_model) {}

};
