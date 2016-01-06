#ifndef HITBOX_H
#define HITBOX_H

#include <iostream>
#include <vector>

using namespace std;
class Hitbox {
    /**
     * Vector of Edges.
     */
    vector<Edge> m_edges;
    /**
     * vector of Points.
     */
    vector<Point> m_points;

public:
    /* constructor */
    /**
     * Cnstructor
     */
    Hitbox();

    /* getter */
    /**
     * Get Edges.
     * \return Vector of Edges.
     */
    vector<Edge> edges() const;
    /**
     * Get Points.
     * \return Vector of Points.
     */
    vector<Point> points() const;
    /**
     * Get A Point defenitely outside the Hitbox.
     * \return Point outside the Hitbox.
     */
    Point offPoint() const;

    /* setter */
    /**
     * Override Edges.
     * \param edges Vector of Edges to insert.
     */
    void setEdges(vector<Edge> edges);
    /**
     * Add an Edge.
     * \param e Edge to add.
     */
    void addEdge(Edge e);
    /**
     * Override Points.
     * \param points Vector of Points to insert.
     */
    void setPoints(vector<Point> points);
    /**
     * Add a Point.
     * \param p Point to add.
     */
    void addPoint(Point p);

    /* operators */
    bool operator==(const Hitbox &h) const;
    friend ostream& operator<<(ostream &output, const Hitbox &h);


    /* misc */
    /**
     * Calculate Edges on based on the Points by building a Cycle.
     */
    void calculateEdges();
};

#endif /* HITBOX_H */
