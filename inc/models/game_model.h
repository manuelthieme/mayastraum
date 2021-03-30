#pragma once

#include <vector>
#include <map>

#include <SDL_GUI/inc/gui/drawable.h>
#include <SDL_GUI/inc/models/model_base.h>

#include <models/character.h>
#include <models/screen.h>

class GameModel : public SDL_GUI::ModelBase {
public:
    /**
     * List of Screens in Game.
     */
    std::vector<Screen *> _screens;

    /**
     * Shortcut to Current Screen.
     */
    Screen *_active_screen;

    /**
     *  Player Character
     */
    Character *_player;

    /**
     * Mapping from texture to ScreenObject
     */
    std::map<SDL_GUI::Drawable *, ScreenObject *> _model_mapping;

    /** flag that determines whether the pivot points of screen objects are shown */
    bool _debugging_pivot = false;

    /** flag that determines whether runtime stats are shown */
    bool _debugging_stats = false;

    void init();

    GameModel();
};

#if 0
#include <vector>
#include <map>
#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Game {
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
#endif
