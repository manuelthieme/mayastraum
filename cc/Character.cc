#include "../h/Character.h"

using namespace std;
/* constructor */
Character::Character(Point position, Point size, Point pivot, Hitbox hitbox, vector<shared_ptr<Animation>> animations) : ScreenObject(position, size, pivot, hitbox, animations), m_target(position) {
    this->m_running = false;
    this->m_path.push_back(position);
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

void Character::setTarget(Point t) {
    this->m_target = t;
    this->m_path.push_back(t);
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

void Character::tick(int t) {
    if (not this->m_running)
        return;

    if (this->m_target == this->m_position or this->m_path.empty()) {
        this->stopRunning();
        return;
    }

    Point n = this->m_path.front();
    Point distance = this->m_position - n;
    Point fak((distance.x() >= 0) ? 1 : -1, (distance.y() >= 0) ? 1 : -1);
    if (this->m_position == n) {
        this->m_path.pop_front();
        this->tick(t);
        return;
    }
    float factor = 1;//((float)this->m_position.y() / this->screen->height()) * (1 - this->screen->sizeFactor()) + this->screen->sizeFactor();
    this->m_position.moveTo(n, /*this->speed * */ factor);

    ScreenObject::tick(t);
}
