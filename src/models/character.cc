#include <models/character.h>

Character::Character(std::string path, SDL_GUI::Position position, unsigned width, unsigned height,
                     int speed) :
    ScreenObject(path, position, width, height),
    _target(position),
    _speed(speed) {
    this->_path.push_back(position);
}

Character::Character(YAML::Node character_yaml)
    : ScreenObject(character_yaml),
      _target(this->_position) {
    this->_path.push_back(this->position());
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


void Character::set_target(list<Point> path) {
    this->_path = path;
    this->_target = this->_path.back();
}

void Character::set_speed(int s) {
    this->_speed = s;
}

void Character::set_running(bool running) {
    this->_running = running;
}


void Character::start_running() {
    this->_running = true;
    //this->_activeAnimation = this->_runningAnimation;
}

void Character::stop_running() {
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
        this->stop_running();
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
    position.move_to(n, this->_speed);
    this->_position.set_x(position.x());
    this->_position.set_y(position.y());

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
