#pragma once

#include <string>

#include <SDL_GUI/gui/positionable.h>

#include <models/hitbox.h>
#include <util/point.h>

class ScreenObject {
protected:
    std::string _path;
    Point _position;
    Point _pivot;
    unsigned _width;
    unsigned _height;

    Hitbox *_hitbox = nullptr;

    void init();
public:
    std::string _name;
    ScreenObject(std::string path);

    ScreenObject(std::string path, Point position, unsigned width, unsigned height);

    ~ScreenObject();

    std::string path() const;

    virtual void tick() {}

    /* getter */
    Point position() const;
    Point pivot() const;
    unsigned width() const;
    unsigned height() const;
    const Hitbox *hitbox() const;

    /* setter */
    void set_position(Point position);
    void set_pivot(Point pivot);
    void set_width(unsigned width);
    void set_height(unsigned height);
    void set_size(unsigned width, unsigned height);
    void set_hitbox(Hitbox *hitbox);

    void move(Point movement);

    bool collides(Point point) const;
    bool collides(Edge edge) const;
    Point closest_point(Point point) const;

    std::string serialise() const;
};

#if 0
#include <iostream>
#include <memory>
#include <vector>


#if 0
#include "Animation.h"
#include "Screen.h"
#endif

using namespace std;
class Screen;
class ScreenObject {
    Point m_size;

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
    Hitbox renderHitbox(shared_ptr<Screen> s, float gameHeight) const;
    shared_ptr<Animation> activeAnimation() const;

    /* setter */
    shared_ptr<Animation> addAnimation(shared_ptr<Animation> a);
    bool setActiveAnimation(shared_ptr<Animation> a);

    /* operators */
    bool operator==(const ScreenObject &s) const;
    static bool greaterThan(shared_ptr<ScreenObject> a, shared_ptr<ScreenObject> b);


    /* misc */
};

#endif
