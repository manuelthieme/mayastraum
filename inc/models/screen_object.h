#pragma once

#include <string>

#include <yaml-cpp/yaml.h>

#include <SDL_GUI/gui/positionable.h>

#include <models/hitbox.h>
#include <util/geometry/point.h>

class ScreenObject {
protected:
    std::string _path = "";
    Point _position = {0,0};
    Point _pivot = {0,0};
    unsigned _width = 0;
    unsigned _height = 0;

    Hitbox *_hitbox = nullptr;
    PolygonHitbox *_polygon_hitbox = nullptr;
    Hitbox *_hover_box = nullptr;
    PolygonHitbox *_polygon_hover_box = nullptr;

    void init();

    void deserialise_box(YAML::Node hitbox_yaml, bool hover_box = false);
public:
    std::string _name = "";
    ScreenObject(std::string path);

    ScreenObject(std::string path, Point position, unsigned width, unsigned height);

    ScreenObject(YAML::Node object_yaml);

    ~ScreenObject();

    virtual void tick() {}

    /* getter */
    std::string path() const;
    Point position() const;
    Point pivot() const;
    unsigned width() const;
    unsigned height() const;

    Hitbox *hitbox();
    const Hitbox *hitbox() const;
    Hitbox *hover_box();
    const Hitbox *hover_box() const;

    PolygonHitbox *polygon_hitbox();
    const PolygonHitbox *polygon_hitbox() const;
    PolygonHitbox *polygon_hover_box();
    const PolygonHitbox *polygon_hover_box() const;

    /* setter */
    void set_position(Point position);
    void set_pivot(Point pivot);
    void set_width(unsigned width);
    void set_height(unsigned height);
    void set_size(unsigned width, unsigned height);

    void set_hitbox(Hitbox *hitbox);
    void set_hitbox(PolygonHitbox *hitbox);
    void set_hover_box(Hitbox *hover_box);
    void set_hover_box(PolygonHitbox *hover_box);

    void move(Point movement);

    bool collides(Point point) const;
    bool collides(Edge edge) const;
    Point closest_point(Point point) const;

    std::string serialise() const;
};

YAML::Emitter& operator<<(YAML::Emitter &out, const ScreenObject &screen_object);

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
