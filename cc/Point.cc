#include "../h/Point.h"

Point::Point(float x, float y): m_x(x), m_y(y) {
};

/* getter */
float Point::x() const {
    return this->m_x;
}

float Point::width() const {
    return this->x();
}

float Point::y() const {
    return this->m_y;
}

float Point::height() const {
    return this->y();
}


/* setter */
void Point::setX(float x) {
    this->m_x = x;
}

void Point::setWidth(float width) {
    this->setX(width);
}

void Point::setY(float y) {
    this->m_y = y;
}

void Point::setHeight(float height) {
    this->setY(height);
}

/* operators */
bool Point::operator==(const Point &p) const {
    return this->m_x == p.m_x
        && this->m_y == p.m_y;
}
