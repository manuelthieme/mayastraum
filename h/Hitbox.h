#ifndef HITBOX_H
#define HITBOX_H

#include <iostream>
#include <vector>

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
    Point offPoint() const;

    /* setter */
    void setEdges(vector<Edge> edges);
    void addEdge(Edge e);
    void setPoints(vector<Point> points);
    void addPoint(Point p);

    /* operators */
    bool operator==(const Hitbox &h) const;
    friend ostream& operator<<(ostream &output, const Hitbox &h);


    /* misc */
    void calculateEdges();
};

#endif /* HITBOX_H */
