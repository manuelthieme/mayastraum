#include <vector>

#include "../h/Game.h"

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

    Screen screen({}, "screens/garden.png");
    ScreenObject tree(
            Point(650, 580),
            Point(300, 699),
            Point(0.5, 0.85),
            Hitbox(),
            animations1
        );
    ScreenObject mower(
            Point(450, 620),
            Point(222, 200),
            Point(0.3, 0.85),
            Hitbox(),
            animations2
        );
    screen.addScreenObject(tree);
    screen.addScreenObject(mower);

    vector<Screen> screens;
    screens.push_back(screen);

    Game game(
            screens,
            1600,
            900,
            NULL
        );

    while(game.run())
        ; /** void */

    return 0;
}
