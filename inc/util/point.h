#pragma once

#include <iostream>
#include <cmath>

#include <SDL_GUI/inc/gui/position.h>

using namespace std;
class Point {
    /** x-value. */
    float _x;

    /** y-value. */
    float _y;

    /** magnitude. */
    float _magnitude;

    /** Calculate Magnitude. */
    void calcMagnitude();
public:
    /**
     * Constructor.
     * @param x x-value.
     * @param y y-value.
     */
    Point(float x = 0, float y = 0);

    Point(const SDL_GUI::Position &position);

    /**
     * Get x-value.
     * @return x-value.
     */
    float x() const;

    /**
     * Get width.
     * A Point can also be used as a 2D size. For this case, there are this special getters.
     * @return width.
     */
    float width() const;

    /**
     * Get y-value.
     * @return y-value.
     */
    float y() const;

    /**
     * Get height.
     * A Point can also be used as a 2D size. For this case, there are this special getters.
     * @return height.
     */
    float height() const;

    /**
     * Get magnitude.
     * @return magnitude.
     */
    float magnitude() const;

    /**
     * Set x-value.
     * @param x x-value.
     */
    void setX(float x);

    /**
     * Set width.
     * A Point can also be used as a 2D size. For this case, there are this special setters.
     * @param width width.
     */
    void setWidth(float width);

    /**
     * Set y-value.
     * @param y y-value.
     */
    void setY(float Y);

    /**
     * Set height.
     * A Point can also be used as a 2D size. For this case, there are this special setters.
     * @param height height.
     */
    void setHeight(float height);

    /**
     * Set x- and y-value.
     * @param x x-value.
     * @param y y-value.
     */
    void setXY(float x, float y);

    /* operators */
    Point operator+(const Point &p) const;
    Point operator-(const Point &p) const;
    bool operator<(const Point &p) const;
    bool operator>(const Point &p) const;

    bool operator==(const Point &p) const;
    bool operator!=(const Point &p) const;
    friend ostream& operator<<(ostream &output, const Point &p);
    Point operator+=(const Point &p);

    /**
     * Move in a certain direction with a certain Speed.
     * @param to Point to move to.
     * @param speed Speed with wich to move.
     */
    void moveTo(Point to, float speed);

    /**
     * Get middle of two Points.
     * @param p Point to get middle to.
     * @return middle.
     */
    Point middle(Point p) const;
};
