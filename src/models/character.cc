#include <models/character.h>

Character::Character(std::string path, SDL_GUI::Position position, unsigned width, unsigned height, int speed) : ScreenObject(path, position, width, height), _target(position), _speed(speed) {
    this->_running = false;
    this->_path.push_back(position);
}

int Character::speed() const {
    return this->_speed;
}

Point Character::target() const {
    return this->_target;
}

bool Character::running() const {
    return this->_running;
}

list<Point> Character::path() const {
    return this->_path;
}


void Character::setTarget(list<Point> path) {
    this->_path = path;
    this->_target = this->_path.back();
}

void Character::setSpeed(int s) {
    this->_speed = s;
}

void Character::setRunning(bool running) {
    this->_running = running;
}


void Character::startRunning() {
    this->_running = true;
    //this->_activeAnimation = this->_runningAnimation;
}

void Character::stopRunning() {
    this->_running = false;
    //this->_runningAnimation->setActiveImage(0);
    //this->_activeAnimation = this->_animations[0];
}

void Character::tick(int t) {
    if (not this->_running) {
        return;
    }

    Point position = this->_position;
    if (this->_target == position or this->_path.empty()) {
        this->stopRunning();
        return;
    }

    Point n = this->_path.front();
    Point distance = position - n;
    Point fak((distance.x() >= 0) ? 1 : -1, (distance.y() >= 0) ? 1 : -1);
    if (this->_position == n) {
        this->_path.pop_front();
        this->tick(t);
        return;
    }
    //float factor = ((float)position.y() / gameHeight) * (1 - activeScreen->sizeFactor()) + activeScreen->sizeFactor();
    position.moveTo(n, this->_speed);
    this->_position._x = position.x();
    this->_position._y = position.y();

    //ScreenObject::tick(t, activeScreen, gameHeight);
}

#if 0

using namespace std;


shared_ptr<Animation> Character::runningAnimation() const {
    return this->_runningAnimation;
}


/* setter */
shared_ptr<Animation> Character::addRunningAnimation(shared_ptr<Animation> a) {
    this->_runningAnimation = this->addAnimation(a);
    return this->_runningAnimation;
}


/* misc */
#endif
