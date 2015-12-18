#include "../h/Hitbox.h"

/* constructor */
Hitbox::Hitbox() {
}

/* getter */
vector<Point> Hitbox::Points() const {
    return this->points;
}

vector<Edge> Hitbox::Edges() const {
    return this->edges;
}

/* setter */
void Hitbox::setPoints(vector<Point> points) {
    this->points = points;
}

void Hitbox::setEdges(vector<Edge> edges) {
    this->edges = edges;
}

/* operators */
bool Hitbox::operator==(const Hitbox &h) const {
    return this->edges == h.edges
        && this->points == h.points;
}
