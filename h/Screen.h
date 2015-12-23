#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <string>
#include <memory>

#include "ScreenObject.h"
#include "Character.h"
#include "Hitbox.h"

class Screen {
    vector<shared_ptr<ScreenObject>> m_objects;
    string m_backgroundPath;
    Hitbox m_hitbox;

public:
    /* constructor */
    Screen(vector<shared_ptr<ScreenObject>> objects, string backgroundPath);

    /* getter */
    vector<shared_ptr<ScreenObject>> objects() const;
    string backgroundPath() const;
    Hitbox hitbox() const;

    /* setter */
    shared_ptr<ScreenObject> addScreenObject(shared_ptr<ScreenObject> screenObject);
    shared_ptr<Character> addPlayer(shared_ptr<Character> c);
    void setHitbox(Hitbox h);

    /* operators */
    bool operator==(const Screen &s) const;
};

#endif /* SCREEN_H */
