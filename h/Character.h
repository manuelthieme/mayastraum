#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>

#include "ScreenObject.h"

class Character : public ScreenObject {
    bool m_running;
    shared_ptr<Animation> m_runningAnimation;

public:
    /* constructor */
    Character(Point position, Point size, Point pivot, Hitbox hitbox, vector<shared_ptr<Animation>> animations);

    /* getter */
    bool running() const;
    shared_ptr<Animation> runningAnimation() const;

    /* setter */
    void setRunning(bool running);
    shared_ptr<Animation> addRunningAnimation(shared_ptr<Animation> a);
};

#endif /* CHARACTER_H */
