#include <vector>

#include "../h/Game.h"

int main(void) {
    vector<Screen> v;
    Screen s(vector<ScreenObject>(), "screens/garden.png");
    v.push_back(s);
    vector<string> n;
    n.push_back("sprites/tree1.png");
    Animation a(n);
    vector<Animation> as;
    as.push_back(a);
    ScreenObject tree(Point(650, 580), Point(300, 699), Point(0.5, 0.85), Hitbox(), as);
    Game game(v, 1600, 900, NULL);

    while(game.run())
        ; /** void */

    return 0;
}
