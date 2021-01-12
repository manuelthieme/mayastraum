#pragma once

#include <list>
#include <vector>

#include <models/screen_object.h>
#include <util/point.h>

class Character : public ScreenObject {
    /** Target Point. */
    Point _target;

    /** Path to run until reaching the Target. */
    std::list<Point> _path;

    /** running speed of Character. */
    int _speed;

    /** Flag whether the Character is in runningAnimation. */
    bool _running;

public:
    /**
     * Constructor.
     * @param position Point, the Character starts.
     * @param width width
     * @param height height
     * @param speed running speed of Character.
     */
    Character(std::string path, SDL_GUI::Position position, unsigned width, unsigned height, int
              speed = 10);

    /**
     * Get running speed.
     * @return Running Speed.
     */
    int speed() const;

    /**
     * Get Target.
     * @return Target.
     */
    Point target() const;

    /* Get Path.
     * @return Path to run until reaching Target.
     */
    list<Point> path() const;

    /**
     * Get Running Flag.
     * @return Running Flag.
     */
    bool running() const;

    /**
     * Set The Target.
     * Sets The Path and its last Point as Target.
     * @param path List of Points to run until reaching Target.
     */
    void set_target(list<Point> path);

    /**
     * Set Character Speed.
     * @param s Speed.
     */
    void set_speed(int s);

    /**
     * Set Running Flag.
     * @param running Running Flag.
     */
    void set_running(bool running);

    /**
     * Start to run.
     * Sets The Active Animation to the Runing Animation.
     */
    void start_running();

    /**
     * Stop to run.
     * Sets The Active Animation to the First Animation in Animation List. Reset Running Animation.
     */
    void stop_running();

    /**
     * Do repeating tasks.
     * Move if nessessary in next path point direction. Tick current Animation.
     * @param t time.
     */
    void tick(int t = 1);
};


#if 0
#include <memory>
#include <list>

class Character : public ScreenObject {
    /**
     * shortcut to Running Animation.
     */
    shared_ptr<Animation> _runningAnimation;

public:

    /* getter */
    /**
     * Get Running Animation.
     * @return Running Animation.
     */
    shared_ptr<Animation> runningAnimation() const;

    /* setter */
    /**
     * Add a Running Animation.
     * Adds the Animation to the Animation list and overrides the shortcut.
     * @param a Running Animation.
     * @return The shortcut to the Running Animation.
     */
    shared_ptr<Animation> addRunningAnimation(shared_ptr<Animation> a);

    /* misc */
};

#endif
