#include "../h/Point.h"

Point::Point(float x, float y): x(x), y(y) {
};

/* getter */
float Point::X() const {
    return this->x;
}

float Point::Y() const {
    return this->y;
}

/* setter */
void Point::setX(float x) {
    this->x = x;
}

void Point::setY(float y) {
    this->y = y;
}

/* operators */
bool Point::operator==(const Point &p) const {
    return this->x == p.x
        && this->y == p.y;
}
