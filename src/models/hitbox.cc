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

std::list<Edge> CircleHitbox::edges() const {
    return this->_polygon.edges();
}


bool CircleHitbox::collides(Point point) const {
    return wykobi::point_in_circle(point.vector(), this->_circle.circle());
}

bool CircleHitbox::collides(Edge edge) const {
    bool collides = wykobi::intersect(edge.segment(), this->_circle.circle());
    if (not collides) {
        return false;
    }

    bool begin_on_circle = this->_circle.point_on_circle(edge.begin());
    bool end_on_circle = this->_circle.point_on_circle(edge.end());

    unsigned n_edge_collisions = begin_on_circle + end_on_circle;

    /* there is a collision but either both or none of the edge extremes are on */
    if (n_edge_collisions != 1) {
        return true;
    }

    std::vector<Point> collision_points = this->_circle.collision_points(edge);

    /* if more than one collision point (but only one edge extreme on circle) -> collision */
    if (collision_points.size() > 1) {

    }

    return false;
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
    SDL_GUI::Drawable *circle =
        new SDL_GUI::Circle({static_cast<int>(center.x()), static_cast<int>(center.y())},
                            static_cast<unsigned>(this->_circle.radius()));
    circle->_style._color = SDL_GUI::RGB("yellow");
    circle->_style._border_color._a = 150;
    return circle;
}

void CircleHitbox::to_yaml(YAML::Emitter *output) const {
    this->_circle.to_yaml(output);
}


/* AABBHitbox */

std::list<Edge> AABBHitbox::edges() const {
    /* TODO: implement */
    return std::list<Edge>();
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
    this->_aabb.to_yaml(output);
}


/* PolygonHitbox */
PolygonHitbox::PolygonHitbox(YAML::Node hitbox_yaml)
    : Hitbox(HitboxType::POLYGON) {
    if (not hitbox_yaml) {
        return;
    }
    this->_type = HitboxType::POLYGON;
    this->_polygon = Polygon(hitbox_yaml["polygon"]);
}

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

void PolygonHitbox::remove_point(Point &p){
    this->_polygon.remove_point(p);
}

void PolygonHitbox::remove_last_point(){
    this->_polygon.remove_last_point();
}

bool PolygonHitbox::collides(Point point) const {
    return this->_polygon.collides(point);
}

bool PolygonHitbox::collides(Edge edge) const {
    /* there is no collision */
    bool collides = this->_polygon.collides(edge);
    if (not collides) {
        return false;
    }

    /* when middle collides, there is a collision */
    bool middle_collides = this->_polygon.collides(edge.middle());
    if (middle_collides) {
        return true;
    }

    bool begin_on_polygon = this->_polygon.point_on_polygon(edge.begin());
    bool end_on_polygon = this->_polygon.point_on_polygon(edge.end());

    unsigned n_edge_collisions = begin_on_polygon + end_on_polygon;

    /* there is a collision but not at start or beginning */
    if (n_edge_collisions == 0) {
        return true;
    }

    std::vector<Point> collision_points = this->_polygon.collision_points(edge);
    /* there are more than 2 collisions */
    if (collision_points.size() > 2) {
        return true;
    }

    if (collision_points.size() == n_edge_collisions) {
        return false;
    }

    return false;
}

Point PolygonHitbox::closest_point(Point point) const {
    return this->_polygon.closest_point(point);
}

SDL_GUI::Drawable *PolygonHitbox::drawable() const {
    return this->_polygon.drawable();
}

void PolygonHitbox::to_yaml(YAML::Emitter *output) const {
    *output << YAML::BeginMap;
    *output << YAML::Key << "type" << YAML::Value << "PolygonHitbox";
    *output << YAML::Key << "polygon" << this->_polygon;
    *output << YAML::EndMap;
}

std::string PolygonHitbox::to_string() const {
    std::stringstream ss;
    ss << "<Polygon Hitbox: " << this->_polygon << ">";
    return ss.str();
}

