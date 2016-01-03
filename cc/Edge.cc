#include "../h/includes.h"

using namespace std;
/* constructor */
Edge::Edge(Point begin, Point end) : m_begin(begin), m_end(end) {
}

/* getter */
Point Edge::begin() const {
    return this->m_begin;
}

Point Edge::end() const {
    return this->m_end;
}

/* setter */
void Edge::setBegin(Point begin) {
    this->m_begin = begin;
}

void Edge::setEnd(Point end) {
    this->m_end = end;
}


/* operators */
bool Edge::operator==(const Edge &e) const{
    return this->m_begin == e.m_begin
        && this->m_end == e.m_end;
}

ostream& operator<<(ostream &output, const Edge &e) {
    Point b = e.begin();
    Point end = e.end();
    output << b << "---" << end;
    return output;
}

