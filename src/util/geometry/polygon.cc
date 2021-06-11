#include <util/geometry/polygon.h>


#include <sstream>

#include <SDL_GUI/gui/primitives/line.h>
#include <SDL_GUI/gui/primitives/wrap_rect.h>

#include <util/geometry/circle.h>

Polygon::Polygon() {
    this->init();
}

Polygon::Polygon(Circle circle) {
    Point center = circle.center();
    float radius = circle.radius();

    this->_points.emplace_back(center + Point{-radius, -radius});
    this->_points.emplace_back(center + Point{-radius,  radius});
    this->_points.emplace_back(center + Point{ radius, -radius});
    this->_points.emplace_back(center + Point{ radius,  radius});
    this->init();
}

Polygon::Polygon(YAML::Node polygon_yaml) {
    if (not polygon_yaml) {
        return;
    }
    for (auto point: polygon_yaml["points"]) {
        this->_points.emplace_back(point);
    }
    this->init();
}

void Polygon::init() {
    this->_gui_polygon = new SDL_GUI::Polygon();
    for (const Point &point: this->_points) {
        this->_gui_polygon->add_point(point.position());
    }
    this->_gui_polygon->_style._has_border = true;
    this->_gui_polygon->_style._border_color = SDL_GUI::RGB("yellow");
    this->_gui_polygon->_style._border_color._a = 150;
    this->_gui_polygon->set_line_width(3);
}


std::list<Point> &Polygon::points() {
    return this->_points;
}

std::list<Point> Polygon::points() const {
    return this->_points;
}

std::list<Edge> Polygon::edges() const {
    std::list<Edge> edges;
    if (this->_points.empty()) {
        return edges;
    }
    Point begin = this->_points.back();
    for (Point end: this->_points) {
        edges.emplace_back(begin, end);
        begin = end;
    }
    return edges;
}

wykobi::polygon<float, 2> Polygon::polygon() const {
    wykobi::polygon<float, 2> polygon;

    for (const Point &point: this->_points) {
        polygon.push_back(point.vector());
    }

    return polygon;
}

void Polygon::set_points(std::list<Point> points) {
    this->_points = points;
    for (const Point &point: this->_points) {
        this->_gui_polygon->add_point(point.position());
    }
}

void Polygon::add_point(Point point) {
    this->_points.push_back(point);
    this->_gui_polygon->add_point(point.position());
}

void Polygon::remove_point(Point &point) {
    this->_points.remove(point);
    /* TODO: implement */
}

void Polygon::remove_last_point() {
    this->_points.pop_back();
    this->_gui_polygon->remove_last_point();
}

bool Polygon::collides(Point point) const {
    return wykobi::point_in_polygon(point.vector(), this->polygon())
        and not wykobi::point_on_polygon_edge(point.vector(), this->polygon());
}

bool Polygon::collides(Edge edge) const {
    /* for some reason, wyokbi has not implemented the intersection of a segment and a polygon.
     * So we do it ourselfs. */
    wykobi::polygon<float, 2> polygon = this->polygon();
    unsigned j = polygon.size() - 1;
    for (unsigned i = 0; i < polygon.size(); ++i) {
        /* check if edge intersects polygon part */
        if (wykobi::intersect(edge.segment(), wykobi::make_segment(polygon[i], polygon[j]))) {
            return true;
        }
        j = i;
    }
    return false;
}

std::vector<Point> Polygon::collision_points(Edge edge) const {
    std::vector<Point> collision_points;
    wykobi::polygon<float, 2> polygon = this->polygon();
    unsigned j = polygon.size() - 1;
    for (unsigned i = 0; i < polygon.size(); ++i) {
        wykobi::segment<float,2> polygon_segment = wykobi::make_segment(polygon[i], polygon[j]);
        /* check if edge intersects polygon part */
        if (wykobi::intersect(edge.segment(), polygon_segment)) {
            Point point{wykobi::intersection_point(edge.segment(), polygon_segment)};
            collision_points.push_back(point);
        }
        j = i;
    }
    return collision_points;
}

Point Polygon::closest_point(Point point) const {
    wykobi::polygon<float, 2> polygon = this->polygon();
    Point closest{wykobi::closest_point_on_polygon_from_point(polygon, point.vector())};
    if (wykobi::point_on_polygon_edge(closest.vector(), polygon)) {
        return closest;
    }
    /* for some reason, wyokbi has not implemented the closest point on a polygon edge.
     * So we do it ourselfs. */
    unsigned j = polygon.size() - 1;
    Point best_closest;
    float best_distance;
    for (unsigned i = 0; i < polygon.size(); ++i) {
        wykobi::segment<float,2> polygon_segment = wykobi::make_segment(polygon[i], polygon[j]);
        Point closest{wykobi::closest_point_on_segment_from_point(polygon_segment, point.vector())};
        float distance = point.distance(closest);
        if (i == 0 or distance < best_distance) {
            best_closest = closest;
            best_distance = distance;
        }
        j = i;
    }
    return best_closest;
}

bool Polygon::point_on_polygon(Point point) const {
    return wykobi::point_on_polygon_edge(point.vector(), this->polygon());
}

SDL_GUI::Drawable *Polygon::drawable() const {
    return this->_gui_polygon;
}

std::string Polygon::to_string() const {
    std::stringstream ss;
    ss << "<Polygon: ";
    bool first = true;
    for (const Point &point: this->_points) {
        if (not first) {
            ss << " ,";
        }
        ss << point;
    }
    ss << ">" << std::endl;
    return ss.str();
}

void Polygon::to_yaml(YAML::Emitter *output) const {
    *output << YAML::BeginMap;
    *output << YAML::Key << "points" << YAML::Value << this->_points;
    *output << YAML::EndMap;
}
