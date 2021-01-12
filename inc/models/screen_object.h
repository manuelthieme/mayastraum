#pragma once

#include <string>

#include <SDL_GUI/inc/gui/positionable.h>

#include <util/point.h>

class ScreenObject {
protected:
    std::string _path;
    Point _position;
    Point _pivot;
    unsigned _width;
    unsigned _height;

    void init();
public:
    ScreenObject(std::string path);

    ScreenObject(std::string path, Point position, unsigned width, unsigned height);

    std::string path() const;

    virtual void tick() {}

    /* getter */
    Point position() const;
    Point pivot() const;
    unsigned width() const;
    unsigned height() const;

    /* setter */
    void set_position(Point position);
    void set_pivot(Point pivot);
    void set_width(unsigned width);
    void set_height(unsigned height);
    void set_size(unsigned width, unsigned height);
};

#if 0
#include <iostream>
#include <memory>
#include <vector>


#if 0
#include "Animation.h"
#include "Hitbox.h"
#include "Screen.h"
#endif

using namespace std;
class Screen;
class ScreenObject {
    Point m_size;
    Hitbox m_hitbox;

protected:
    Point m_position;
    shared_ptr<Animation> m_activeAnimation;
    vector<shared_ptr<Animation>> m_animations;

public:
    /* constructor */
    ScreenObject(Point position, Point size, Point pivot, Hitbox hitbox, vector<shared_ptr<Animation>> animations);

    /* getter */
    Point size() const;
    Point renderSize(shared_ptr<Screen> s, float gameHeight) const;
    Hitbox hitbox() const;
    Hitbox renderHitbox(shared_ptr<Screen> s, float gameHeight) const;
    shared_ptr<Animation> activeAnimation() const;

    /* setter */
    void setHitbox(Hitbox h);
    shared_ptr<Animation> addAnimation(shared_ptr<Animation> a);
    bool setActiveAnimation(shared_ptr<Animation> a);

    /* operators */
    bool operator==(const ScreenObject &s) const;
    static bool greaterThan(shared_ptr<ScreenObject> a, shared_ptr<ScreenObject> b);


    /* misc */
    bool collides(Point p, shared_ptr<Screen> activeScreen, int gameHeight) const;
    bool collides(Edge e, shared_ptr<Screen> activeScreen, int gameHeight) const;
    Point nearestPoint(Point p) const;
};

#endif
