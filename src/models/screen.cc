#include <models/screen.h>

Screen::Screen(std::string path, const GameModel *game_model)
    : ScreenObject(path, {0,0}, 1920, 1080), _game_model(game_model) {
    this->_type = "Screen";
}

Screen::Screen(YAML::Node screen_yaml, const GameModel *game_model)
    : ScreenObject(screen_yaml), _game_model(game_model) {
    std::vector<Hitbox *> hitboxes;
    for (auto object_path: screen_yaml["screen_objects"]) {
        YAML::Node object_yaml = YAML::LoadFile(object_path.as<std::string>());
        ScreenObject *object = new ScreenObject(object_yaml);
        this->add_screen_object(object);
        hitboxes.push_back(object->hitbox());
    }
    std::vector<ScreenObject *> screen_objects(this->_screen_objects);

    screen_objects.push_back(this);
    this->_pathfinder.init(screen_objects);
}

std::string Screen::background_path() const {
    return this->_path;
}

std::vector<ScreenObject *> Screen::screen_objects() {
    return this->_screen_objects;
}

const GameModel *Screen::game_model() const {
    return this->_game_model;
}

Pathfinder &Screen::pathfinder() {
    return this->_pathfinder;
}

void Screen::add_screen_object(ScreenObject *screen_object) {
    this->_screen_objects.push_back(screen_object);
}

void Screen::_to_yaml (YAML::Emitter *output) const {
    ScreenObject::_to_yaml(output);
    *output << YAML::Key << "screen_objects" << YAML::Value;
    *output << YAML::BeginSeq;
    for (ScreenObject *screen_object: this->_screen_objects) {
        std::stringstream ss;
        ss << "data/" << screen_object->_name << ".yml";
        *output << ss.str();
    }
    *output << YAML::EndSeq;
}
#if 0
#include <includes.h>

using namespace std;
/* constructor */
Screen::Screen(vector<shared_ptr<ScreenObject>> objects, string backgroundPath, float sizeFactor) : m_objects(objects), m_backgroundPath(backgroundPath), m_sizeFactor(sizeFactor){
}

/* getter */
vector<shared_ptr<ScreenObject>> Screen::objects() const {
    return this->m_objects;
}

string Screen::backgroundPath() const {
    return this->m_backgroundPath;
}

Hitbox Screen::hitbox() const {
    return this->m_hitbox;
}
float Screen::sizeFactor() const {
    return this->m_sizeFactor;
}

/* setter */
shared_ptr<ScreenObject> Screen::addScreenObject(shared_ptr<ScreenObject> screenObject) {
    this->m_objects.push_back(screenObject);
    return this->m_objects.back();
}

shared_ptr<Character> Screen::addPlayer(shared_ptr<Character> c) {
    shared_ptr<ScreenObject> s = this->addScreenObject(c);
    return static_pointer_cast<Character>(s);
}

void Screen::setHitbox(Hitbox h) {
    this->m_hitbox = h;
}

void Screen::setSizeFactor(float s) {
    this->m_sizeFactor = s;
}

/* operators */
bool Screen::operator==(const Screen &s) const {
    return this->m_objects == s.m_objects;
}

/* misc */

void Screen::sortScreenObjects() {
    sort(this->m_objects.begin(), this->m_objects.end(), ScreenObject::greaterThan);
}

bool Screen::collides(Edge e) const {
    for (auto edge: this->m_hitbox.edges())
        if (edge.intersects(e))
                return true;

    return false;
}

bool Screen::collides(Point p) const {
    Point offPoint = this->m_hitbox.offPoint();
    int count = 0;
    for (auto e: this->m_hitbox.edges())
        if (e.intersects(Edge(p, offPoint)))
            count++;

    if (count % 2)
        return true;

    return false;
}

#endif
