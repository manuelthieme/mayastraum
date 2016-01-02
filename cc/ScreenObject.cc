#include "../h/ScreenObject.h"

/* constructor */
ScreenObject::ScreenObject(Point position, Point size, Point pivot, Hitbox hitbox, vector<shared_ptr<Animation>> animations) : m_size(size), m_pivot(pivot), m_hitbox(hitbox), m_position(position), m_animations(animations) {
    if (this->m_animations.size() > 0)
        this->m_activeAnimation = this->m_animations[0];
}

/* getter */
Point ScreenObject::position() const {
    return this->m_position;
}

Point ScreenObject::size() const {
    return this->m_size;
}

#if 0
Point ScreenObject::renderSize() const {

}
#endif

Point ScreenObject::pivot() const {
    return this->m_pivot;
}

Hitbox ScreenObject::hitbox() const {
    return this->m_hitbox;
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

/* misc */
void ScreenObject::tick(int t) {
    //cout << typeid(this).name() << endl;
    this->m_activeAnimation->tick(t);
}
