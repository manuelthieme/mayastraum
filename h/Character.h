#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>
#include <list>

class Character : public ScreenObject {
    /**
     * Flag whether the Character is in runningAnimation.
     */
    bool m_running;
    /**
     * shortcut to Running Animation.
     */
    shared_ptr<Animation> m_runningAnimation;
    /**
     * Target Point.
     */
    Point m_target;
    /**
     * Path to run until reaching the Target.
     */
    list<Point> m_path;
    /**
     *  running speed of Character.
     */
    int m_speed;

public:
    /* constructor */
    /**
     * Constructor.
     * \param position Point, the Character starts.
     * \param size Size of the Character.
     * \param pivot Relative position of Pivot Point.
     * \param hitbox Hitbox of the Character.
     * \param animations A list of Animations.
     * \param speed running speed of Character.
     */
    Character(Point position, Point size, Point pivot, Hitbox hitbox, vector<shared_ptr<Animation>> animations, int speed = 10);

    /* getter */
    /**
     * Get Running Flag.
     * \return Running Flag.
     */
    bool running() const;
    /**
     * Get Running Animation.
     * \return Running Animation.
     */
    shared_ptr<Animation> runningAnimation() const;
    /**
     * Get running speed.
     * \return Running Speed.
     */
    int speed() const;
    /**
     * Get Target.
     * \return Target.
     */
    Point target() const;
    /* Get Path.
     * \return Path to run until reaching Target.
     */
    list<Point> path() const;

    /* setter */
    /**
     * Set Running Flag.
     * \param running Running Flag.
     */
    void setRunning(bool running);
    /**
     * Add a Running Animation.
     * Adds the Animation to the Animation list and overrides the shortcut.
     * \param a Running Animation.
     * \return The shortcut to the Running Animation.
     */
    shared_ptr<Animation> addRunningAnimation(shared_ptr<Animation> a);
    /**
     * Set The Target.
     * Sets The Path and its last Point as Target.
     * \param path List of Points to run until reaching Target.
     */
    void setTarget(list<Point> path);
    /**
     * Set Character Speed.
     * \param s Speed.
     */
    void setSpeed(int s);

    /* misc */
    /**
     * Start to run.
     * Sets The Active Animation to the Runing Animation.
     */
    void startRunning();
    /**
     * Stop to run.
     * Sets The Active Animation to the First Animation in Animation List. Reset Running Animation.
     */
    void stopRunning();
    /**
     * Do repeating tasks.
     * Move if nessessary in next path point direction. Tick current Animation.
     * \param t time.
     * \param activeScreen currently active Screen.
     * \param gameHeight Height of Game.
     */
    void tick(int t, shared_ptr<Screen> activeScreen, int gameHeight);
};

#endif /* CHARACTER_H */
