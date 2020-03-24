#pragma once

#if 0
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;
class Graph {
    /**
     * List of Edges.
     */
    vector<Edge> m_edges;
    /**
     * List of Points.
     */
    vector<Point> m_nodes;

    /**
     * Add a Node if possible.
     * Checks, whether the Point List already contains a Point.
     * @param p Node to add.
     */
    void addNode(Point p);
    list<Point> dijkstra(Point source, Point sink) const;
    list<Point> aStar(int source, int sink) const;
    float heuristicCostEstimate(int start, int end) const;
    list<Point> reconstructPath(map<unsigned, unsigned> predecessor, unsigned sink) const;
    vector<unsigned> outgoingEdges(unsigned p) const;
    signed nodeIndex(Point p) const;
public:
    /* getter */
    /**
     * Get Edge List.
     * @return Vector of Edges.
     */
    vector<Edge> edges() const;
    /**
     * Get All Edges concerning to a Point.
     * @param p Point which is part of the wanted Edges.
     * @return Vector of Edges.
     */
    vector<Edge> edges(const Point p) const;

    /* setter */
    /**
     * Override Edges.
     * @param es vector of Edges.
     */
    void setEdges(vector<Edge> es);
    /**
     * Add Edge if not already in Graph.
     * @param e Edge to add.
     */
    void addEdge(Edge e);
    /*
     * Delete all Edges and Nodes.
     */
    void clear();

    /* misc */
    /* Calculate shortest path from source to sink.
     * @param source Source.
     * @param sink Sink.
     * @return If source and sink are Part of the Graph, returns shortest Path. Else returns empty List.
     */
    list<Point> shortestPath(Point source, Point sink) const;
};

#endif
