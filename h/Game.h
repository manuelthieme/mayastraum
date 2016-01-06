#ifndef GAME_H
#define GAME_H

#include <vector>
#include <map>
#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Game {
    vector<shared_ptr<Screen>> m_screens;
    shared_ptr<Screen> m_activeScreen;
    float m_width;
    float m_height;
    shared_ptr<Character> m_player;

	SDL_Event* m_mainEvent;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
    TTF_Font* m_font;
	map<string, SDL_Texture*> m_textures;
    map<string, bool> m_inputStates;

    void init();
    void render();
    void drawDebug();
    void clear();
    void drawScreenObject(shared_ptr<ScreenObject> screenObject);
	void drawBackground();
    void present();
	SDL_Texture* getTextureFromPath(string texturePath);

    int tick;

    shared_ptr<ScreenObject> m_debug;
    Graph m_pathGraph;

public:
    /* constructor */
    Game(vector<shared_ptr<Screen>> screens, float width, float height, Character* player);
    ~Game();

    /* getter */
    Graph pathGraph(Point position, Point target);

    /* setter */
    shared_ptr<Screen> addScreen(shared_ptr<Screen> screen);
    bool setActiveScreen(shared_ptr<Screen> screen);
    void setPlayer(shared_ptr<Character> player);
    void setDebug(shared_ptr<ScreenObject> d);

    /* misc */
    bool run();
    list<Point> shortestPath(shared_ptr<Character> character, Point target);
};

#endif /* GAME_H */
