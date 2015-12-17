#ifndef SCREEN_H
#define SCREEN_H

#include <vector>

#include "ScreenObject.h"

class Screen {
    vector<ScreenObject> m_objects;

public:
    /* constructor */
    Screen(vector<ScreenObject> objects);

    /* getter */
    vector<ScreenObject> objects() const;

    /* setter */
    void addScreenObject(ScreenObject screenObject);

    /* operators */
    bool operator==(const Screen &s) const;
};

#endif /* SCREEN_H */
