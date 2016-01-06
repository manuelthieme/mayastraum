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
    /**
     * List of Screens in Game.
     */
    vector<shared_ptr<Screen>> m_screens;
    /**
     * Shortcut to Current Screen.
     */
    shared_ptr<Screen> m_activeScreen;
    /**
     * Windows width.
     */
    float m_width;
    /**
     * Window height.
     */
    float m_height;
    /**
     *  Player Character
     */
    shared_ptr<Character> m_player;

    /**
     * "Timestamp"
     */
    int tick;

    /**
     * SDL Event.
     */
	SDL_Event* m_mainEvent;
    /**
     * SDL Window.
     */
	SDL_Window* m_window;
    /**
     * SDL Renderer.
     */
	SDL_Renderer* m_renderer;
    /**
     * SDL Font.
     */
    TTF_Font* m_font;
    /**
     * list of loaded Textures.
     */
	map<string, SDL_Texture*> m_textures;
    /**
     * List of Input States.
     * Saves Bools for settings. This is usefull for debugging etc.
     */
    map<string, bool> m_inputStates;

    /**
     * Object to debug.
     */
    shared_ptr<ScreenObject> m_debug;
    /**
     * Graph with possible paths.
     */
    Graph m_pathGraph;

    /**
     * Initialise SDL stuff.
     */
    void init();
    /**
     * Render everything
     */
    void render();
    /**
     * Prepare Debugging stuff for Rendering.
     * Bounding boxes, Pivot Points, Hitboxes, Graphs ...
     */
    void drawDebug();
    /**
     * Clear Graphic Output.
     */
    void clear();
    /**
     * Prepare a single ScreenObject for Rendering.
     * \param screenObject The Object to render.
     */
    void drawScreenObject(shared_ptr<ScreenObject> screenObject);
    /**
     * Prepare Background of active Screen for Rendering.
     */
	void drawBackground();
    /**
     * Render all that was prepared.
     */
    void present();
    /**
     * Get Texture from Path.
     * \param texturePath Path of Texture.
     * \return Pointer to SDL_Texture Object.
     */
	SDL_Texture* getTextureFromPath(string texturePath);

public:
    /* constructor */
    /**
     * Constructor.
     * \param screens List of Screens.
     * \param width Game width.
     * \param height Game height.
     * \param player Player.
     */
    Game(vector<shared_ptr<Screen>> screens, float width, float height, Character* player);

    /**
     * Destructor.
     */
    ~Game();

    /* getter */
    /**
     * Calculate specific Path Graph.
     * \param position Starting Point.
     * \paran target Target Point.
     * \return Graph Containing all possible Paths from position to target.
     */
    Graph pathGraph(Point position, Point target);

    /* setter */
    /**
     * Add a Screen.
     * \param screen Screen to Add.
     * \return Pointer to added Screen.
     */
    shared_ptr<Screen> addScreen(shared_ptr<Screen> screen);
    /**
     * Set Active Screen Shortcut if in Screen List.
     * \param screen Screen to set as active.
     * \return True, if screen is in Screen List. Otherwise False.
     */
    bool setActiveScreen(shared_ptr<Screen> screen);
    /**
     * Set Player.
     * \param player Player.
     */
    void setPlayer(shared_ptr<Character> player);
    /**
     * Set Debug Object.
     * \param d Debug Object.
     */
    void setDebug(shared_ptr<ScreenObject> d);

    /* misc */
    /**
     * Run One Game Iteration.
     * \return False if Game quits. Otherwise True.
     */
    bool run();
    /**
     * Calculate shortest Path from a characters standpoint to a target.
     * \param character Character with the Position to start with.
     * \param target Target Point.
     * \return Shortest Path from Character Position to target.
     */
    list<Point> shortestPath(shared_ptr<Character> character, Point target);
};

#endif /* GAME_H */
