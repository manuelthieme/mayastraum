#pragma once

#include <string>
#include <vector>

#include <models/screen_object.h>

class Screen {
    /** Background Image. */
    std::string _background_path;

    /** Vector of Screen Objects. */
    std::vector<ScreenObject *> _screen_objects;

public:
    Screen(std::string path);

    std::string background_path() const;

    std::vector<ScreenObject *> screen_objects();

    void add_screen_object(ScreenObject *screen_object);
};

#if 0
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

#if 0
#include "Character.h"
#include "ScreenObject.h"
#include "Hitbox.h"
#endif

class Screen {
    /**
     * Area not enterable.
     */
    Hitbox m_hitbox;
    /**
     * Factor wich size does an object have at the vertical middle relative to the bottom line.
     */
    float m_sizeFactor;

public:
    /* constructor */
    /**
     * Constructor.
     * \param objects Vector of Screen Objects.
     * \param backgroundPath Background Image Path.
     * \param sizeFactor Wich Size does an Object have at the vertical middle relative to the bottom line.
     */
    Screen(vector<shared_ptr<ScreenObject>> objects, string backgroundPath, float sizeFactor = 0.5);

    /* getter */
    /**
     * Get Screen Objects.
     * \return Vectr of Screen Objects.
     */
    vector<shared_ptr<ScreenObject>> objects() const;
    /**
     * Get Background Image Path.
     * \return Background Image Path.
     */
    string backgroundPath() const;
    /**
     * Get not enterable area.
     * \return Screen Hitbox.
     */
    Hitbox hitbox() const;
    /**
     * Get size Factor.
     * \return sizeFactor.
     */
    float sizeFactor() const;

    /* setter */
    /**
     * Add a ScreenObject to Object List.
     * \param screenObject Object to Add.
     * \return pointer to added Object.
     */
    shared_ptr<ScreenObject> addScreenObject(shared_ptr<ScreenObject> screenObject);
    /**
     * Add Player to Object List.
     * \param c Player to add.
     * \return Pointer to added Player.
     */
    shared_ptr<Character> addPlayer(shared_ptr<Character> c);
    /**
     * Set Hitbox.
     * \param h Hitbox.
     */
    void setHitbox(Hitbox h);
    /**
     * set Size Factor.
     * \param s Size Factor.
     */
    void setSizeFactor(float s);

    /* operators */
    bool operator==(const Screen &s) const;

    /* misc */
    /**
     * Sort Screen Objects.
     * To Know what stand before what.
     */
    void sortScreenObjects();
    /**
     * Check if an Edge Collides with any Object.
     * \param e Edge to check against.
     * \return True if Edge collides. Otherwise False.
     */
    bool collides(Edge e) const;
    /**
     * check if a Point lies within the Hitbox of any Object.
     * \param p Point to check against.
     * \return True if Point lies within a Hitbox. Otherwise False.
     */
    bool collides(Point p) const;
};

#endif
