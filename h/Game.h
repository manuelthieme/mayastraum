#ifndef GAME_H
#define GAME_H

#include <vector>
#include <map>
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

	SDL_Event* m_mainEvent;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	map<string, SDL_Texture*> m_textures;

    void init();
    void render();
    void clear();
    void drawScreenObject(ScreenObject screenObject);
	void drawBackground();
    void present();
	SDL_Texture* getTextureFromPath(string texturePath);

public:
    /* constructor */
    Game(vector<Screen> screens, float width, float height, Character* player);
    ~Game();

    /* getter */

    /* setter */
    void addScreen(Screen screen);
    bool setActiveScreen(Screen screen);
    void setPlayer(Character* player);

    /* misc */
    bool run();
};

#endif /* GAME_H */
