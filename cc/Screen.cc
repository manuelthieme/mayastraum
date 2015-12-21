#include "../h/Screen.h"

/* constructor */
Screen::Screen(vector<ScreenObject> objects, string backgroundPath) : m_objects(objects), m_backgroundPath(backgroundPath) {
}

/* getter */
vector<ScreenObject> Screen::objects() const {
    return this->m_objects;
}

string Screen::backgroundPath() const {
    return this->m_backgroundPath;
}

Hitbox Screen::hitbox() const {
    return this->m_hitbox;
}

/* setter */
void Screen::addScreenObject(ScreenObject screenObject) {
    this->m_objects.push_back(screenObject);
}

void Screen::setHitbox(Hitbox h) {
    this->m_hitbox = h;
}

/* operators */
bool Screen::operator==(const Screen &s) const {
    return this->m_objects == s.m_objects;
}
