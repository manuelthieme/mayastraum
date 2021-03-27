#include <models/screen_object.h>
ScreenObject::ScreenObject(std::string path): _path(path) {
    this->init();
}

ScreenObject::ScreenObject(std::string path, Point position, unsigned width, unsigned height):
    _path(path),
    _position(position),
    _width(width),
    _height(height) {
    this->init();
}

void ScreenObject::init() {

}

std::string ScreenObject::path() const {
    return this->_path;
}

Point ScreenObject::position() const {
    return this->_position;
}

Point ScreenObject::pivot() const {
    return this->_pivot;
}

unsigned ScreenObject::width() const {
    return this->_width;
}

unsigned ScreenObject::height() const {
    return this->_height;
}

void ScreenObject::set_position(Point position) {
    this->_position = position;
}

void ScreenObject::set_pivot(Point pivot) {
    this->_pivot = pivot;
}

void ScreenObject::set_width(unsigned width) {
    this->_width = width;
}

void ScreenObject::set_height(unsigned height) {
    this->_height = height;
}

void ScreenObject::set_size(unsigned width, unsigned height) {
    this->set_width(width);
    this->set_height(height);
}

void ScreenObject::move(Point movement) {
    this->_position += movement;
}

#if 0
#include <includes.h>

/* constructor */
ScreenObject::ScreenObject(Point position, Point size, Point pivot, Hitbox hitbox, vector<shared_ptr<Animation>> animations) : m_size(size), m_pivot(pivot), m_hitbox(hitbox), m_position(position), m_animations(animations) {
    if (this->m_animations.size() > 0)
        this->m_activeAnimation = this->m_animations[0];
}

/* getter */

Point ScreenObject::size() const {
    return this->m_size;
}

Point ScreenObject::renderSize(shared_ptr<Screen> s, float gameHeight) const {
    float factor = (this->m_position.y() / gameHeight) * (1 - s->sizeFactor()) + s->sizeFactor();
    return Point(this->m_size.width() * factor, this->m_size.height() * factor);
}


Hitbox ScreenObject::hitbox() const {
    return this->m_hitbox;
}

Hitbox ScreenObject::renderHitbox(shared_ptr<Screen> s, float gameHeight) const {
    Hitbox h;
    float factor = (this->m_position.y() / gameHeight) * (1 - s->sizeFactor()) + s->sizeFactor();
    for (auto p: this->m_hitbox.points()) {
        Point tmp(p.width() * factor, p.height() * factor);
        h.addPoint(tmp);
    }
    h.calculateEdges();
    return h;
}
shared_ptr<Animation> ScreenObject::activeAnimation() const {
    return this->m_activeAnimation;
}


/* setter */
void ScreenObject::setPosition(Point p) {
    this->m_position = p;
}

void ScreenObject::setSize(Point p) {
    this->m_size = p;
}

void ScreenObject::setPivot(Point p) {
    this->m_pivot = p;
}

void ScreenObject::setHitbox(Hitbox h) {
    this->m_hitbox = h;
}

shared_ptr<Animation> ScreenObject::addAnimation(shared_ptr<Animation> a) {
    this->m_animations.push_back(a);
    return this->m_animations.back();
}

bool ScreenObject::setActiveAnimation(shared_ptr<Animation> a) {
    bool success = false;
    for (auto animation: this->m_animations)
        if (animation == a) {
            this->m_activeAnimation = animation;
            success = true;
            break;
        }

    return success;
}


/* operators */
bool ScreenObject::operator==(const ScreenObject &s) const {
    return this->m_position == s.m_position
        && this->m_hitbox == s.m_hitbox
        && this->m_animations == s.m_animations;
}

bool ScreenObject::greaterThan(shared_ptr<ScreenObject> a, shared_ptr<ScreenObject> b) {
    return (a->position().y() < b->position().y());
}

/* misc */
void ScreenObject::tick(int t, shared_ptr<Screen> activeScreen, int gameHeight) {
    this->m_activeAnimation->tick(t);
}

bool ScreenObject::collides(Point p, shared_ptr<Screen> activeScreen, int gameHeight) const {
    Point offPoint = this->m_hitbox.offPoint();
    int count = 0;
    for (auto e: this->renderHitbox(activeScreen, gameHeight).edges())
        if ((e + this->m_position).intersects(Edge(p, offPoint)))
            count++;

    if (count % 2)
        return true;

    return false;
}

bool ScreenObject::collides(Edge e, shared_ptr<Screen> activeScreen, int gameHeight) const {
    Hitbox renderHitbox = this->renderHitbox(activeScreen, gameHeight);

    /* check whether the Edge intersects one of the hitbox edges */
    for (auto edge: renderHitbox.edges()) {
        edge += this->m_position;
        if (edge.intersects(e))
            //if(this->collides(edge.middle(), activeScreen, gameHeight))
                return true;
    }
    return false;
}

Point ScreenObject::nearestPoint(Point p) const {
    return p;
}
#endif
