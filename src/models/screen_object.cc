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

enum class HitboxType {
    CIRCLE,
    AABB,
    POLYGON,
    NONE,
};

static const std::map<std::string, HitboxType> TYPE_MAPPING = {
    {"CircleHitbox" , HitboxType::CIRCLE},
    {"AABBHitbox"   , HitboxType::AABB},
    {"PolygonHitbox", HitboxType::POLYGON},
};


ScreenObject::ScreenObject(YAML::Node object_yaml) {
    this->_path   = object_yaml["path"].as<std::string>();
    this->_name   = object_yaml["name"].as<std::string>();
    this->_width  = object_yaml["width"].as<float>();
    this->_height = object_yaml["height"].as<float>();

    this->_position = Point(object_yaml["position"]);

    this->_pivot = Point(object_yaml["pivot"]);

    YAML::Node hitbox_yaml = object_yaml["hitbox"];

    if (hitbox_yaml) {
        std::string type_str = hitbox_yaml["type"].as<std::string>();

        HitboxType type = TYPE_MAPPING.contains(type_str) ? TYPE_MAPPING.at(type_str) : HitboxType::NONE;

        switch(type) {
            case HitboxType::CIRCLE:
                this->_hitbox = new CircleHitbox(hitbox_yaml);
                break;
            case HitboxType::AABB:
                this->_hitbox = new AABBHitbox(hitbox_yaml);
                break;
            case HitboxType::POLYGON:
                this->_hitbox = new PolygonHitbox(hitbox_yaml);
                break;
            case HitboxType::NONE:
                break;
        }
    }
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

const Hitbox *ScreenObject::hitbox() const {
    return this->_hitbox;
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

YAML::Emitter& operator<<(YAML::Emitter &out, const ScreenObject &screen_object) {
    out << YAML::BeginMap;

    out << YAML::Key << "type"<< YAML::Value << "ScreenObject";
    out << YAML::Key << "name" << YAML::Value << screen_object._name;
    out << YAML::Key << "path" << YAML::Value << screen_object.path();

    out << YAML::Key << "position" << YAML::Value;
    out << YAML::BeginMap;
    out << YAML::Key << "x" << screen_object.position().x();
    out << YAML::Key << "y" << screen_object.position().y();
    out << YAML::EndMap;

    out << YAML::Key << "width" << YAML::Value << screen_object.width();
    out << YAML::Key << "height" << YAML::Value << screen_object.height();

    out << YAML::Key << "pivot" << YAML::Value;
    out << YAML::BeginMap;
    out << YAML::Key << "x" << screen_object.pivot().x();
    out << YAML::Key << "y" << screen_object.pivot().y();
    out << YAML::EndMap;

    if (screen_object.hitbox()) {
        out << YAML::Key << "hitbox" << YAML::Value << *screen_object.hitbox();
    }

    return out;
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
