#ifndef HITBOX_H
#define HITBOX_H

#include <vector>
#include "Edge.h"
#include "Point.h"

using namespace std;
class Hitbox {
    vector<Edge> edges;
    vector<Point> points;

public:
    /* constructor */
    Hitbox();

    /* getter */
    vector<Edge> Edges() const;
    vector<Point> Points() const;

    /* setter */
    void setEdges(vector<Edge> edges);
    void setPoints(vector<Point> points);

    /* operators */
    bool operator==(const Hitbox &h) const;
};

#endif /* HITBOX_H */
