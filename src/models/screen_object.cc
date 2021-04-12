#include <models/screen_object.h>

ScreenObject::ScreenObject(std::string path): _path(path) {
    this->init();
}

ScreenObject::ScreenObject(std::string path, Point position, unsigned width, unsigned height):
    _path(path),
    _position(position),
    _width(width),
    _height(height) {
    this->init();
}

void ScreenObject::deserialise_box(YAML::Node hitbox_yaml, bool hover_box) {
    if (not hitbox_yaml) {
        return;
    }

    std::string type_str = hitbox_yaml["type"].as<std::string>();

    HitboxType type = HITBOX_TYPE_MAPPING.contains(type_str)
                      ? HITBOX_TYPE_MAPPING.at(type_str)
                      : HitboxType::NONE;
    Hitbox **box = hover_box ? &this->_hover_box : &this->_hitbox;
    PolygonHitbox **poly_box = hover_box ? &this->_polygon_hover_box : &this->_polygon_hitbox;

    switch(type) {
        case HitboxType::CIRCLE:
            *box = new CircleHitbox(hitbox_yaml);
            break;
        case HitboxType::AABB:
            *box = new AABBHitbox(hitbox_yaml);
            break;
        case HitboxType::POLYGON:
            *poly_box = new PolygonHitbox(hitbox_yaml);
            *box = *poly_box;
            break;
        case HitboxType::NONE:
            break;
    }
}


ScreenObject::ScreenObject(YAML::Node object_yaml) {
    this->_path   = object_yaml["path"].as<std::string>();
    this->_name   = object_yaml["name"].as<std::string>();
    this->_width  = object_yaml["width"].as<float>();
    this->_height = object_yaml["height"].as<float>();

    this->_position = Point(object_yaml["position"]);

    this->_pivot = Point(object_yaml["pivot"]);

    this->deserialise_box(object_yaml["hitbox"]);
    this->deserialise_box(object_yaml["hover_box"], true);
}

ScreenObject::~ScreenObject() {
    if (this->_hitbox) {
        delete this->_hitbox;
    }
}

void ScreenObject::init() {

}

std::string ScreenObject::path() const {
    return this->_path;
}

Point ScreenObject::position() const {
    return this->_position;
}

Point ScreenObject::pivot() const {
    return this->_pivot;
}

unsigned ScreenObject::width() const {
    return this->_width;
}

unsigned ScreenObject::height() const {
    return this->_height;
}

Hitbox *ScreenObject::hitbox() {
    return this->_hitbox;
}

const Hitbox *ScreenObject::hitbox() const {
    return this->_hitbox;
}

Hitbox *ScreenObject::hover_box() {
    return this->_hover_box;
}

const Hitbox *ScreenObject::hover_box() const {
    return this->_hover_box;
}


PolygonHitbox *ScreenObject::polygon_hitbox() {
    return this->_polygon_hitbox;
}

const PolygonHitbox *ScreenObject::polygon_hitbox() const {
    return this->_polygon_hitbox;
}

PolygonHitbox *ScreenObject::polygon_hover_box() {
    return this->_polygon_hover_box;
}

const PolygonHitbox *ScreenObject::polygon_hover_box() const {
    return this->_polygon_hover_box;
}


void ScreenObject::set_position(Point position) {
    this->_position = position;
}

void ScreenObject::set_pivot(Point pivot) {
    this->_pivot = pivot;
}

void ScreenObject::set_width(unsigned width) {
    this->_width = width;
}

void ScreenObject::set_height(unsigned height) {
    this->_height = height;
}

void ScreenObject::set_size(unsigned width, unsigned height) {
    this->set_width(width);
    this->set_height(height);
}

void ScreenObject::set_hitbox(Hitbox *hitbox) {
    this->_hitbox = hitbox;
}

void ScreenObject::set_hitbox(PolygonHitbox *hitbox) {
    this->_polygon_hitbox = hitbox;
    this->_hitbox = hitbox;
}

void ScreenObject::set_hover_box(Hitbox *hover_box) {
    this->_hover_box = hover_box;
}

void ScreenObject::set_hover_box(PolygonHitbox *hover_box) {
    this->_polygon_hover_box = hover_box;
    this->_hover_box = hover_box;
}

void ScreenObject::move(Point movement) {
    this->_position += movement;
}


