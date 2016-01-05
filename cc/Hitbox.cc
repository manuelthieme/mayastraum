#include "../h/includes.h"

using namespace std;
/* constructor */
Hitbox::Hitbox() {
}

/* getter */
vector<Point> Hitbox::points() const {
    return this->m_points;
}

vector<Edge> Hitbox::edges() const {
    return this->m_edges;
}

Point Hitbox::offPoint() const {
    if (this->m_points.size() < 1)
        return Point(0, 0);
    Point point = this->m_points.front();
    for (auto p: this->m_points) {
        if (p.x() < point.x())
            point.setX(p.x());

        if (p.y() < point.y())
            point.setY(p.y());

    }
    return point + Point(-1, -1);
}

/* setter */
void Hitbox::setPoints(vector<Point> points) {
    this->m_points = points;
}

void Hitbox::addPoint(Point p) {
    this->m_points.push_back(p);
}

void Hitbox::setEdges(vector<Edge> edges) {
    this->m_edges = edges;
}
void Hitbox::addEdge(Edge e) {
    this->m_edges.push_back(e);
}

/* operators */
bool Hitbox::operator==(const Hitbox &h) const {
    return this->m_edges == h.m_edges
        && this->m_points == h.m_points;
}

ostream& operator<<(ostream &output, const Hitbox &h) {
    for (auto e: h.edges())
        output << e << endl;

    return output;
}


/* misc */

void Hitbox::calculateEdges() {
    if (this->m_points.size() < 1)
        return;
    this->m_edges.clear();
    Point before(0, 0);
    bool first = false;
    for (auto p: this->m_points) {
        if (!first) {
            first = true;
            before = p;
            continue;
        }
        Edge e(before, p);
        this->m_edges.push_back(e);
        before = p;
    }
    Edge e(before, this->m_points.front());
    this->m_edges.push_back(e);
}
