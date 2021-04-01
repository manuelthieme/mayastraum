#pragma once

#include <wykobi/wykobi.hpp>

#include <util/edge.h>
#include <util/point.h>

class Circle {
    wykobi::circle<float> _circle;
public:
    /**
     * Constructor
     * @param center circles center point
     * @param radius circles radius
     */
    Circle(Point center = {0, 0}, float radius = 0)
        : _circle(wykobi::make_circle(center.vector(), radius)) {}

    wykobi::circle<float> circle() const;

    Point center() const;

    float radius() const;

    Point closest_point(Point point) const;

    friend ostream& operator<<(ostream &output, const Circle &circle);
};
