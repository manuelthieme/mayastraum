#include "../h/Character.h"

/* constructor */

Character::Character(Point position, Point size, Point pivot, Hitbox hitbox, vector<shared_ptr<Animation>> animations) : ScreenObject(position, size, pivot, hitbox, animations) {
    this->m_running = false;
}

/* getter */
bool Character::running() const {
    return this->m_running;
}

shared_ptr<Animation> Character::runningAnimation() const {
    return this->m_runningAnimation;
}


/* setter */
void Character::setRunning(bool running) {
    this->m_running = running;
}

shared_ptr<Animation> Character::addRunningAnimation(shared_ptr<Animation> a) {
    this->m_runningAnimation = this->addAnimation(a);
    return this->m_runningAnimation;
}

/* misc */
void Character::startRunning() {
    this->m_running = true;
    this->m_activeAnimation = this->m_runningAnimation;
}

void Character::stopRunning() {
    this->m_running = false;
    this->m_runningAnimation->setActiveImage(0);
    this->m_activeAnimation = this->m_animations[0];
}
