#pragma once

#include <iostream>
#include <list>

#include <wykobi/wykobi.hpp>

#include <yaml-cpp/yaml.h>

#include <SDL_GUI/gui/drawable.h>
#include <SDL_GUI/gui/primitives/polygon.h>

#include <util/geometry/point.h>
#include <util/geometry/edge.h>


class Polygon : public Serialisable {
    std::list<Point> _points;

    SDL_GUI::Polygon *_gui_polygon;
public:

    Polygon();

    Polygon(YAML::Node polygon_yaml);

    void init();

    std::list<Point> &points();
    std::list<Point> points() const;

    std::list<Edge> edges() const;

    wykobi::polygon<float, 2> polygon() const;

    void set_points(std::list<Point> points);
    void add_point(Point point);
    void remove_point(Point &point);
    void remove_last_point();

    bool collides(Point point) const;
    bool collides(Edge edge) const;

    Point closest_point(Point point) const;

    SDL_GUI::Drawable *drawable() const;

    /** @copydoc Serialisable::to_yaml(YAML::Emitter *) const */
    void to_yaml(YAML::Emitter *output) const override;

    /** @copydoc Serialisable::to_string() const */
    std::string to_string() const override;
};
