#pragma once

#include <iostream>
#include <string>
#include <list>

#include <SDL_GUI/gui/drawable.h>

#include <yaml-cpp/yaml.h>

#include <util/geometry/aabb.h>
#include <util/geometry/circle.h>
#include <util/geometry/edge.h>
#include <util/geometry/polygon.h>
#include <util/serialisable.h>

enum class HitboxType {
    CIRCLE,
    AABB,
    POLYGON,
    NONE,
};

const std::map<std::string, HitboxType> HITBOX_TYPE_MAPPING = {
    {"CircleHitbox" , HitboxType::CIRCLE},
    {"AABBHitbox"   , HitboxType::AABB},
    {"PolygonHitbox", HitboxType::POLYGON},
};


/** Base class for the different options to describe a hitbox */
class Hitbox : public Serialisable {
public:
    HitboxType _type;

    Hitbox(HitboxType type)
        : _type(type) {}

    virtual ~Hitbox() = default;

    virtual std::list<Edge> edges() const = 0;

    /** check if point is inside Hitbox */
    virtual bool collides(Point point) const = 0;

    /** check if Edge collides with hitbox */
    virtual bool collides(Edge edge) const = 0;

    /** calculate point on hitbox edge that is the nearest to a given point */
    virtual Point closest_point(Point point) const = 0;

    /** get string representation of this hitbox */
    virtual std::string to_string() const = 0;

    /** generate a drawable for this hitbox */
    virtual SDL_GUI::Drawable *drawable() const = 0;
};

/** Hitbox given through a circle */
class CircleHitbox : public Hitbox {
    Circle _circle;     /**< circle describing this hitbox */
    Polygon _polygon;   /**< for approximation */
public:
    /**
     * Constructor
     * @param circle circle describing the hitbox
     */
    CircleHitbox(Circle circle)
        : Hitbox(HitboxType::CIRCLE), _circle(circle), _polygon(circle) {}

    /**
     * Constructor
     * @param center circles center point
     * @param radius circles radius
     */
    CircleHitbox(Point center = {0, 0}, float radius = 0)
        : Hitbox(HitboxType::CIRCLE), _circle(center, radius), _polygon(this->_circle) {}

    CircleHitbox(YAML::Node hitbox_yaml)
        : Hitbox(HitboxType::CIRCLE), _circle(hitbox_yaml), _polygon(this->_circle) {}


    virtual std::list<Edge> edges() const override;

    /** @copydoc Hitbox::collides(Point) const */
    bool collides(Point point) const override;

    /** @copydoc Hitbox:: collides(Edge) const */
    bool collides(Edge edge) const override;

    /** copydoc Hitbox::nearest_point(Point) const */
    Point closest_point(Point point) const override;

    /** @copydoc Hitbox::to_string() const */
    std::string to_string() const override;

    /** @copydoc Hitbox::drawable() const */
    SDL_GUI::Drawable *drawable() const override;

    void to_yaml(YAML::Emitter *output) const override;
};

/** Hitbox given through an Axis-Aligned Bounding Box */
class AABBHitbox : public Hitbox {
    AABB _aabb;

public:
    /**
     * Constructor
     * @param position bounding box' position
     * @param width bounding box' width
     * @param height bounding box' height
     */
    AABBHitbox(Point position = {0, 0}, float width = 0, float height = 0)
        : Hitbox(HitboxType::AABB), _aabb(position, width, height) {}

    AABBHitbox(YAML::Node hitbox_yaml)
        : Hitbox(HitboxType::AABB), _aabb(hitbox_yaml) {}


    virtual std::list<Edge> edges() const override;

    /** @copydoc Hitbox::collides(Point) const */
    bool collides(Point point) const override;

    /** @copydoc Hitbox:: collides(Edge) const */
    bool collides(Edge edge) const override;

    /** copydoc Hitbox::nearest_point(Point) const */
    Point closest_point(Point point) const override;

    /** @copydoc Hitbox::to_string() const */
    std::string to_string() const override;

    /** @copydoc Hitbox::drawable() const */
    SDL_GUI::Drawable *drawable() const override;

    void to_yaml(YAML::Emitter *output) const override;
};

class PolygonHitbox : public Hitbox {
    Polygon _polygon;

public:
    PolygonHitbox()
        : Hitbox(HitboxType::POLYGON) {}

    PolygonHitbox(YAML::Node hitbox_yaml);

    /**
     * Get Edges.
     * @return list of Edges.
     */
    virtual std::list<Edge> edges() const override;

    /**
     * Get Points.
     * @return list of Points.
     */
    std::list<Point> points() const;

    /**
     * Override Points.
     * @param points list of Points to insert.
     */
    void set_points(std::list<Point> points);

    /**
     * Add a Point.
     * @param p Point to add.
     */
    void add_point(Point p);

    void remove_point(Point &p);

    void remove_last_point();


    /** @copydoc Hitbox::collides(Point) const */
    bool collides(Point point) const override;

    /** @copydoc Hitbox:: collides(Edge) const */
    bool collides(Edge edge) const override;

    /** copydoc Hitbox::nearest_point(Point) const */
    Point closest_point(Point point) const override;

    /** @copydoc Hitbox::drawable() const */
    SDL_GUI::Drawable *drawable() const override;

    /** @copydoc Serialisable::to_yaml(YAML::Emitter *) const */
    void to_yaml(YAML::Emitter *output) const override;

    /** @copydoc Serialisable::to_string() const */
    std::string to_string() const override;

};

