#include <models/hitbox.h>

#include <sstream>

#include <SDL_GUI/gui/primitives/circle.h>

ostream& operator<<(ostream &output, const Hitbox &hitbox) {
    output << hitbox.to_string();
    return output;
}

YAML::Emitter &operator<<(YAML::Emitter &out, const Hitbox &hitbox) {
    hitbox.to_yaml(&out);
    return out;
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

void CircleHitbox::to_yaml(YAML::Emitter *output) const {
    this->_circle.to_yaml(output);
}


/* AABBHitbox */
AABBHitbox::AABBHitbox(YAML::Node hitbox_yaml) {
    /* TODO: implement */
}


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

void AABBHitbox::to_yaml(YAML::Emitter *output) const {
    (void)output;
}


/* PolygonHitbox */
std::list<Point> PolygonHitbox::points() const {
    return this->_polygon.points();
}

std::list<Edge> PolygonHitbox::edges() const {
    return this->_polygon.edges();
}

void PolygonHitbox::set_points(std::list<Point> points) {
    this->_polygon.set_points(points);
}

void PolygonHitbox::add_point(Point point) {
    this->_polygon.add_point(point);
}

bool PolygonHitbox::collides(Point point) const {
    return this->_polygon.collides(point);
}

bool PolygonHitbox::collides(Edge edge) const {
    return this->_polygon.collides(edge);
}

Point PolygonHitbox::closest_point(Point point) const {
    return this->_polygon.closest_point(point);
}

SDL_GUI::Drawable *PolygonHitbox::drawable() const {
    return this->_polygon.drawable();
}

void PolygonHitbox::to_yaml(YAML::Emitter *output) const {
    *output << this->_polygon;
}

std::string PolygonHitbox::to_string() const {
    std::stringstream ss;
    ss << "<Polygon Hitbox: " << this->_polygon << ">";
    return ss.str();
}

