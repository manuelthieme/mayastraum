#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Screen.h"
#include "Character.h"

class Game {
    vector<Screen> m_screens;
    Screen* m_activeScreen;
    Character* m_player;

public:
    /* constructor */
    Game(vector<Screen> screens, Character* player);

    /* getter */

    /* setter */
    void addScreen(Screen screen);
    bool setActiveScreen(Screen screen);
    void setPlayer(Character* player);

    /* misc */
    void render();
};

#endif /* GAME_H */
