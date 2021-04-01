#pragma once

#include <wykobi/wykobi.hpp>

#include <util/point.h>

class AABB {
    Point _position;
    float _width;
    float _height;
public:
    AABB(Point position = {0, 0}, float width = 0, float height = 0)
        : _position(position), _width(width), _height(height) {}

    wykobi::rectangle<float> rectangle() const;

    Point position() const;

    float width() const;

    float height() const;

    Point closest_point(Point point) const;

    friend ostream& operator<<(ostream &output, const AABB &aabb);

};
