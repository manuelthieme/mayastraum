#include "../h/Edge.h"

/* constructor */
Edge::Edge(Point begin, Point end) : begin(begin), end(end) {
}

/* getter */
Point Edge::Begin() const {
    return this->begin;
}

Point Edge::End() const {
    return this->end;
}

/* setter */
void Edge::setBegin(Point begin) {
    this->begin = begin;
}

void Edge::setEnd(Point end) {
    this->end = end;
}
