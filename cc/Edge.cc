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
    return (this->m_begin.y() - this->m_end.y()) / (this->m_begin.x() - this->m_end.x());
}

float Edge::magnitude() const {
    return max(this->m_begin.magnitude(), this->m_end.magnitude()) - min(this->m_begin.magnitude(), this->m_end.magnitude());
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

    Point possible(0, 0);

    if (this->m_begin.x() == this->m_end.x() and e.m_begin.x() == e.m_end.x()) {
        if (this->m_begin.x() != e.m_begin.x()) {
            return false;
        } else {
            return false;
        }
    }
    if (this->m_begin.x() == this->m_end.x()) {
        float m = e.slope();
        float n = e.m_begin.y() - e.m_begin.x() * m;
        possible = Point(this->m_begin.x(), m * this->m_begin.x() + n);
    } else if (e.m_begin.x() == e.m_end.x()) {
        float m = this->slope();
        float n = this->m_begin.y() - this->m_begin.x() * m;
        possible = Point(e.m_begin.x(), m * e.m_begin.x() + n);
    }

    /* get slopes */
    float m1 = this->slope();
    float m2 = e.slope();

    float n1 = this->m_begin.y() - this->m_begin.x() * m1;
    float n2 = e.m_begin.y() - e.m_begin.x() * m2;

    if (m1 == m2)
        if (n1 == n2)
            return true;
        else
            return false;

    //cout << *this << endl << e << endl;
    //cout << "\t" << m1 << "\t" << m2 << endl;

    /* get intersection */
    float x = (n2 - n1) / (m1 - m2);
    //float y = m1 * x + n1;

    //Point p(x, y);

    /* check whether intersection is in bounds */
    return min(this->m_begin.x(), this->m_end.x()) < x && x < max(this->m_begin.x(), this->m_end.x())
        && min(e.m_begin.x(), e.m_end.x()) < x          && x < max(e.m_begin.x(), e.m_end.x());
}

Point Edge::middle() const {
    return this->m_begin.middle(this->m_end);
}
