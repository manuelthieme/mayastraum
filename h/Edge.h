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

    /* setter */
    void setBegin(Point begin);
    void setEnd(Point end);

    /* operators */
    bool operator==(const Edge &e) const;
    friend ostream& operator<<(ostream &output, const Edge &e);
};

#endif /* EDGE_H */
