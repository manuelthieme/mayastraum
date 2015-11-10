#ifndef POINT_H
#define POINT_H


class Point {
    float x;
    float y;

public:
    /* constructor */
    Point(float x, float y);

    /* getter */
    float X() const;
    float Y() const;

    /* setter */
    void setX(float x);
    void setY(float Y);
};

#endif /* EDGE_H */
