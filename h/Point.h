#ifndef POINT_H
#define POINT_H


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
};

#endif /* EDGE_H */
