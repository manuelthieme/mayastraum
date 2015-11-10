#ifndef EDGE_H
#define EDGE_H

#include "Point.h"

class Edge {
    Point begin;
    Point end;

public:
    /* constructor */
    Edge(Point begin, Point end);

    /* getter */
    Point Begin() const;
    Point End() const;

    /* setter */
    void setBegin(Point begin);
    void setEnd(Point end);
};

#endif /* EDGE_H */
