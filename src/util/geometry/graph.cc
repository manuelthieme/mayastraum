#include <util/geometry/graph.h>
#include <limits>

/* getter */
std::vector<Edge> Graph::edges() const {
    return this->_edges;
}

std::vector<Edge> Graph::edges(const Point p) const {
    std::vector<Edge> ret;
    for(auto e: this->_edges) {
        if(e.begin() != p && e.end() != p)
            continue;
        ret.push_back(e);
    }
    return ret;
}

std::vector<Point> Graph::nodes() const {
    return this->_nodes;
}

std::vector<unsigned> Graph::outgoing_edges(unsigned p) const {
    std::vector<unsigned> ret;
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
void Graph::set_edges(std::vector<Edge> es) {
    this->_edges = es;
}

void Graph::add_edge(Edge e) {
    for (auto edge: this->_edges)
        if (edge == e)
            return;

    this->_edges.push_back(e);
    this->add_node(e.begin());
    this->add_node(e.end());
}

void Graph::add_node(Point p) {
    for (auto n: this->_nodes)
        if (p == n)
            return;

    this->_nodes.push_back(p);
}

void Graph::clear() {
    this->_edges.clear();
    this->_nodes.clear();
}

bool Graph::contains(Point p) const {
    if (std::find(this->_nodes.begin(), this->_nodes.end(), p) != this->_nodes.end()) {
        return true;
    }
    return false;
}

bool Graph::contains(Edge e) const {
    if (std::find(this->_edges.begin(), this->_edges.end(), e) != this->_edges.end()) {
        return true;
    }
    return false;
}

 /* misc */

std::list<Point> Graph::shortest_path(Point source, Point sink) const {
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
    std::list<Point> ret = this->a_star(source_i, sink_i);
    return ret;
}

std::list<Point> Graph::dijkstra(Point source, Point sink) const {
    /* initialize */
    std::list<Point> ret;
    std::map<Point, Point> predecessor;
    std::map<Point, signed int> min_length;
    std::set<Point> q;

    /* check if source and sink are in graph */
    bool source_in = false;
    bool sink_in = false;
    for (auto n: this->_nodes) {
        if (n == source) {
            source_in = true;
            if (sink_in)
                break;
        }
        if (n == sink) {
            sink_in = true;
            if (source_in)
                break;
        }
    }

    if (not (source_in and sink_in))
        return ret;

    /* set length to infinite */
    for (auto n: this->_nodes) {
        Point p;
        for(auto f: this->_nodes)
            if(f == n){
                p = f;
                break;
            }

        min_length[p] = -1;
    }

    /* source length is zero */
    min_length[source] = 0;

    /* source is in queue */
    q.insert(source);



    while (not q.empty()) {
        /* find nearest node in queue */
        Point p;
        bool p_is_set = false;
        for(auto point: q) {
            if(!p_is_set or min_length[point] < min_length[p]) {
                p = point;
                p_is_set = true;
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
            if(min_length[to] == -1) {
                q.insert(to);
                min_length[to] = min_length[p] + e.magnitude();
                predecessor[to] = p;
            }
            /* if length is lower, update length and predecessor */
            else if(min_length[to] > (min_length[p] + e.magnitude())) {
                min_length[to] = min_length[p] + e.magnitude();
            }
        }
    }

    /* make list from predecessors */
    ret.push_front(sink);
    Point to_push = sink;
    while (to_push != source) {
        if(min_length[to_push] == -1)
            break;
        to_push = predecessor[to_push];
        ret.push_front(to_push);
    }
    return ret;
}

std::list<Point> Graph::a_star(int source, int sink) const {
    std::set<unsigned> closed_set;
    std::set<unsigned> open_set;
    open_set.insert(source);

    std::map<unsigned, unsigned> predecessor;

    std::map<unsigned, float> g_score;
    std::map<unsigned, float> f_score;

    for (unsigned i = 0; i < this->_nodes.size(); ++i) {
        g_score.insert({i, numeric_limits<float>::infinity()});
        f_score.insert({i, numeric_limits<float>::infinity()});
    }
    g_score.at(source) = 0;
    f_score.at(source) = this->heuristic_cost_estimate(source, sink);

    while (not open_set.empty()) {
        signed current = -1;
        for (auto n: open_set)
            if (current < 0 or f_score.at(n) < f_score.at(current))
                current = n;

        if (current == sink)
            return this->reconstruct_path(predecessor, sink);

        open_set.erase(current);
        closed_set.insert(current);

        for (auto e: this->outgoing_edges(current)) {
            Point to;
            Edge edge = this->_edges.at(e);

            /* find corresponding node */
            if (edge.begin() == this->_nodes.at(current))
                to = edge.end();
            else
                to = edge.begin();

            signed to_i = this->node_index(to);
            if (to_i < 0)
                break;


            if (closed_set.find(to_i) != closed_set.end())
                continue;

            float tentative_g_score = g_score.at(current) + edge.magnitude();

            if (open_set.find(to_i) == open_set.end())
                open_set.insert(to_i);
            else if (tentative_g_score >= g_score.at(to_i))
                continue;

            predecessor.insert({to_i, current});
            g_score.at(to_i) = tentative_g_score;
            f_score.at(to_i) = g_score.at(to_i) + heuristic_cost_estimate(to_i, sink);
        }
    }
    std::list<Point> ret;
    return ret;
}

float Graph::heuristic_cost_estimate(int start, int end) const {
    return Edge(this->_nodes.at(start), this->_nodes.at(end)).magnitude();
}

std::list<Point> Graph::reconstruct_path(std::map<unsigned, unsigned> predecessor, unsigned sink) const {
    std::list<Point> ret;
    ret.push_front(this->_nodes.at(sink));
    while (predecessor.find(sink) != predecessor.end()) {
        sink = predecessor.at(sink);
        ret.push_front(this->_nodes.at(sink));
    }
    return ret;
}

signed Graph::node_index(Point p) const {
    unsigned i = 0;
    for (auto n: this->_nodes) {
        if (n == p)
            return i;

        ++i;
    }
    return -1;
}
