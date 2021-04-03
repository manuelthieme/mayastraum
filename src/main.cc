#include <SDL_GUI/application.h>
#include <SDL_GUI/plugins/default_plugin.h>

#include <plugins/game_plugin.h>

int main(int argc, char *argv[]) {

    SDL_GUI::Application<GamePlugin, SDL_GUI::DefaultPlugin> app("Mayas Traum", argc, argv);
    app.run();
    return 0;
}
