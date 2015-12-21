#include <vector>
#include <iostream>

#include "../h/Game.h"

using namespace std;
int main(void) {
    vector<string> images_a1;
    images_a1.push_back("sprites/tree1.png");
    vector<string> images_a2;
    images_a2.push_back("sprites/mower.png");

    Animation a1(images_a1);
    Animation a2(images_a2);

    vector<Animation> animations1;
    animations1.push_back(a1);

    vector<Animation> animations2;
    animations2.push_back(a2);

    Hitbox h1;
    h1.addPoint(Point(-50, -25));
    h1.addPoint(Point(-50, 25));
    h1.addPoint(Point(50, 25));
    h1.addPoint(Point(50, -25));
    h1.calculateEdges();

    Hitbox h2;
    h2.addPoint(Point(-28, -9));
    h2.addPoint(Point(26, -33));
    h2.addPoint(Point(80, -14));
    h2.addPoint(Point(24, 5));
    h2.calculateEdges();

    Hitbox hs;
    hs.addPoint(Point(-1, -1));
    hs.addPoint(Point(-1, 320));
    hs.addPoint(Point(200, 315));
    hs.addPoint(Point(400, 330));
    hs.addPoint(Point(600, 345));
    hs.addPoint(Point(750, 345));
    hs.addPoint(Point(900, 335));
    hs.addPoint(Point(1100, 340));
    hs.addPoint(Point(1280, 325));
    hs.addPoint(Point(1280, -1));
    hs.calculateEdges();

    ScreenObject tree(
            Point(650, 580),
            Point(300, 699),
            Point(0.5, 0.85),
            h1,
            animations1
        );
    ScreenObject mower(
            Point(450, 620),
            Point(222, 200),
            Point(0.3, 0.85),
            h2,
            animations2
        );

    Screen screen({}, "screens/garden.png");
    screen.addScreenObject(tree);
    screen.addScreenObject(mower);
    screen.setHitbox(hs);

    vector<Screen> screens;
    screens.push_back(screen);

    Game game(
            screens,
            1280,
            800,
            NULL
        );

    while(game.run())
        ; /** void */

    return 0;
}
