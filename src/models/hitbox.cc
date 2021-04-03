#include <models/hitbox.h>

#include <sstream>

#include <SDL_GUI/gui/primitives/circle.h>

ostream& operator<<(ostream &output, const Hitbox &hitbox) {
    output << hitbox.to_string();
    return output;
}


/* CircleHitbox */

bool CircleHitbox::collides(Point point) const {
    return wykobi::point_in_circle(point.vector(), this->_circle.circle());
}

bool CircleHitbox::collides(Edge edge) const {
    return wykobi::intersect(edge.segment(), this->_circle.circle());
}

Point CircleHitbox::closest_point(Point point) const {
    return this->_circle.closest_point(point);
}

std::string CircleHitbox::to_string() const {
    std::stringstream ss;
    ss << "<CircleHitbox: " << this->_circle << ">";
    return ss.str();
}

SDL_GUI::Drawable *CircleHitbox::drawable() const {
    Point center = this->_circle.center();
    return new SDL_GUI::Circle({static_cast<int>(center.x()), static_cast<int>(center.y())},
                               static_cast<unsigned>(this->_circle.radius()));
}

void CircleHitbox::to_yaml(ryml::NodeRef *node) const {
    ryml::NodeRef &n = *node;
    n["type"] = "CircleHitbox";

    ryml::NodeRef center = n["center"];
    center |= ryml::MAP;
    center["x"] << this->_circle.center().x();
    center["y"] << this->_circle.center().y();

    n["radius"] << this->_circle.radius();
}


/* AABBHitbox */

bool AABBHitbox::collides(Point point) const {
    return wykobi::point_in_rectangle(point.vector(), this->_aabb.rectangle());
}

bool AABBHitbox::collides(Edge edge) const {
    return wykobi::intersect(edge.segment(), this->_aabb.rectangle());
}

Point AABBHitbox::closest_point(Point point) const {
    return this->_aabb.closest_point(point);
}

std::string AABBHitbox::to_string() const {
    std::stringstream ss;
    ss << "<AABBHitbox: " << this->_aabb << ">";
    return ss.str();
}

SDL_GUI::Drawable *AABBHitbox::drawable() const {
    return new SDL_GUI::NullDrawable();
}

void AABBHitbox::to_yaml(ryml::NodeRef *node) const {
    (void)node;
}


/* PolygonHitbox */

vector<Point> PolygonHitbox::points() const {
    return this->_points;
}

vector<Edge> PolygonHitbox::edges() const {
    return this->_edges;
}

Point PolygonHitbox::off_point() const {
    if (this->_points.size() < 1)
        return Point(0, 0);
    Point point = this->_points.front();
    for (auto p: this->_points) {
        if (p.x() < point.x())
            point.set_x(p.x());

        if (p.y() < point.y())
            point.set_y(p.y());

    }
    return point + Point(-1, -1);
}

void PolygonHitbox::set_points(vector<Point> points) {
    this->_points = points;
}

void PolygonHitbox::add_point(Point point) {
    this->_points.push_back(point);
}

void PolygonHitbox::set_edges(vector<Edge> edges) {
    this->_edges = edges;
}
void PolygonHitbox::add_edge(Edge edge) {
    this->_edges.push_back(edge);
}

std::string PolygonHitbox::to_string() const {
    std::stringstream ss;
    ss << "<Polygon Hitbox: ";
    bool first = true;
    for (const Edge &edge: this->_edges) {
        if (not first) {
            ss << " ,";
        }
        ss << edge;
    }
    ss << ">" << std::endl;
    return ss.str();
}



void PolygonHitbox::calculate_edges() {
    if (this->_points.size() < 1)
        return;
    this->_edges.clear();
    Point before(0, 0);
    bool first = false;
    for (const Point &point: this->_points) {
        if (!first) {
            first = true;
            before = point;
            continue;
        }
        Edge edge(before, point);
        this->_edges.push_back(edge);
        before = point;
    }
    Edge edge(before, this->_points.front());
    this->_edges.push_back(edge);
}

bool PolygonHitbox::collides(Point point) const {
    /* a point collides with the hitbox when the edge from a point outside the hitbox to the checked
     * point collides with an even number of hitbox edges */
    Point off_point = this->off_point();
    int count = 0;
    for (const Edge &edge: this->_edges) {
        if ((edge).intersects(Edge(point, off_point))) {
            count++;
        }
    }

    if (count % 2) {
        return true;
    }

    return false;
}

bool PolygonHitbox::collides(Edge edge) const {
    /* check whether the Edge intersects one of the hitbox edges */
    for (const Edge &e: this->_edges) {
        if (e.intersects(edge)) {
            /* TODO: what is this? */
            //if(this->collides(edge.middle(), activeScreen, gameHeight))
            return true;
        }
    }
    return false;
}

Point PolygonHitbox::closest_point(Point point) const {
    /* TODO: implement */
    return point;
}

SDL_GUI::Drawable *PolygonHitbox::drawable() const {
    return new SDL_GUI::NullDrawable();
}

void PolygonHitbox::to_yaml(ryml::NodeRef *node) const {
    (void)node;
}
