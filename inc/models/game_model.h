#pragma once

#include <vector>
#include <map>

#include <SDL_GUI/gui/drawable.h>
#include <SDL_GUI/gui/primitives/rect.h>
#include <SDL_GUI/gui/primitives/text.h>
#include <SDL_GUI/models/model_base.h>

#include <gui/gui_screen.h>
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
    Character *_character;

    SDL_GUI::Drawable *_main;   /**< drawable root for the game */
    GuiScreen *_screen_texture; /**< screen drawable */
    SDL_GUI::Rect *_debug_rect; /**< drawable wrapper for general debug information */
    SDL_GUI::Rect *_stats_rect; /**< drawable wrapper for fps and tps */
    SDL_GUI::Text *_fps_text;   /**< text that displays fps stat */
    SDL_GUI::Text *_tps_text;   /**< text that displays tps stat */
    SDL_GUI::Rect *_graph_rect; /**< drawable wrapper for graph visualisation */

    SDL_GUI::Drawable *_debug_active = nullptr;     /**< drawable that gets debugged */
    ScreenObject *_debug_active_object = nullptr;   /**< screenobject that gets debugged */
    SDL_GUI::Drawable *_hovered = nullptr;          /**< drawable that is hovered */
    ScreenObject *_hovered_screen_object = nullptr; /**< screenobject that is hovered */
    std::vector<SDL_GUI::Drawable *> _all_hovered;  /**< drawables that are hovered */

    Point _drag_movement;   /**< dragging that has to be done on active debug */
    bool _dragging = false; /**< flag that determines whether the dragging is applied */

    /** flag that determines whether we are in hitbox edit mode */
    bool _editing_hitbox = false;
    Hitbox *_edited_hitbox = nullptr; /**< Hitbox that gets edited */

    /**
     * Mapping from texture to ScreenObject
     */
    std::map<SDL_GUI::Drawable *, ScreenObject *> _model_mapping;

    /** flag that determines whether basic debugging is activated */
    bool _debugging = false;

    /** flag that determines whether the pivot points of screen objects are shown */
    bool _debugging_pivot = false;

    /** flag that determines whether runtime stats are shown */
    bool _debugging_stats = false;

    /** flag that determines whether pathfinding is shown */
    bool _debugging_graph = false;

    /** flag that determines whether hitboxes are shown */
    bool _debugging_hitboxes = false;

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
