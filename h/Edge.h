#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#if 0
#include "Point.h"
#endif

class Edge {
    Point m_begin;
    Point m_end;

public:
    /* constructor */
    Edge(Point begin, Point end);

    /* getter */
    Point begin() const;
    Point end() const;
    float slope() const;

    /* setter */
    void setBegin(Point begin);
    void setEnd(Point end);

    /* operators */
    bool operator==(const Edge &e) const;
    friend ostream& operator<<(ostream &output, const Edge &e);
    Edge operator+(const Point &p) const;
    Edge operator+=(const Point &p);

    /* misc */
    bool intersects(Edge e) const;
    Point middle() const;
};

#endif /* EDGE_H */
