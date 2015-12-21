#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;
class Point {
    float m_x;
    float m_y;

public:
    /* constructor */
    Point(float x, float y);

    /* getter */
    float x() const;
    float width() const;
    float y() const;
    float height() const;

    /* setter */
    void setX(float x);
    void setWidth(float width);
    void setY(float Y);
    void setHeight(float height);

    /* operators */
    bool operator==(const Point &h) const;
    friend ostream& operator<<(ostream &output, const Point &p);
};

#endif /* EDGE_H */
