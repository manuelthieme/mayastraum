#include <util/geometry/aabb.h>

AABB::AABB(YAML::Node hitbox_yaml) {
    if (not hitbox_yaml) {
        return;
    }
    this->_position = Point(hitbox_yaml["position"]);
    this->_width = hitbox_yaml["width"].as<float>();
    this->_height = hitbox_yaml["height"].as<float>();
}

wykobi::rectangle<float> AABB::rectangle() const {
    return wykobi::make_rectangle(this->_position.vector(),
                                  wykobi::make_point(this->_width, this->_height));
}

Point AABB::position() const {
    return this->_position;
}

float AABB::width() const {
    return this->_width;
}

float AABB::height() const {
    return this->_height;
}

Point AABB::closest_point(Point point) const {
    Point closest_point
        = wykobi::closest_point_on_rectangle_from_point(this->rectangle(), point.vector());
    return closest_point;
}

void AABB::to_yaml(YAML::Emitter *output) const {
    *output << YAML::BeginMap;
    *output << YAML::Key << "position" << YAML::Value << this->_position;
    *output << YAML::Key << "width" << YAML::Value << this->_width;
    *output << YAML::Key << "height" << YAML::Value << this->_height;
    *output << YAML::EndMap;
}

std::string AABB::to_string() const {
    std::stringstream ss;
    ss << "<AABB: " << this->_position << " " << this->_width << "x" << this->_height<< ">";
    return ss.str();
}
