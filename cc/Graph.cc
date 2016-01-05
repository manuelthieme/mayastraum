#include "../h/includes.h"

/* getter */
vector<Edge> Graph::edges() const {
    return this->m_edges;
}

/* setter */
void Graph::setEdges(vector<Edge> es) {
    this->m_edges = es;
}

void Graph::addEdge(Edge e) {
    this->m_edges.push_back(e);
}
