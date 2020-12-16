#include <util/edge.h>

using namespace std;
/* constructor */
Edge::Edge(Point begin, Point end) : _begin(begin), _end(end) {
}

/* getter */
Point Edge::begin() const {
    return this->_begin;
}

Point Edge::end() const {
    return this->_end;
}

float Edge::slope() const {
    return (this->_begin.y() - this->_end.y()) / (this->_begin.x() - this->_end.x());
}

float Edge::magnitude() const {
    return max(this->_begin.magnitude(), this->_end.magnitude()) - min(this->_begin.magnitude(), this->_end.magnitude());
}

/* setter */
void Edge::setBegin(Point begin) {
    this->_begin = begin;
}

void Edge::setEnd(Point end) {
    this->_end = end;
}


/* operators */
bool Edge::operator==(const Edge &e) const{
    return (this->_begin == e._begin && this->_end == e._end)
        || (this->_end == e._begin && this->_begin == e._end);
}

ostream& operator<<(ostream &output, const Edge &e) {
    Point b = e.begin();
    Point end = e.end();
    output << b << "---" << end;
    return output;
}

Edge Edge::operator+(const Point &p) const {
    return Edge(this->_begin + p, this->_end + p);
}

Edge Edge::operator+=(const Point &p) {
    this->_begin += p;
    this->_end += p;

    return *this;
}

/* misc */
bool Edge::intersects(Edge e) const {

    Point intersection(0, 0);

    if (this->_begin.x() == this->_end.x() and e._begin.x() == e._end.x()) {
        if (this->_begin.x() != e._begin.x()) {
            return false;
        } else {
            return false;
        }
    }
    if (this->_begin.x() == this->_end.x()) {
        float m = e.slope();
        float n = e._begin.y() - e._begin.x() * m;
        intersection = Point(this->_begin.x(), m * this->_begin.x() + n);
    } else if (e._begin.x() == e._end.x()) {
        float m = this->slope();
        float n = this->_begin.y() - this->_begin.x() * m;
        intersection = Point(e._begin.x(), m * e._begin.x() + n);
    } else {
        /* get slopes */
        float m1 = this->slope();
        float m2 = e.slope();

        float n1 = this->_begin.y() - this->_begin.x() * m1;
        float n2 = e._begin.y() - e._begin.x() * m2;

        if (m1 == m2)
            if (n1 == n2)
                return true;
            else
                return false;

        //cout << *this << endl << e << endl;
        //cout << "\t" << m1 << "\t" << m2 << endl;

        /* get intersection */
        float x = (n2 - n1) / (m1 - m2);
        float y = m1 * x + n1;

        intersection = Point(x, y);
    }

    /* check whether intersection is one of the given EdgePoints */
    bool isEdgePoint = (intersection.x() == this->_begin.x() || intersection.x() == this->_end.x());

    /* check whether intersection is in bounds */
    bool inBounds =
        min(this->_begin.x(), this->_end.x()) <= intersection.x() && intersection.x() <= max(this->_begin.x(), this->_end.x())
        && min(e._begin.x(), e._end.x()) <= intersection.x()      && intersection.x() <= max(e._begin.x(), e._end.x());

    return (!isEdgePoint && inBounds);
}

Point Edge::middle() const {
    return this->_begin.middle(this->_end);
}
