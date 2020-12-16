#include <util/point.h>


/* constructor */
Point::Point(float x, float y): _x(x), _y(y) {
    this->calcMagnitude();
};

Point::Point(const SDL_GUI::Position &position): _x(position._x), _y(position._y) {
    this->calcMagnitude();
};

/* getter */
float Point::x() const {
    return this->_x;
}

float Point::width() const {
    return this->x();
}

float Point::y() const {
    return this->_y;
}

float Point::height() const {
    return this->y();
}

float Point::magnitude() const {
    return this->_magnitude;
}

/* setter */
void Point::setX(float x) {
    this->_x = x;
    this->calcMagnitude();
}

void Point::setWidth(float width) {
    this->setX(width);
}

void Point::setY(float y) {
    this->_y = y;
    this->calcMagnitude();
}

void Point::setHeight(float height) {
    this->setY(height);
}

void Point::setXY(float x, float y) {
    this->_x = x;
    this->_y = y;
    this->calcMagnitude();
}

/* operators */
Point Point::operator+(const Point &p) const {
    return Point(this->_x + p._x , this->_y + p._y);
}

Point Point::operator-(const Point &p) const {
    return Point(this->_x - p._x , this->_y - p._y);
}

bool Point::operator==(const Point &p) const {
    return (int)this->_x == (int)p._x
        && (int)this->_y == (int)p._y;
}

bool Point::operator!=(const Point &p) const {
    return (int)this->_x != (int)p._x
        || (int)this->_y != (int)p._y;
}

bool Point::operator<(const Point &p) const {
    return (this->magnitude() < p.magnitude());
}

bool Point::operator>(const Point &p) const {
    return (this->magnitude() > p.magnitude());
}

ostream& operator<<(ostream &output, const Point &p) {
    output << "(" << p.x() << " | " << p.y() << ")";
    return output;
}

Point Point::operator+=(const Point &p) {
    this->_x += p._x;
    this->_y += p._y;

    return *this;
}

/* misc */
void Point::moveTo(Point to, float speed) {
    Point distance = to - *this;
//  cout << distance.magnitude << " | " << speed << endl;
    if (distance._magnitude <= speed) {
        this->_x = to._x;
        this->_y = to._y;
        return;
    }
    Point fak( (distance._x > 0) ? 1 : -1 , (distance._y > 0) ? 1 : -1 );
    if(!distance._y)
        /* Just move in y direction */
        this->_y = this->_y + fak._y * speed;
    else if(!distance._x)
        /* Just move in x direction */
        this->_x = this->_x + fak._x * speed;
    else
        /* move x and y */
        this->setXY(this->_x + (float(distance._x) / distance._magnitude * speed),
                    this->_y + (float(distance._y) / distance._magnitude * speed));

}

void Point::calcMagnitude() {
    this->_magnitude = sqrt(pow(this->_x, 2) + pow(this->_y, 2));
}

Point Point::middle(Point p) const {
    Point middle = p + Point((this->_x - p._x) / 2, (this->_y - p._y) / 2);
    return middle;
}
