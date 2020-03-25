#include <models/screen.h>

Screen::Screen(std::string path) : _background_path(path) {}

std::string Screen::background_path() const {
    return this->_background_path;
}
#if 0
#include <includes.h>

using namespace std;
/* constructor */
Screen::Screen(vector<shared_ptr<ScreenObject>> objects, string backgroundPath, float sizeFactor) : m_objects(objects), m_backgroundPath(backgroundPath), m_sizeFactor(sizeFactor){
}

/* getter */
vector<shared_ptr<ScreenObject>> Screen::objects() const {
    return this->m_objects;
}

string Screen::backgroundPath() const {
    return this->m_backgroundPath;
}

Hitbox Screen::hitbox() const {
    return this->m_hitbox;
}
float Screen::sizeFactor() const {
    return this->m_sizeFactor;
}

/* setter */
shared_ptr<ScreenObject> Screen::addScreenObject(shared_ptr<ScreenObject> screenObject) {
    this->m_objects.push_back(screenObject);
    return this->m_objects.back();
}

shared_ptr<Character> Screen::addPlayer(shared_ptr<Character> c) {
    shared_ptr<ScreenObject> s = this->addScreenObject(c);
    return static_pointer_cast<Character>(s);
}

void Screen::setHitbox(Hitbox h) {
    this->m_hitbox = h;
}

void Screen::setSizeFactor(float s) {
    this->m_sizeFactor = s;
}

/* operators */
bool Screen::operator==(const Screen &s) const {
    return this->m_objects == s.m_objects;
}

/* misc */

void Screen::sortScreenObjects() {
    sort(this->m_objects.begin(), this->m_objects.end(), ScreenObject::greaterThan);
}

bool Screen::collides(Edge e) const {
    for (auto edge: this->m_hitbox.edges())
        if (edge.intersects(e))
                return true;

    return false;
}

bool Screen::collides(Point p) const {
    Point offPoint = this->m_hitbox.offPoint();
    int count = 0;
    for (auto e: this->m_hitbox.edges())
        if (e.intersects(Edge(p, offPoint)))
            count++;

    if (count % 2)
        return true;

    return false;
}

#endif
