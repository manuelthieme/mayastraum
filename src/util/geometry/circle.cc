#include <util/geometry/circle.h>


Circle::Circle(YAML::Node circle_yaml) {
    if (not circle_yaml) {
        return;
    }
    Point c(circle_yaml["center"]);

    float radius = circle_yaml["radius"].as<float>();

    this->_circle = wykobi::make_circle(c.vector(), radius);
}

wykobi::circle<float> Circle::circle() const {
    return this->_circle;
}

Point Circle::center() const {
    return Point(this->_circle.x, this->_circle.y);
}

float Circle::radius() const {
    return this->_circle.radius;
}

Point Circle::closest_point(Point point) const {
    Point closest_point = wykobi::closest_point_on_circle_from_point(this->_circle, point.vector());

    return closest_point;
}
void Circle::to_yaml(YAML::Emitter *output) const {
    *output << YAML::BeginMap;
    *output << YAML::Key << "center" << YAML::Value << this->center();
    *output << YAML::Key << "radius" << YAML::Value << this->radius();
    *output << YAML::EndMap;
}

std::string Circle::to_string() const {
    std::stringstream ss;
    ss << "<Circle: " << this->center() << "r=" << this->radius() << ">";
    return ss.str();
}
