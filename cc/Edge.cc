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


/* operators */
bool Edge::operator==(const Edge &e) const{
    return this->begin == e.begin
        && this->end == e.end;
}
