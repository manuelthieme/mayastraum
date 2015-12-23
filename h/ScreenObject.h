#ifndef SCREENOBJECT_H
#define SCREENOBJECT_H

#include <iostream>
#include <memory>
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

protected:
    shared_ptr<Animation> m_activeAnimation;
    vector<shared_ptr<Animation>> m_animations;

public:
    /* constructor */
    ScreenObject(Point position, Point size, Point pivot, Hitbox hitbox, vector<shared_ptr<Animation>> animations);

    /* getter */
    Point position() const;
    Point size() const;
    Point renderSize() const;
    Point pivot() const;
    Hitbox hitbox() const;
    shared_ptr<Animation> activeAnimation() const;

    /* setter */
    void setPosition(Point p);
    void setSize(Point p);
    void setPivot(Point p);
    void setHitbox(Hitbox h);
    shared_ptr<Animation> addAnimation(shared_ptr<Animation> a);
    bool setActiveAnimation(shared_ptr<Animation> a);

    /* operators */
    bool operator==(const ScreenObject &s) const;

    /* misc */
    void tick(int t);
};

#endif /* SCREENOBJECT_H */
