#ifndef HITBOX_H
#define HITBOX_H

#include <vector>
#include "Edge.h"
#include "Point.h"

using namespace std;
class Hitbox {
    vector<Edge> m_edges;
    vector<Point> m_points;

public:
    /* constructor */
    Hitbox();

    /* getter */
    vector<Edge> edges() const;
    vector<Point> points() const;

    /* setter */
    void setEdges(vector<Edge> edges);
    void setPoints(vector<Point> points);

    /* operators */
    bool operator==(const Hitbox &h) const;
};

#endif /* HITBOX_H */
