#include <util/pathfinder.h>

bool Pathfinder::collides_with_screen_objects(const Edge &edge) const {
    for (ScreenObject* screen_object: this->_screen_objects) {
        if (screen_object->collides(edge)) {
            return true;
        }
    }

    return false;
}

bool Pathfinder::can_be_added(const Edge &edge, const Graph &graph) const {
    /* no edge at all */
    if (edge.begin() == edge.end()) {
        return false;
    }
    /* edge already in graph */
    if (graph.contains(edge)) {
        return false;
    }
    /* edge collides with a hitbox */
    return not this->collides_with_screen_objects(edge);
}

void Pathfinder::init(std::vector<ScreenObject *> screen_objects) {
    this->_screen_objects = screen_objects;
    /* add hitboxes to graph */
    for (ScreenObject *screen_object: this->_screen_objects) {
        Point position = screen_object->position() - screen_object->pivot();
        for (Edge edge: screen_object->hitbox()->edges()) {
            this->_graph.add_edge(edge + position);
        }
    }

    /* Add all possible edges between hitboxes to graph */
    for (Point from: this->_graph.nodes()) {
        for (Point to: this->_graph.nodes()) {
            Edge edge(from, to);
            if (not can_be_added(edge, this->_graph)) {
                continue;
            }
            this->_graph.add_edge(edge);
        }
    }

    this->_current_graph = this->_graph;
    this->_initialised = true;
}

Graph Pathfinder::current_graph() const {
    return this->_current_graph;
}

std::list<Point> Pathfinder::shortest_path(Point begin, Point end) {
    this->_current_graph = this->_graph;

    /* adjust end if necessary */
    for (ScreenObject *screen_object: this->_screen_objects) {
        if (screen_object->collides(end)) {
            end = screen_object->closest_point(end) + screen_object->position() - screen_object->pivot();
        }
    }

    /* direct path is possible */
    Edge direct(begin, end);
    if (this->can_be_added(direct, this->_graph)) {
        this->_current_graph.add_edge(direct);
        return {end};
    }

    /* Try to add edges from begin and end to every node in graph */
    for (Point to: this->_graph.nodes()) {
        Edge e1(begin, to);
        if (this->can_be_added(e1, this->_current_graph)) {
            this->_current_graph.add_edge(e1);
        }
        Edge e2(end, to);
        if (this->can_be_added(e2, this->_current_graph)) {
            this->_current_graph.add_edge(e2);
        }
    }
    std::list<Point> path = this->_current_graph.shortest_path(begin, end);
    return path;
}
