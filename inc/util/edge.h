#pragma once

#include <iostream>
#include <optional>

#include <wykobi/wykobi.hpp>

#include <util/point.h>

class Edge {

    /** First Point of Edge.  */
    Point _begin;

    /** Second Point of Edge.  */
    Point _end;

public:
    /**
     * Constructor.
     * @param begin First Point.
     * @param end Second Point.
     */
    Edge(Point begin, Point end)
        : _begin(begin), _end(end) {}

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

    /** get wykobi segment for this edge */
    wykobi::segment<float,2> segment() const;

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

    /**
     * Set First Point.
     * @param begin First Point.
     */
    void set_begin(Point begin);

    /**
     * Set Second Point.
     * @param end Second Point.
     */
    void set_end(Point end);

    /**
     * Shift end of edge to match given magnitude
     * @param magnitude target magnitude
     */
    void set_magnitude(float magnitude);

    /**
     * shift end of edge to scale the magnitude
     * @param scale scale factor
     */
    void scale(float scale);

    /* operators */
    bool operator==(const Edge &edge) const;
    friend ostream& operator<<(ostream &output, const Edge &edge);
    Edge operator+(const Point &point) const;
    Edge operator+=(const Point &point);
    Edge operator-(const Point &point) const;
    Edge operator-=(const Point &point);

    /**
     * Check if This Edge Intersects with another Edge.
     * Edges with similar start/end Points are considered not intersecting.
     * @param e Edge to check Intersecting with.
     * @return True if They intersect. Otherwise False.
     */
    bool intersects(Edge edge) const;

    /**
     * get the intersection with another Edge.
     * This always returns an intersection even if the lines are too short.
     */
    Point intersection(Edge edge) const;

    /**
     * Get The Point in the middle of this Edge.
     * @return Point in the middle.
     */
    Point middle() const;

    /** calculate point on the edge that is nearest to a given point */
    Point closest_point(Point point) const;
};
