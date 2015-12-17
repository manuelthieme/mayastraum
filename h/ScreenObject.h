#ifndef SCREENOBJECT_H
#define SCREENOBJECT_H

#include <vector>

#include "Animation.h"
#include "Point.h"
#include "Hitbox.h"

using namespace std;
class ScreenObject {
    Point m_position;
    Hitbox m_hitbox;
    vector<Animation> m_animations;
    Animation* m_activeAnimation;

public:
    /* constructor */
    ScreenObject(Point position, Hitbox hitbox, vector<Animation> animations);

    /* getter */
    Point position() const;
    Hitbox hitbox() const;
    Animation* activeAnimation() const;

    /* setter */
    void setPosition(Point p);
    void setHitbox(Hitbox h);
    void addAnimation(Animation a);
    bool setActiveAnimation(Animation a);

    /* operators */
    bool operator==(const ScreenObject &s) const;

};

#endif /* SCREENOBJECT_H */
