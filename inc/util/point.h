#pragma once

#include <iostream>
#include <cmath>

#include <wykobi/wykobi.hpp>

#include <SDL_GUI/inc/gui/position.h>

using namespace std;
class Point {
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
    friend ostream& operator<<(ostream &output, const Point &p);
    Point operator+=(const Point &p);
    Point operator-=(const Point &p);
    Point operator*=(const float &s);
    Point operator/=(const float &s);


    /**
     * Move in a certain direction with a certain Speed.
     * @param to Point to move to.
     * @param disctance distance to move in the given direction
     */
    void move_to(Point to, float distance);

    /**
     * Get middle of two Points.
     * @param p Point to get middle to.
     * @return middle.
     */
    Point middle(Point p) const;
};
