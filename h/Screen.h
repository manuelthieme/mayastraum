#ifndef SCREEN_H
#define SCREEN_H

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
    vector<shared_ptr<ScreenObject>> m_objects;
    string m_backgroundPath;
    Hitbox m_hitbox;
    float m_sizeFactor;

public:
    /* constructor */
    Screen(vector<shared_ptr<ScreenObject>> objects, string backgroundPath, float sizeFactor = 0.5);

    /* getter */
    vector<shared_ptr<ScreenObject>> objects() const;
    string backgroundPath() const;
    Hitbox hitbox() const;
    float sizeFactor() const;

    /* setter */
    shared_ptr<ScreenObject> addScreenObject(shared_ptr<ScreenObject> screenObject);
    shared_ptr<Character> addPlayer(shared_ptr<Character> c);
    void setHitbox(Hitbox h);
    void setSizeFactor(float s);

    /* operators */
    bool operator==(const Screen &s) const;

    /* misc */
    void sortScreenObjects();
    bool collides(Edge e) const;
};

#endif /* SCREEN_H */
