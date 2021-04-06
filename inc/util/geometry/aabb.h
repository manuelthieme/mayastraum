#pragma once

#include <wykobi/wykobi.hpp>

#include <util/geometry/point.h>
#include <util/serialisable.h>

class AABB : public Serialisable {
    Point _position;
    float _width;
    float _height;
public:
    AABB(Point position = {0, 0}, float width = 0, float height = 0)
        : _position(position), _width(width), _height(height) {}

    AABB(YAML::Node hitbox_yaml);

    wykobi::rectangle<float> rectangle() const;

    Point position() const;

    float width() const;

    float height() const;

    Point closest_point(Point point) const;

    void to_yaml(YAML::Emitter *output) const override;

    std::string to_string() const override;
};
