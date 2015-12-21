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

/* setter */
void Screen::addScreenObject(ScreenObject screenObject) {
    this->m_objects.push_back(screenObject);
}

/* operators */
bool Screen::operator==(const Screen &s) const {
    return this->m_objects == s.m_objects;
}
