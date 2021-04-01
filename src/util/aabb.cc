#include <util/aabb.h>

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

ostream& operator<<(ostream &output, const AABB &aabb) {
    output << "<AABB: " << aabb.position() << " " << aabb.width() << "x" << aabb.height()<< ">";
    return output;
}
