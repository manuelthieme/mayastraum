#include <util/circle.h>

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

ostream& operator<<(ostream &output, const Circle &circle) {
    output << "<Circle: " << circle.center() << "r=" << circle.radius() << ">";
    return output;
}
