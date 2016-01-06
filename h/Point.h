#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

using namespace std;
class Point {
    /**
     * x-value.
     */
    float m_x;
    /**
     * y-value.
     */
    float m_y;
    /**
     * magnitude.
     */
    float m_magnitude;

    /**
     * Calculate Magnitude.
     */
    void calcMagnitude();
public:
    /* constructor */
    /**
     * Constructor.
     * \param x x-value.
     * \param y y-value.
     */
    Point(float x = 0, float y = 0);

    /* getter */
    /**
     * Get x-value.
     * \return x-value.
     */
    float x() const;
    /**
     * Get width.
     * A Point can also be used as a 2D size. For this case, there are this special getters.
     * \return width.
     */
    float width() const;
    /**
     * Get y-value.
     * \return y-value.
     */
    float y() const;
    /**
     * Get height.
     * A Point can also be used as a 2D size. For this case, there are this special getters.
     * \return height.
     */
    float height() const;
    /**
     * Get magnitude.
     * \return magnitude.
     */
    float magnitude() const;

    /* setter */
    /**
     * Set x-value.
     * \param x x-value.
     */
    void setX(float x);
    /**
     * Set width.
     * A Point can also be used as a 2D size. For this case, there are this special setters.
     * \param width width.
     */
    void setWidth(float width);
    /**
     * Set y-value.
     * \param y y-value.
     */
    void setY(float Y);
    /**
     * Set height.
     * A Point can also be used as a 2D size. For this case, there are this special setters.
     * \param height height.
     */
    void setHeight(float height);
    /**
     * Set x- and y-value.
     * \param x x-value.
     * \param y y-value.
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

    /* misc */
    /**
     * Move in a certain direction with a certain Speed.
     * \param to Point to move to.
     * \param speed Speed with wich to move.
     */
    void moveTo(Point to, float speed);
    /**
     * Get middle of two Points.
     * \param p Point to get middle to.
     * \return middle.
     */
    Point middle(Point p) const;
};

#endif /* EDGE_H */
