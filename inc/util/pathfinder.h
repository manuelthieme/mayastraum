#include <models/hitbox.h>
#include <models/screen_object.h>
#include <util/geometry/graph.h>

class Pathfinder {
    Graph _graph;
    Graph _current_graph;
    std::vector<ScreenObject *> _screen_objects;
    bool _initialised = false;

    bool collides_with_screen_objects(const Edge &edge) const;

    bool can_be_added(const Edge &edge, const Graph &graph) const;
  public:
    void init(std::vector<ScreenObject *> screen_objects);

    Graph current_graph() const;

    std::list<Point> shortest_path(Point source, Point sink);
};
