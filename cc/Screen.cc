#include "../h/Screen.h"

/* constructor */

Screen::Screen(vector<ScreenObject> objects) : m_objects(objects) {
}

/* getter */
vector<ScreenObject> Screen::objects() const {
    return this->m_objects;
}

/* setter */
void Screen::addScreenObject(ScreenObject screenObject) {
    this->m_objects.push_back(screenObject);
}

/* operators */
bool Screen::operator==(const Screen &s) const {
    return this->m_objects == s.m_objects;
}
