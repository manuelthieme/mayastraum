#pragma once

#include <map>

#include <SDL2/SDL.h>

#include <input_keys.h>

const std::map<SDL_Scancode, InputKey> keyboard_input_config = {
    {SDL_SCANCODE_Q, InputKey::QUIT},
    {SDL_SCANCODE_ESCAPE, InputKey::QUIT},
    {SDL_SCANCODE_K, InputKey::UP},
    {SDL_SCANCODE_J, InputKey::DOWN},
    {SDL_SCANCODE_H, InputKey::LEFT},
    {SDL_SCANCODE_L, InputKey::RIGHT},
};

const std::map<SDL_WindowEventID, InputKey> window_event_config;

const std::map<Uint8, InputKey> mouse_input_config;
