#include <SDL_GUI/inc/application.h>
#include <SDL_GUI/inc/plugins/default_plugin.h>

#include <plugins/game_plugin.h>

int main(void) {

    SDL_GUI::Application<GamePlugin, SDL_GUI::DefaultPlugin> application("Mayas Traum");
    application.run();
    return 0;
}
