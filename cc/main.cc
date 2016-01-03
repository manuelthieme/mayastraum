#include <vector>
#include <iostream>
#include <memory>

#include "../h/includes.h"

using namespace std;
int main(void) {
    vector<string> images_a1;
    images_a1.push_back("sprites/tree1.png");
    vector<string> images_a2;
    images_a2.push_back("sprites/mower.png");
    vector<string> images_a3;
    images_a3.push_back("characters/strichmann.png");
    vector<string> images_a4;
    images_a4.push_back("characters/strichmann.png");
    images_a4.push_back("characters/strichmann1.png");
    images_a4.push_back("characters/strichmann2.png");


    Animation a1(images_a1, -1);
    Animation a2(images_a2, -1);
    Animation a3(images_a3, -1);
    Animation a4(images_a4, 25);

    vector<shared_ptr<Animation>> animations1;
    animations1.push_back(shared_ptr<Animation>(new Animation(a1)));
    vector<shared_ptr<Animation>> animations2;
    animations2.push_back(shared_ptr<Animation>(new Animation(a2)));
    vector<shared_ptr<Animation>> animations3;
    animations3.push_back(shared_ptr<Animation>(new Animation(a3)));

    Hitbox h1;
    h1.addPoint(Point(-92, 17));
    h1.addPoint(Point(-20, 0));
    h1.addPoint(Point(-5, 53));
    h1.addPoint(Point(8, 33));
    h1.addPoint(Point(-1, 10));
    h1.addPoint(Point(8, -2));
    h1.addPoint(Point(50, 27));
    h1.addPoint(Point(71, 20));
    h1.addPoint(Point(58, 12));
    h1.addPoint(Point(29, -18));
    h1.addPoint(Point(11, -46));
    h1.addPoint(Point(-12, -22));
    h1.addPoint(Point(-50, -3));
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

    Character player(
            Point(100, 500),
            Point(100, 200),
            Point(0.4, 0.95),
            Hitbox(),
            animations3
        );

    player.addRunningAnimation(shared_ptr<Animation>(new Animation(a4)));

    vector<shared_ptr<ScreenObject>> objects;
    shared_ptr<ScreenObject> p_tree(new ScreenObject(tree));
    objects.push_back(p_tree);
    objects.push_back(shared_ptr<ScreenObject>(new ScreenObject(mower)));
    Screen screen(objects, "screens/garden.png");
    shared_ptr<Character> p = screen.addPlayer(shared_ptr<Character>(new Character(player)));
    screen.setHitbox(hs);

    vector<shared_ptr<Screen>> screens;
    screens.push_back(shared_ptr<Screen>(new Screen(screen)));

    Game game(
            screens,
            1280,
            800,
            NULL
        );
    game.setPlayer(p);

    while(game.run())
        ; /** void */

    return 0;
}
