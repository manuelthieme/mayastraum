#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <string>

#include "ScreenObject.h"

class Screen {
    vector<ScreenObject> m_objects;
    string m_backgroundPath;

public:
    /* constructor */
    Screen(vector<ScreenObject> objects, string backgroundPath);

    /* getter */
    vector<ScreenObject> objects() const;
    string backgroundPath() const;

    /* setter */
    void addScreenObject(ScreenObject screenObject);

    /* operators */
    bool operator==(const Screen &s) const;
};

#endif /* SCREEN_H */
