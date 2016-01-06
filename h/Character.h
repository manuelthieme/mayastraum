#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>
#include <list>

#if 0
#include "ScreenObject.h"
#include "Point.h"
#endif

class Character : public ScreenObject {
    bool m_running;
    shared_ptr<Animation> m_runningAnimation;
    Point m_target;
    list<Point> m_path;
    int m_speed;

public:
    /* constructor */
    Character(Point position, Point size, Point pivot, Hitbox hitbox, vector<shared_ptr<Animation>> animations, int speed = 10);

    /* getter */
    bool running() const;
    shared_ptr<Animation> runningAnimation() const;
    int speed() const;
    Point target() const;
    list<Point> path() const;

    /* setter */
    void setRunning(bool running);
    shared_ptr<Animation> addRunningAnimation(shared_ptr<Animation> a);
    void setTarget(list<Point> path);
    void setSpeed(int s);

    /* misc */
    void startRunning();
    void stopRunning();
    void tick(int t, shared_ptr<Screen> activeScreen, int gameHeight);
};

#endif /* CHARACTER_H */
