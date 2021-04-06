#pragma once

#include <iostream>
#include <list>

#include <wykobi/wykobi.hpp>

#include <yaml-cpp/yaml.h>

#include <SDL_GUI/gui/drawable.h>

#include <util/geometry/point.h>
#include <util/geometry/edge.h>


class Polygon : public Serialisable {
    std::list<Point> _points;
public:

    Polygon() = default;

    Polygon(YAML::Node polygon_yaml);

    std::list<Point> &points();
    std::list<Point> points() const;

    std::list<Edge> edges() const;

    wykobi::polygon<float, 2> polygon() const;

    void set_points(std::list<Point> points);
    void add_point(Point point);
    void remove_point(Point &point);

    bool collides(Point point) const;
    bool collides(Edge edge) const;

    Point closest_point(Point point) const;

    SDL_GUI::Drawable *drawable() const;

    /** @copydoc Serialisable::to_yaml(YAML::Emitter *) const */
    void to_yaml(YAML::Emitter *output) const override;

    /** @copydoc Serialisable::to_string() const */
    std::string to_string() const override;
};
