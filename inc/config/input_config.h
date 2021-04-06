#pragma once

#include <map>
#include <set>

#include <SDL2/SDL.h>

enum class InputKey {
    QUIT,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    CLICK,
    MOVE_CHARACTER,
    TOGGLE_DEBUG,
    TOGGLE_SHOW_PIVOT,
    TOGGLE_SHOW_STATS,
    TOGGLE_SHOW_GRAPH,
    CYCLE_SHOW_HITBOX,
    SERIALISE,
    CHANGE_DEBUG_OBJECT,
    CYCLE_EDIT_HITBOX,
    ADD_HITBOX_POINT,
    REMOVE_HITBOX_POINT,
};

enum class InputState {
    ALL,
    NON_DEBUG,
    DEBUG,
    EDIT_HITBOX,
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
            {SDL_SCANCODE_S, InputKey::TOGGLE_SHOW_STATS},
            {SDL_SCANCODE_G, InputKey::TOGGLE_SHOW_GRAPH},
        }},
        {{SDL_SCANCODE_RSHIFT}, {
            {SDL_SCANCODE_D, InputKey::TOGGLE_DEBUG},
            {SDL_SCANCODE_S, InputKey::TOGGLE_SHOW_STATS},
            {SDL_SCANCODE_G, InputKey::TOGGLE_SHOW_GRAPH},
        }},
    }},
    {InputState::DEBUG, {
        {{}, {
            {SDL_SCANCODE_K, InputKey::MOVE_UP},
            {SDL_SCANCODE_J, InputKey::MOVE_DOWN},
            {SDL_SCANCODE_H, InputKey::MOVE_LEFT},
            {SDL_SCANCODE_L, InputKey::MOVE_RIGHT},
        }},
        {{SDL_SCANCODE_LSHIFT}, {
            {SDL_SCANCODE_P, InputKey::TOGGLE_SHOW_PIVOT},
            {SDL_SCANCODE_H, InputKey::CYCLE_SHOW_HITBOX},
            {SDL_SCANCODE_Z, InputKey::SERIALISE},
        }},
        {{SDL_SCANCODE_RSHIFT}, {
            {SDL_SCANCODE_P, InputKey::TOGGLE_SHOW_PIVOT},
            {SDL_SCANCODE_H, InputKey::CYCLE_SHOW_HITBOX},
            {SDL_SCANCODE_Z, InputKey::SERIALISE},
        }},
        {{SDL_SCANCODE_LCTRL}, {
            {SDL_SCANCODE_H, InputKey::CYCLE_EDIT_HITBOX},
        }},
        {{SDL_SCANCODE_RCTRL}, {
            {SDL_SCANCODE_H, InputKey::CYCLE_EDIT_HITBOX},
        }},
    }},
    {InputState::EDIT_HITBOX, {
        {{SDL_SCANCODE_LCTRL}, {
            {SDL_SCANCODE_H, InputKey::CYCLE_EDIT_HITBOX},
        }},
        {{SDL_SCANCODE_RCTRL}, {
            {SDL_SCANCODE_H, InputKey::CYCLE_EDIT_HITBOX},
        }},
    }},
};

const std::map<SDL_WindowEventID, InputKey> window_event_config;

const std::map<InputState, std::map<std::set<SDL_Scancode>, std::map<Uint8, InputKey>>>
mouse_input_config {
    {InputState::ALL, {
        {{}, {
            {SDL_BUTTON_LEFT, InputKey::CLICK},
        }},
    }},
    {InputState::NON_DEBUG, {
        {{}, {
            {SDL_BUTTON_LEFT, InputKey::CHANGE_DEBUG_OBJECT},
            {SDL_BUTTON_RIGHT, InputKey::MOVE_CHARACTER},
        }},
    }},
    {InputState::DEBUG, {
        {{}, {
            {SDL_BUTTON_LEFT, InputKey::CHANGE_DEBUG_OBJECT},
            {SDL_BUTTON_RIGHT, InputKey::MOVE_CHARACTER},
        }},
    }},
    {InputState::EDIT_HITBOX, {
        {{}, {
            {SDL_BUTTON_LEFT, InputKey::ADD_HITBOX_POINT},
            {SDL_BUTTON_RIGHT, InputKey::REMOVE_HITBOX_POINT},
        }},
    }},
};
