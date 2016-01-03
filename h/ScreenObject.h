#ifndef SCREENOBJECT_H
#define SCREENOBJECT_H

#include <iostream>
#include <memory>
#include <vector>


#if 0
#include "Animation.h"
#include "Point.h"
#include "Hitbox.h"
#include "Screen.h"
#endif

using namespace std;
class Screen;
class ScreenObject {
    Point m_size;
    Point m_pivot;
    Hitbox m_hitbox;

protected:
    Point m_position;
    shared_ptr<Animation> m_activeAnimation;
    vector<shared_ptr<Animation>> m_animations;

public:
    /* constructor */
    ScreenObject(Point position, Point size, Point pivot, Hitbox hitbox, vector<shared_ptr<Animation>> animations);

    /* getter */
    Point position() const;
    Point size() const;
    Point renderSize(shared_ptr<Screen> s, float gameHeight) const;
    Point pivot() const;
    Hitbox hitbox() const;
    Hitbox renderHitbox(shared_ptr<Screen> s, float gameHeight) const;
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
    static bool greaterThan(shared_ptr<ScreenObject> a, shared_ptr<ScreenObject> b);


    /* misc */
    virtual void tick(int t);
};

#endif /* SCREENOBJECT_H */
