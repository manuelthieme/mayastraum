#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Screen.h"
#include "Character.h"

class Game {
    vector<Screen> m_screens;
    Screen* m_activeScreen;
    float m_width;
    float m_height;
    Character* m_player;

	SDL_Event* mainEvent;
	SDL_Window* window;
	SDL_Renderer* renderer;

    void init();
    void render();
public:
    /* constructor */
    Game(vector<Screen> screens, float width, float height, Character* player);

    /* getter */

    /* setter */
    void addScreen(Screen screen);
    bool setActiveScreen(Screen screen);
    void setPlayer(Character* player);

    /* misc */
    bool run();
};

#endif /* GAME_H */
