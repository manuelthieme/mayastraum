#include "../h/ScreenObject.h"

/* constructor */
ScreenObject::ScreenObject(Point position, Hitbox hitbox, vector<Animation> animations) : m_position(position), m_hitbox(hitbox), m_animations(animations) {
    if (this->m_animations.size() > 0)
        this->m_activeAnimation = &(this->m_animations[0]);
}

/* getter */
Point ScreenObject::position() const {
    return this->m_position;
}

Hitbox ScreenObject::hitbox() const {
    return this->m_hitbox;
}

Animation* ScreenObject::activeAnimation() const {
    return this->m_activeAnimation;
}


/* setter */
void ScreenObject::setPosition(Point p) {
    this->m_position = p;
}

void ScreenObject::setHitbox(Hitbox h) {
    this->m_hitbox = h;
}

void ScreenObject::addAnimation(Animation a) {
    this->m_animations.push_back(a);
}

bool ScreenObject::setActiveAnimation(Animation a) {
    bool success = false;
    for (auto animation: this->m_animations)
        if (animation == a) {
            this->m_activeAnimation = &animation;
            success = true;
            break;
        }

    return success;
}


/* operators */
bool ScreenObject::operator==(const ScreenObject &s) const {
    return this->m_position == s.m_position
        && this->m_hitbox == s.m_hitbox
        && this->m_animations = s.m_animations;
}
