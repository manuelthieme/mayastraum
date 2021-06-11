#pragma once

#include <iostream>
#include <cmath>

#include <yaml-cpp/yaml.h>

#include <wykobi/wykobi.hpp>

#include <SDL_GUI/gui/position.h>

#include <util/serialisable.h>

using namespace std;
class Point : public Serialisable {
    wykobi::vector2d<float> _point;

public:
    /**
     * Constructor.
     * @param x x-value.
     * @param y y-value.
     */
    Point(float x = 0, float y = 0);

    Point(const SDL_GUI::Position &position);

    Point(wykobi::point2d<float> point)
        : _point(wykobi::make_vector<float>(point[0], point[1])) {}

    Point(wykobi::vector2d<float> point)
        : _point(point) {}

    Point(YAML::Node point_yaml);

    /**
     * Get x-value.
     * @return x-value.
     */
    float x() const;

    /**
     * Get y-value.
     * @return y-value.
     */
    float y() const;

    /**
     * Get magnitude.
     * @return magnitude.
     */
    float magnitude() const;

    /** get the underlying wykobi vector */
    wykobi::vector2d<float> vector() const;

    /** get the SDL_GUI::Position */
    SDL_GUI::Position position() const;

    /**
     * Set x-value.
     * @param x x-value.
     */
    void set_x(float x);

    /**
     * Set y-value.
     * @param y y-value.
     */
    void set_y(float y);

    /**
     * Set x- and y-value.
     * @param x x-value.
     * @param y y-value.
     */
    void set_coords(float x, float y);

    /* operators */
    Point operator+(const Point &p) const;
    Point operator-(const Point &p) const;
    Point operator*(const float &s) const;
    Point operator/(const float &s) const;
    bool operator<(const Point &p) const;
    bool operator>(const Point &p) const;

    bool operator==(const Point &p) const;
    bool operator!=(const Point &p) const;
    Point operator+=(const Point &p);
    Point operator-=(const Point &p);
    Point operator*=(const float &s);
    Point operator/=(const float &s);


    /**
     * Move in a certain direction with a certain Speed.
     * @param to Point to move to.
     * @param disctance distance to move in the given direction
     * @param overflow if set to true, the result may exceed the target point
     */
    void move_to(Point to, float distance, bool overflow = false);

    void move(Point direction);

    /**
     * Get middle of two Points.
     * @param p Point to get middle to.
     * @return middle.
     */
    Point middle(Point p) const;

    float distance(Point p) const;

    void to_yaml(YAML::Emitter *output) const override;
    std::string to_string() const override;
};
