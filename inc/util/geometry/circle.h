#pragma once

#include <yaml-cpp/yaml.h>

#include <wykobi/wykobi.hpp>

#include <util/geometry/edge.h>
#include <util/geometry/point.h>
#include <util/serialisable.h>

class Circle : public Serialisable {
    wykobi::circle<float> _circle;
public:
    /**
     * Constructor
     * @param center circles center point
     * @param radius circles radius
     */
    Circle(Point center = {0, 0}, float radius = 0)
        : _circle(wykobi::make_circle(center.vector(), radius)) {}

    Circle(YAML::Node circle_yaml);

    wykobi::circle<float> circle() const;

    Point center() const;

    float radius() const;

    Point closest_point(Point point) const;

    bool point_on_circle(Point point) const;

    std::vector<Point> collision_points(Edge edge) const;

    void to_yaml(YAML::Emitter *output) const override;
    std::string to_string() const override;
};
