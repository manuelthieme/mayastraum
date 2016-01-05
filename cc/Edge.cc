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

float Edge::slope() const {
    if (this->m_begin.x() == this->m_end.x())
        return 0;
    return (this->m_begin.y() - this->m_end.y()) / (this->m_begin.x() - this->m_end.x());
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
    return (this->m_begin == e.m_begin && this->m_end == e.m_end)
        || (this->m_end == e.m_begin && this->m_begin == e.m_end);
}

ostream& operator<<(ostream &output, const Edge &e) {
    Point b = e.begin();
    Point end = e.end();
    output << b << "---" << end;
    return output;
}

Edge Edge::operator+(const Point &p) const {
    return Edge(this->m_begin + p, this->m_end + p);
}

Edge Edge::operator+=(const Point &p) {
    this->m_begin += p;
    this->m_end += p;

    return *this;
}

/* misc */
bool Edge::intersects(Edge e) const {
    /* get slopes */
    float m1 = this->slope();
    float m2 = e.slope();
    if (m1 == m2)
        return false;

    //cout << *this << endl << e << endl;
    //cout << "\t" << m1 << "\t" << m2 << endl;

    float n1 = this->m_begin.y() - this->m_begin.x() * m1;
    float n2 = e.m_begin.y() - e.m_begin.x() * m2;

    /* get intersection */
    float x = (n2 - n1) / (m1 - m2);
    float y = m1 * x + n1;

    Point p(x, y);

    /* check whether intersection is in bounds */
    bool ret = ((x < this->m_begin.x() && x > this->m_end.x()) || (x > this->m_begin.x() && x < this->m_end.x()))
            && ((y < this->m_begin.y() && y > this->m_end.y()) || (y > this->m_begin.y() && y < this->m_end.y()))
            && ((x < e.m_begin.x()     && x > e.m_end.x())     || (x > e.m_begin.x()     && x < e.m_end.x()))
            && ((y < e.m_begin.y()     && y > e.m_end.y())     || (y > e.m_begin.y()     && y < e.m_end.y()));

    return ret;
}

Point Edge::middle() const {
    return this->m_begin.middle(this->m_end);
}
