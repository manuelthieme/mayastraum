#pragma once

#include <map>

#include <SDL2/SDL.h>

#include <input_keys.h>

const std::map<SDL_Scancode, InputKey> keyboard_input_config = {
    {SDL_SCANCODE_Q, InputKey::QUIT},
    {SDL_SCANCODE_ESCAPE, InputKey::QUIT},
};

const std::map<SDL_WindowEventID, InputKey> window_event_config;

const std::map<Uint8, InputKey> mouse_input_config;
