#include "../h/includes.h"

using namespace std;
/* constructor */
Character::Character(Point position, Point size, Point pivot, Hitbox hitbox, vector<shared_ptr<Animation>> animations, int speed) : ScreenObject(position, size, pivot, hitbox, animations), m_target(position), m_speed(speed) {
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

int Character::speed() const {
    return this->m_speed;
}

Point Character::target() const {
    return this->m_target;
}
list<Point> Character::path() const {
    return this->m_path;
}


/* setter */
void Character::setRunning(bool running) {
    this->m_running = running;
}

shared_ptr<Animation> Character::addRunningAnimation(shared_ptr<Animation> a) {
    this->m_runningAnimation = this->addAnimation(a);
    return this->m_runningAnimation;
}

void Character::setTarget(list<Point> path) {
    this->m_path = path;
    this->m_target = this->m_path.back();
}

void Character::setSpeed(int s) {
    this->m_speed = s;
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

void Character::tick(int t, shared_ptr<Screen> activeScreen, int gameHeight) {
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
        this->tick(t, activeScreen, gameHeight);
        return;
    }
    float factor = ((float)this->m_position.y() / gameHeight) * (1 - activeScreen->sizeFactor()) + activeScreen->sizeFactor();
    this->m_position.moveTo(n, this->m_speed * factor);

    ScreenObject::tick(t, activeScreen, gameHeight);
}