bool ScreenObject::collides(Point point) const {
    return this->_hitbox->collides(point - this->_position);

}

bool ScreenObject::collides(Edge edge) const {
    return this->_hitbox->collides(edge - this->_position);

}

Point ScreenObject::closest_point(Point point) const {
    return this->_hitbox->closest_point(point);
}

std::string ScreenObject::serialise() const {
    YAML::Emitter out;
    out << *this;
    return out.c_str();
}

void ScreenObject::to_yaml (YAML::Emitter *output) const {
    *output << YAML::BeginMap;
    this->_to_yaml(output);
    *output << YAML::EndMap;
}

void ScreenObject::_to_yaml (YAML::Emitter *output) const {
    *output << YAML::Key << "type"<< YAML::Value << this->_type;
    *output << YAML::Key << "name" << YAML::Value << this->_name;
    *output << YAML::Key << "path" << YAML::Value << this->path();

    *output << YAML::Key << "position" << YAML::Value;
    *output << YAML::BeginMap;
    *output << YAML::Key << "x" << this->position().x();
    *output << YAML::Key << "y" << this->position().y();
    *output << YAML::EndMap;

    *output << YAML::Key << "width" << YAML::Value << this->width();
    *output << YAML::Key << "height" << YAML::Value << this->height();

    *output << YAML::Key << "pivot" << YAML::Value;
    *output << YAML::BeginMap;
    *output << YAML::Key << "x" << this->pivot().x();
    *output << YAML::Key << "y" << this->pivot().y();
    *output << YAML::EndMap;

    if (this->hitbox()) {
        *output << YAML::Key << "hitbox" << YAML::Value << *this->hitbox();
    }

    if (this->hover_box()) {
        *output << YAML::Key << "hover_box" << YAML::Value << *this->hover_box();
    }
}

#if 0
#include <includes.h>

/* constructor */
ScreenObject::ScreenObject(Point position, Point size, Point pivot, Hitbox hitbox, vector<shared_ptr<Animation>> animations) : m_size(size), m_pivot(pivot), m_hitbox(hitbox), m_position(position), m_animations(animations) {
    if (this->m_animations.size() > 0)
        this->m_activeAnimation = this->m_animations[0];
}

/* getter */

Point ScreenObject::size() const {
    return this->m_size;
}

Point ScreenObject::renderSize(shared_ptr<Screen> s, float gameHeight) const {
    float factor = (this->m_position.y() / gameHeight) * (1 - s->sizeFactor()) + s->sizeFactor();
    return Point(this->m_size.width() * factor, this->m_size.height() * factor);
}


Hitbox ScreenObject::renderHitbox(shared_ptr<Screen> s, float gameHeight) const {
    Hitbox h;
    float factor = (this->m_position.y() / gameHeight) * (1 - s->sizeFactor()) + s->sizeFactor();
    for (auto p: this->m_hitbox.points()) {
        Point tmp(p.width() * factor, p.height() * factor);
        h.addPoint(tmp);
    }
    h.calculateEdges();
    return h;
}
shared_ptr<Animation> ScreenObject::activeAnimation() const {
    return this->m_activeAnimation;
}


/* setter */
void ScreenObject::setPosition(Point p) {
    this->m_position = p;
}

void ScreenObject::setSize(Point p) {
    this->m_size = p;
}

void ScreenObject::setPivot(Point p) {
    this->m_pivot = p;
}

shared_ptr<Animation> ScreenObject::addAnimation(shared_ptr<Animation> a) {
    this->m_animations.push_back(a);
    return this->m_animations.back();
}

bool ScreenObject::setActiveAnimation(shared_ptr<Animation> a) {
    bool success = false;
    for (auto animation: this->m_animations)
        if (animation == a) {
            this->m_activeAnimation = animation;
            success = true;
            break;
        }

    return success;
}


/* operators */
bool ScreenObject::operator==(const ScreenObject &s) const {
    return this->m_position == s.m_position
        && this->m_hitbox == s.m_hitbox
        && this->m_animations == s.m_animations;
}

bool ScreenObject::greaterThan(shared_ptr<ScreenObject> a, shared_ptr<ScreenObject> b) {
    return (a->position().y() < b->position().y());
}

/* misc */
void ScreenObject::tick(int t, shared_ptr<Screen> activeScreen, int gameHeight) {
    this->m_activeAnimation->tick(t);
}

#endif
