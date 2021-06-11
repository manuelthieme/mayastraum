#pragma once

#include <vector>
#include <list>
#include <map>
#include <set>

#include <util/geometry/edge.h>
#include <util/geometry/point.h>

class Graph {
    /**
     * List of Edges.
     */
    std::vector<Edge> _edges;
    /**
     * List of Points.
     */
    std::vector<Point> _nodes;

    /**
     * Add a Node if possible.
     * Checks, whether the Point List already contains a Point.
     * @param p Node to add.
     */
    void add_node(Point p);

    std::list<Point> dijkstra(Point source, Point sink) const;
    std::list<Point> a_star(int source, int sink) const;
    float heuristic_cost_estimate(int start, int end) const;
    std::list<Point> reconstruct_path(std::map<unsigned, unsigned> predecessor, unsigned sink) const;
    std::vector<unsigned> outgoing_edges(unsigned p) const;
    signed node_index(Point p) const;
public:
    /* getter */
    /**
     * Get Edge List.
     * @return Vector of Edges.
     */
    std::vector<Edge> edges() const;

    /**
     * Get All Edges concerning to a Point.
     * @param p Point which is part of the wanted Edges.
     * @return Vector of Edges.
     */
    std::vector<Edge> edges(const Point p) const;

    std::vector<Point> nodes() const;

    /* setter */
    /**
     * Override Edges.
     * @param es vector of Edges.
     */
    void set_edges(std::vector<Edge> es);

    /**
     * Add Edge if not already in Graph.
     * @param e Edge to add.
     */
    void add_edge(Edge e);

    /*
     * Delete all Edges and Nodes.
     */
    void clear();

    bool contains(Point p) const;
    bool contains(Edge e) const;

    /* Calculate shortest path from source to sink.
     * @param source Source.
     * @param sink Sink.
     * @return If source and sink are Part of the Graph, returns shortest Path. Else returns empty List.
     */
    std::list<Point> shortest_path(Point source, Point sink) const;
};
