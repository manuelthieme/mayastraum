#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

using namespace std;
class Point {
    float m_x;
    float m_y;
    float m_magnitude;

    void calcMagnitude();
public:
    /* constructor */
    Point(float x = 0, float y = 0);

    /* getter */
    float x() const;
    float width() const;
    float y() const;
    float height() const;
    float magnitude() const;

    /* setter */
    void setX(float x);
    void setWidth(float width);
    void setY(float Y);
    void setHeight(float height);
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
    void moveTo(Point to, float speed);
    Point middle(Point p) const;
};

#endif /* EDGE_H */
