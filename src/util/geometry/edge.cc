#include <util/geometry/edge.h>

Point Edge::begin() const {
    return this->_begin;
}

Point Edge::end() const {
    return this->_end;
}

float Edge::slope() const {
    return (this->_begin.y() - this->_end.y()) / (this->_begin.x() - this->_end.x());
}

float Edge::magnitude() const {
    return (this->_end - this->_begin).magnitude();
}

wykobi::segment<float,2> Edge::segment() const {
    return wykobi::make_segment(this->_begin.vector(), this->_end.vector());
}

void Edge::set_begin(Point begin) {
    this->_begin = begin;
}

void Edge::set_end(Point end) {
    this->_end = end;
}

void Edge::set_magnitude(float magnitude) {
    float scale = this->magnitude() / magnitude;
    this->scale(scale);
}

void Edge::scale(float scale) {
    this->_end += (this->_end - this->_begin) * (1 - scale);
}


bool Edge::operator==(const Edge &edge) const{
    return this->_begin == edge._begin and this->_end == edge._end;
}

Edge Edge::operator+(const Point &point) const {
    return Edge(this->_begin + point, this->_end + point);
}

Edge Edge::operator+=(const Point &point) {
    this->_begin += point;
    this->_end += point;

    return *this;
}

Edge Edge::operator-(const Point &point) const {
    return Edge(this->_begin - point, this->_end - point);
}

Edge Edge::operator-=(const Point &point) {
    this->_begin -= point;
    this->_end -= point;

    return *this;
}

Point Edge::intersection(Edge edge) const {
    wykobi::point2d<float> intersection = wykobi::intersection_point(this->segment(), edge.segment());

    return intersection;
}

bool Edge::intersects(Edge edge) const {
    return wykobi::intersect(this->segment(), edge.segment());
}

Point Edge::middle() const {
    return this->_begin.middle(this->_end);
}

Point Edge::closest_point(Point point) const {
    wykobi::point2d<float> closest_point =
        wykobi::closest_point_on_segment_from_point(this->segment(), point.vector());

    return closest_point;
}

void Edge::to_yaml(YAML::Emitter *output) const {
    *output << YAML::BeginMap;
    *output << YAML::Key << "begin" << YAML::Value << this->_begin;
    *output << YAML::Key << "end"   << YAML::Value << this->_end;
    *output << YAML::EndMap;
}

std::string Edge::to_string() const {
    std::stringstream ss;
    ss << "<Edge: " << this->_begin << "---" << this->_end << ">";
    return ss.str();
}
