#ifndef CHARACTER_H
#define CHARACTER_H

#include "ScreenObject.h"

class Character : public ScreenObject {
    bool m_running;

public:
    /* constructor */
    Character(Point position, Point size, Point pivot, Hitbox hitbox, vector<Animation> animations);

    /* getter */
    bool running() const;

    /* setter */
    void setRunning(bool running);
};

#endif /* CHARACTER_H */
