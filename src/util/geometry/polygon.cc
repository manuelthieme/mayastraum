#include <util/geometry/polygon.h>

#include <sstream>

#include <SDL_GUI/gui/primitives/line.h>
#include <SDL_GUI/gui/primitives/wrap_rect.h>

Polygon::Polygon(YAML::Node polygon_yaml) {
    if (not polygon_yaml) {
        return;
    }
    for (auto point: polygon_yaml["points"]) {
        this->_points.emplace_back(point);
    }
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
}

void Polygon::add_point(Point point) {
    this->_points.push_back(point);
}

void Polygon::remove_point(Point &point) {
    this->_points.remove(point);
}

void Polygon::remove_last_point() {
    this->_points.pop_back();
}

bool Polygon::collides(Point point) const {
    return wykobi::point_in_polygon(point.vector(), this->polygon());
}

bool Polygon::collides(Edge edge) const {
    /* for some reason, wyokbi has not implemented the intersection of a segment and a polygon.
     * So we do it ourselfs. */
    wykobi::polygon<float, 2> polygon = this->polygon();
    unsigned j = polygon.size() - 1;
    for (unsigned i = 0; i < polygon.size(); ++i) {
        if (wykobi::intersect(edge.segment(), wykobi::make_segment(polygon[i], polygon[j]))) {
            return true;
        }
    }
    return false;
}

Point Polygon::closest_point(Point point) const {
    return wykobi::closest_point_on_polygon_from_point(this->polygon(), point.vector());
}

SDL_GUI::Drawable *Polygon::drawable() const {
    SDL_GUI::WrapRect *wrapper = new SDL_GUI::WrapRect();
    for (Edge edge: this->edges()) {
        SDL_GUI::Line *l = new SDL_GUI::Line(edge.begin().position(), edge.end().position());
        l->set_line_width(3);
        l->_style._color = SDL_GUI::RGB("yellow");
        wrapper->add_child(l);
    }
    return wrapper;
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
