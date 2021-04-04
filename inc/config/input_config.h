#pragma once

#include <map>
#include <set>

#include <SDL2/SDL.h>

enum class InputKey {
    QUIT,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    CLICK,
    MOVE_CHARACTER,
    TOGGLE_DEBUG,
    TOGGLE_DEBUG_PIVOT,
    TOGGLE_DEBUG_STATS,
    TOGGLE_DEBUG_GRAPH,
    TOGGLE_DEBUG_HITBOXES,
    SERIALISE,
    CHANGE_DEBUG_OBJECT,
};

enum class InputState {
    ALL,
    DEBUG,
};

const std::map<InputState, std::map<std::set<SDL_Scancode>, std::map<SDL_Scancode, InputKey>>>
keyboard_input_config = {
    {InputState::ALL, {
        {{}, {
            {SDL_SCANCODE_Q, InputKey::QUIT},
            {SDL_SCANCODE_ESCAPE, InputKey::QUIT},
        }},
        {{SDL_SCANCODE_LSHIFT}, {
            {SDL_SCANCODE_D, InputKey::TOGGLE_DEBUG},
            {SDL_SCANCODE_S, InputKey::TOGGLE_DEBUG_STATS},
            {SDL_SCANCODE_G, InputKey::TOGGLE_DEBUG_GRAPH},
        }},
        {{SDL_SCANCODE_RSHIFT}, {
            {SDL_SCANCODE_D, InputKey::TOGGLE_DEBUG},
            {SDL_SCANCODE_S, InputKey::TOGGLE_DEBUG_STATS},
            {SDL_SCANCODE_G, InputKey::TOGGLE_DEBUG_GRAPH},
        }},
    }},
    {InputState::DEBUG, {
        {{}, {
            {SDL_SCANCODE_K, InputKey::UP},
            {SDL_SCANCODE_J, InputKey::DOWN},
            {SDL_SCANCODE_H, InputKey::LEFT},
            {SDL_SCANCODE_L, InputKey::RIGHT},
        }},
        {{SDL_SCANCODE_LSHIFT}, {
            {SDL_SCANCODE_P, InputKey::TOGGLE_DEBUG_PIVOT},
            {SDL_SCANCODE_H, InputKey::TOGGLE_DEBUG_HITBOXES},
            {SDL_SCANCODE_Z, InputKey::SERIALISE},
        }},
        {{SDL_SCANCODE_RSHIFT}, {
            {SDL_SCANCODE_P, InputKey::TOGGLE_DEBUG_PIVOT},
            {SDL_SCANCODE_H, InputKey::TOGGLE_DEBUG_HITBOXES},
            {SDL_SCANCODE_Z, InputKey::SERIALISE},
        }},
    }},
};

const std::map<SDL_WindowEventID, InputKey> window_event_config;

const std::map<InputState, std::map<std::set<SDL_Scancode>, std::map<Uint8, InputKey>>>
mouse_input_config {
    {InputState::ALL, {
        {{}, {
            {SDL_BUTTON_LEFT, InputKey::CLICK},
            {SDL_BUTTON_RIGHT, InputKey::MOVE_CHARACTER},
        }},
    }},
    {InputState::DEBUG, {
        {{}, {
            {SDL_BUTTON_LEFT, InputKey::CHANGE_DEBUG_OBJECT}
        }},
    }},
};
