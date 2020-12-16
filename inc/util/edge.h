#pragma once

#include <iostream>

#include <util/point.h>

class Edge {
    /**
     * First Point of Edge.
     */
    Point _begin;
    /**
     * Second Point of Edge.
     */
    Point _end;

public:
    /* constructor */
    /**
     * Constructor.
     * @param begin First Point.
     * @param end Second Point.
     */
    Edge(Point begin, Point end);

    /* getter */
    /**
     * Get first Point.
     * @return First Point.
     */
    Point begin() const;
    /**
     * Get second Point.
     * @return Second Point.
     */
    Point end() const;
    /**
     * Get Slope.
     * @return Slope of Edge.
     */
    float slope() const;
    /**
     * Get Magnitude.
     * @return Magnitude of the Points of this Edge.
     */
    float magnitude() const;

    /* setter */
    /**
     * Set First Point.
     * @param begin First Point.
     */
    void setBegin(Point begin);
    /**
     * Set Second Point.
     * @param end Second Point.
     */
    void setEnd(Point end);

    /* operators */
    bool operator==(const Edge &e) const;
    friend ostream& operator<<(ostream &output, const Edge &e);
    Edge operator+(const Point &p) const;
    Edge operator+=(const Point &p);

    /* misc */
    /**
     * Check if This Edge Intersects with another Edge.
     * Edges with similar start/end Points are considered not intersecting.
     * @param e Edge to check Intersecting with.
     * @return True if They intersect. Otherwise False.
     */
    bool intersects(Edge e) const;
    /**
     * Get The Point in the middle of this Edge.
     * @return Point in the middle.
     */
    Point middle() const;
};
