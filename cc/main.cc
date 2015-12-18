#include <vector>

#include "../h/Game.h"
#include "../h/Screen.h"

int main(void) {
    vector<Screen> v;
    Game game(v, 1600, 900, NULL);

    while(game.run())
        ; /** void */

    return 0;
}
