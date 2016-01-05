#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

using namespace std;
class Graph {
    vector<Edge> m_edges;
public:
    /* getter */
    vector<Edge> edges() const;

    /* setter */
    void setEdges(vector<Edge> es);
    void addEdge(Edge e);
};

#endif /* GRAPH_H */
