#include "../h/includes.h"

/* getter */
vector<Edge> Graph::edges() const {
    return this->m_edges;
}

vector<Edge> Graph::edges(const Point p) const {
    vector<Edge> ret;
    for(auto e: this->m_edges) {
        if(e.begin() != p && e.end() != p)
            continue;
        ret.push_back(e);
    }
    return ret;
}


/* setter */
void Graph::setEdges(vector<Edge> es) {
    this->m_edges = es;
}

void Graph::addEdge(Edge e) {
    for (auto edge: this->m_edges)
        if (edge == e)
            return;

    this->m_edges.push_back(e);
    this->addNode(e.begin());
    this->addNode(e.end());
}

void Graph::addNode(Point p) {
    for (auto n: this->m_nodes)
        if (p == n)
            return;

    this->m_nodes.push_back(p);
}

void Graph::clear() {
    this->m_edges.clear();
}

 /* misc */

list<Point> Graph::shortestPath(Point source, Point sink) const {

    /* initialize */
    list<Point> ret;
    map<Point, Point> predecessor;
    map<Point, signed int> minLength;
    set<Point> q;

    /* check if source and sink are in graph */
    bool sourceIn = false;
    bool sinkIn = false;
    for (auto n: this->m_nodes) {
        if (n == source) {
            sourceIn = true;
            if (sinkIn)
                break;
        }
        if (n == sink) {
            sinkIn = true;
            if (sourceIn)
                break;
        }
    }

    if (not (sourceIn and sinkIn))
        return ret;

    /* set length to infinite */
    for (auto n: this->m_nodes) {
        Point p;
        for(auto f: this->m_nodes)
            if(f == n){
                p = f;
                break;
            }

        minLength[p] = -1;
    }

    /* source length is zero */
    minLength[source] = 0;

    /* source is in queue */
    q.insert(source);



    while (!q.empty()) {
        /* find nearest node in queue */
        Point p;
        bool pIsSet = false;
        for(auto point: q) {
            if(!pIsSet or minLength[point] < minLength[p]) {
                p = point;
                pIsSet = true;
            } else {
            }
        }
        /* erase it from queue */
        for(auto it: q)
            if(it == p)
                q.erase(it);

        /* analize edges */
        for(auto e: this->edges(p)) {
            Point to;
            /* find corresponding node */
            if (e.begin() == p)
                to = e.end();
            else
                to = e.begin();


            /* if not visited yet, push_back into queue and set predecessor*/
            if(minLength[to] == -1) {
                q.insert(to);
                minLength[to] = minLength[p] + e.magnitude();
                predecessor[to] = p;
            }
            /* if length is lower, update length and predecessor */
            else if(minLength[to] > (minLength[p] + e.magnitude())) {
                minLength[to] = minLength[p] + e.magnitude();
            }
        }
    }

    /* make list from predecessors */
    ret.push_front(sink);
    Point toPush = sink;
    while (toPush != source) {
        if(minLength[toPush] == -1)
            break;
        toPush = predecessor[toPush];
        ret.push_front(toPush);
    }
    return ret;
}

