#include "../h/Game.h"

/* constructor */
Game::Game(vector<Screen> screens, Character* player) : m_screens(screens), m_player(player) {
    if (this->m_screens.size() > 0)
        this->m_activeScreen = &(this->m_screens[0]);
}

/* getter */


/* setter */
void Game::addScreen(Screen screen) {
    this->m_screens.push_back(screen);
}

bool Game::setActiveScreen(Screen screen) {
    bool success = false;
    for (auto s: this->m_screens)
        if (s == screen) {
            this->m_activeScreen = &s;
            success = true;
            break;
        }

    return success;
}

void Game::setPlayer(Character* player) {
    this->m_player = player;
}

/* misc */
void Game::render() {
    /* TODO Render!!1!!! */
}
