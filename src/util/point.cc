#include <util/point.h>


/* constructor */
Point::Point(float x, float y) {
    this->_point = wykobi::make_vector(x, y);
}

Point::Point(const SDL_GUI::Position &position) {
    this->_point = wykobi::make_vector<float>(position._x, position._y);
}

Point::Point(YAML::Node point_yaml) {
    if (not point_yaml) {
        return;
    }
    float x = point_yaml["x"].as<float>();
    float y = point_yaml["y"].as<float>();
    this->_point = wykobi::make_vector<float>(x, y);
}

/* getter */
float Point::x() const {
    return this->_point[0];
}

float Point::y() const {
    return this->_point[1];
}

float Point::magnitude() const {
    return wykobi::vector_norm(this->_point);
}

wykobi::vector2d<float> Point::vector() const {
    return this->_point;
}

/* setter */
void Point::set_x(float x) {
    this->_point[0] = x;
}

void Point::set_y(float y) {
    this->_point[1] = y;
}

void Point::set_coords(float x, float y) {
    this->_point = wykobi::make_vector(x, y);
}

/* operators */
Point Point::operator+(const Point &p) const {
    return Point(this->_point + p._point);
}

Point Point::operator-(const Point &p) const {
    return Point(this->_point - p._point);
}

Point Point::operator*(const float &s) const {
    return Point(this->_point * s);
}

Point Point::operator/(const float &s) const {
    return Point(this->_point / s);
}

bool Point::operator<(const Point &p) const {
    return (this->magnitude() < p.magnitude());
}

bool Point::operator>(const Point &p) const {
    return (this->magnitude() > p.magnitude());
}


bool Point::operator==(const Point &p) const {
    return this->_point == p._point;
}

bool Point::operator!=(const Point &p) const {
    return not (*this == p);
}

ostream& operator<<(ostream &output, const Point &p) {
    output << "<Point: " << p._point << ">";
    return output;
}

Point Point::operator+=(const Point &p) {
    this->_point = this->_point + p._point;

    return *this;
}

Point Point::operator-=(const Point &p) {
    this->_point = this->_point - p._point;

    return *this;
}

Point Point::operator*=(const float &s) {
    this->_point = this->_point * s;

    return *this;
}

Point Point::operator/=(const float &s) {
    this->_point = this->_point / s;

    return *this;
}

/* misc */
void Point::move_to(Point to, float distance) {
    float max_distance = wykobi::distance(this->_point, to.vector());
    if (max_distance == std::numeric_limits<float>::epsilon()) {
        return;
    }
    if (max_distance < distance) {
        distance = max_distance;
    }
    this->_point = this->_point + (wykobi::normalize(to._point - this->_point) * distance);
}

Point Point::middle(Point p) const {
    Point middle(wykobi::segment_mid_point(this->_point, p._point));
    return middle;
}

YAML::Emitter &operator<<(YAML::Emitter &out, const Point &point) {
    out << YAML::BeginMap;
    out << YAML::Key << "x" << YAML::Value << point.x();
    out << YAML::Key << "y" << YAML::Value << point.y();
    out << YAML::EndMap;
    return out;
}
