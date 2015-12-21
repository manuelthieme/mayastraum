#ifndef EDGE_H
#define EDGE_H

#include "Point.h"

class Edge {
    Point m_begin;
    Point m_end;

public:
    /* constructor */
    Edge(Point begin, Point end);

    /* getter */
    Point begin() const;
    Point end() const;

    /* setter */
    void setBegin(Point begin);
    void setEnd(Point end);

    /* operators */
    bool operator==(const Edge &e) const;
};

#endif /* EDGE_H */
