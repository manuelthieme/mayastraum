#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;
class Graph {
    vector<Edge> m_edges;
    vector<Point> m_nodes;

    void addNode(Point p);
public:
    /* getter */
    vector<Edge> edges() const;
    vector<Edge> edges(const Point p) const;

    /* setter */
    void setEdges(vector<Edge> es);
    void addEdge(Edge e);
    void clear();

    /* misc */
    list<Point> shortestPath(Point source, Point sink) const;
};

#endif /* GRAPH_H */
