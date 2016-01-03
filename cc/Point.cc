#include "../h/includes.h"

using namespace std;

/* constructor */
Point::Point(float x, float y): m_x(x), m_y(y) {
    this->calcMagnitude();
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

float Point::magnitude() const {
    return this->m_magnitude;
}

/* setter */
void Point::setX(float x) {
    this->m_x = x;
    this->calcMagnitude();
}

void Point::setWidth(float width) {
    this->setX(width);
}

void Point::setY(float y) {
    this->m_y = y;
    this->calcMagnitude();
}

void Point::setHeight(float height) {
    this->setY(height);
}

void Point::setXY(float x, float y) {
    this->m_x = x;
    this->m_y = y;
    this->calcMagnitude();
}

/* operators */
Point Point::operator+(const Point &p) const {
    return Point(this->m_x + p.m_x , this->m_y + p.m_y);
}

Point Point::operator-(const Point &p) const {
    return Point(this->m_x - p.m_x , this->m_y - p.m_y);
}

bool Point::operator==(const Point &p) const {
    return this->m_x == p.m_x
        && this->m_y == p.m_y;
}

ostream& operator<<(ostream &output, const Point &p) {
    output << "(" << p.x() << " | " << p.y() << ")";
    return output;
}

/* misc */
void Point::moveTo(Point to, float speed) {
    Point distance = to - *this;
//  cout << distance.magnitude << " | " << speed << endl;
    if (distance.m_magnitude <= speed) {
        this->m_x = to.m_x;
        this->m_y = to.m_y;
        return;
    }
    Point fak( (distance.m_x > 0) ? 1 : -1 , (distance.m_y > 0) ? 1 : -1 );
	if(!distance.m_y)
		/* Just move in y direction */
        this->m_y = this->m_y + fak.m_y * speed;
	else if(!distance.m_x)
		/* Just move in x direction */
        this->m_x = this->m_x + fak.m_x * speed;
	else
		/* move x and y */
		this->setXY(this->m_x + (float(distance.m_x) / distance.m_magnitude * speed),
				    this->m_y + (float(distance.m_y) / distance.m_magnitude * speed));

}

void Point::calcMagnitude() {
	this->m_magnitude = sqrt(pow(this->m_x, 2) + pow(this->m_y, 2));
}
