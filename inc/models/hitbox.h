#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <SDL_GUI/gui/drawable.h>

#include <yaml-cpp/yaml.h>

#include <util/aabb.h>
#include <util/circle.h>
#include <util/edge.h>

using namespace std;

/** Base class for the different options to describe a hitbox */
class Hitbox {
public:

    Hitbox() = default;

    virtual ~Hitbox() = default;

    friend ostream& operator<<(ostream &output, const Hitbox &hitbox);

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

    virtual void to_yaml(YAML::Emitter *out) const = 0;
};

YAML::Emitter &operator<<(YAML::Emitter &out, const Hitbox &hitbox);

/** Hitbox given through a circle */
class CircleHitbox : public Hitbox {
    Circle _circle; /**< circle describing this hitbox */
public:
    /**
     * Constructor
     * @param circle circle describing the hitbox
     */
    CircleHitbox(Circle circle)
        : _circle(circle) {}

    /**
     * Constructor
     * @param center circles center point
     * @param radius circles radius
     */
    CircleHitbox(Point center = {0, 0}, float radius = 0)
        : _circle(center, radius) {}

    CircleHitbox(YAML::Node hitbox_yaml)
        : _circle(hitbox_yaml) {}


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

    void to_yaml(YAML::Emitter *out) const override;
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
        : _aabb(position, width, height) {}

    AABBHitbox(YAML::Node hitbox_yaml);

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

    void to_yaml(YAML::Emitter *out) const override;
};

class PolygonHitbox : public Hitbox {
    /** Vector of Edges. */
    vector<Edge> _edges;

    /** vector of Points. */
    vector<Point> _points;

public:
   PolygonHitbox(YAML::Node hitbox_yaml);

    /**
     * Get Edges.
     * @return Vector of Edges.
     */
    vector<Edge> edges() const;

    /**
     * Get Points.
     * @return Vector of Points.
     */
    vector<Point> points() const;

    /**
     * Get A Point defenitely outside the Hitbox.
     * @return Point outside the Hitbox.
     */
    Point off_point() const;

    /**
     * Override Edges.
     * @param edges Vector of Edges to insert.
     */
    void set_edges(vector<Edge> edges);

    /**
     * Add an Edge.
     * @param e Edge to add.
     */
    void add_edge(Edge e);

    /**
     * Override Points.
     * @param points Vector of Points to insert.
     */
    void set_points(vector<Point> points);

    /**
     * Add a Point.
     * @param p Point to add.
     */
    void add_point(Point p);


    /** Calculate Edges on based on the Points by building a Cycle.  */
    void calculate_edges();

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

    void to_yaml(YAML::Emitter *out) const override;
};

