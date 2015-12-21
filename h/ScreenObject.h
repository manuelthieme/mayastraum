#ifndef SCREENOBJECT_H
#define SCREENOBJECT_H

#include <vector>

#include "Animation.h"
#include "Point.h"
#include "Hitbox.h"

using namespace std;
class ScreenObject {
    Point m_position;
    Point m_size;
    Point m_pivot;
    Hitbox m_hitbox;
    vector<Animation> m_animations;
    Animation* m_activeAnimation;

public:
    /* constructor */
    ScreenObject(Point position, Point size, Point pivot, Hitbox hitbox, vector<Animation> animations);

    /* getter */
    Point position() const;
    Point size() const;
    Point renderSize() const;
    Point pivot() const;
    Hitbox hitbox() const;
    Animation activeAnimation() const;

    /* setter */
    void setPosition(Point p);
    void setSize(Point p);
    void setPivot(Point p);
    void setHitbox(Hitbox h);
    void addAnimation(Animation a);
    bool setActiveAnimation(Animation a);

    /* operators */
    bool operator==(const ScreenObject &s) const;

};

#endif /* SCREENOBJECT_H */
