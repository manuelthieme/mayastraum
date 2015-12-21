#include "../h/Hitbox.h"

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

/* setter */
void Hitbox::setPoints(vector<Point> points) {
    this->m_points = points;
}

void Hitbox::setEdges(vector<Edge> edges) {
    this->m_edges = edges;
}

/* operators */
bool Hitbox::operator==(const Hitbox &h) const {
    return this->m_edges == h.m_edges
        && this->m_points == h.m_points;
}
