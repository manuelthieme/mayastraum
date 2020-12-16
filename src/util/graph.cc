#include <util/graph.h>
#include <limits>

/* getter */
vector<Edge> Graph::edges() const {
    return this->_edges;
}

vector<Edge> Graph::edges(const Point p) const {
    vector<Edge> ret;
    for(auto e: this->_edges) {
        if(e.begin() != p && e.end() != p)
            continue;
        ret.push_back(e);
    }
    return ret;
}

vector<unsigned> Graph::outgoingEdges(unsigned p) const {
    vector<unsigned> ret;
    unsigned i = 0;
    for (auto e: this->_edges) {
        if (e.begin() != this->_nodes.at(p) && e.end() != this->_nodes.at(p)) {
            ++i;
            continue;
        }
        ret.push_back(i);
        ++i;
    }
    return ret;
}


/* setter */
void Graph::setEdges(vector<Edge> es) {
    this->_edges = es;
}

void Graph::addEdge(Edge e) {
    for (auto edge: this->_edges)
        if (edge == e)
            return;

    this->_edges.push_back(e);
    this->addNode(e.begin());
    this->addNode(e.end());
}

void Graph::addNode(Point p) {
    for (auto n: this->_nodes)
        if (p == n)
            return;

    this->_nodes.push_back(p);
}

void Graph::clear() {
    this->_edges.clear();
    this->_nodes.clear();
}

 /* misc */

list<Point> Graph::shortestPath(Point source, Point sink) const {
    signed source_i = -1;
    signed sink_i = -1;
    unsigned i = 0;
    for (auto n: this->_nodes) {
        if (n == source)
            source_i = i;

        if (n == sink)
            sink_i = i;

        if (source_i >= 0 && sink_i >= 0)
            break;

        ++i;
    }
    list<Point> ret = this->aStar(source_i, sink_i);
    return ret;
}

list<Point> Graph::dijkstra(Point source, Point sink) const {
    /* initialize */
    list<Point> ret;
    map<Point, Point> predecessor;
    map<Point, signed int> minLength;
    set<Point> q;

    /* check if source and sink are in graph */
    bool sourceIn = false;
    bool sinkIn = false;
    for (auto n: this->_nodes) {
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
    for (auto n: this->_nodes) {
        Point p;
        for(auto f: this->_nodes)
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



    while (not q.empty()) {
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

list<Point> Graph::aStar(int source, int sink) const {
    set<unsigned> closedSet;
    set<unsigned> openSet;
    openSet.insert(source);

    map<unsigned, unsigned> predecessor;

    map<unsigned, float> g_score;
    map<unsigned, float> f_score;

    cout << "size: " << this->_nodes.size() << endl;;
    for (unsigned i = 0; i < this->_nodes.size(); ++i) {
        g_score.insert({i, numeric_limits<float>::infinity()});
        f_score.insert({i, numeric_limits<float>::infinity()});
    }
    g_score.at(source) = 0;
    f_score.at(source) = this->heuristicCostEstimate(source, sink);
    cout << "heuristic for source: " << f_score.at(source) << endl;

    while (not openSet.empty()) {
        cout << "entering while loop" << endl;
        signed current = -1;
        for (auto n: openSet)
            if (current < 0 or f_score.at(n) < f_score.at(current))
                current = n;

        if (current == sink)
            return this->reconstructPath(predecessor, sink);

        openSet.erase(current);
        closedSet.insert(current);

        cout << "found " << this->outgoingEdges(current).size() << " outgoing edges" << endl;
        for (auto e: this->outgoingEdges(current)) {
            cout << "\tentering for loop" << endl;
            Point to;
            Edge edge = this->_edges.at(e);

            /* find corresponding node */
            if (edge.begin() == this->_nodes.at(current))
                to = edge.end();
            else
                to = edge.begin();

            signed to_i = this->nodeIndex(to);
            cout << "\tPoint " << to_i << endl;
            if (to_i < 0)
                break;


            if (closedSet.find(to_i) != closedSet.end())
                continue;

            float tentative_g_score = g_score.at(current) + edge.magnitude();

            if (openSet.find(to_i) == openSet.end())
                openSet.insert(to_i);
            else if (tentative_g_score >= g_score.at(to_i))
                continue;

            predecessor.insert({to_i, current});
            g_score.at(to_i) = tentative_g_score;
            f_score.at(to_i) = g_score.at(to_i) + heuristicCostEstimate(to_i, sink);
        }
        cout << "\tleaving for loop" << endl;
    }
    cout << "leaving while loop" << endl;
    list<Point> ret;
    return ret;
}

float Graph::heuristicCostEstimate(int start, int end) const {
    return Edge(this->_nodes.at(start), this->_nodes.at(end)).magnitude();
}

list<Point> Graph::reconstructPath(map<unsigned, unsigned> predecessor, unsigned sink) const {
    list<Point> ret;
    ret.push_front(this->_nodes.at(sink));
    while (predecessor.find(sink) != predecessor.end()) {
        sink = predecessor.at(sink);
        ret.push_front(this->_nodes.at(sink));
    }
    return ret;
}

signed Graph::nodeIndex(Point p) const {
    unsigned i = 0;
    for (auto n: this->_nodes) {
        cout << "comparing " << n << " with " << p << " ... " << endl;
        if (n == p)
            return i;

        cout << "obviously not the same" << endl;
        ++i;
    }
    return -1;
}
