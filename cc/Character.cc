#include "../h/Character.h"

/* constructor */

Character::Character(Point position, Hitbox hitbox, vector<Animation> animations) : ScreenObject(position, hitbox, animations) {
    this->m_running = false;
}

/* getter */
bool Character::running() const {
    return this->m_running;
}


/* setter */
void Character::setRunning(bool running) {
    this->m_running = running;
}
