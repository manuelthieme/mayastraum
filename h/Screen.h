#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <string>

#include "ScreenObject.h"
#include "Hitbox.h"

class Screen {
    vector<ScreenObject> m_objects;
    string m_backgroundPath;
    Hitbox m_hitbox;

public:
    /* constructor */
    Screen(vector<ScreenObject> objects, string backgroundPath);

    /* getter */
    vector<ScreenObject> objects() const;
    string backgroundPath() const;
    Hitbox hitbox() const;

    /* setter */
    void addScreenObject(ScreenObject screenObject);
    void setHitbox(Hitbox h);

    /* operators */
    bool operator==(const Screen &s) const;
};

#endif /* SCREEN_H */
