#include <gui/gui_screen.h>

#include <SDL_GUI/inc/models/interface_model.h>

#include <models/game_model.h>

GuiScreen::GuiScreen(std::string type, const Screen *screen, SDL_Renderer *renderer)
    : Texture(type, screen->background_path(), renderer), _screen(screen) {

    this->_debug_rect = new SDL_GUI::Rect({1600, 700}, 320, 380);
    this->_debug_rect->_style._has_background = true;
    this->_debug_rect->_style._color = SDL_GUI::RGB(255, 255, 255, 150);

    this->add_debug_drawable(this->_debug_rect,
        [this](){
            return this->_interface_model->debug_information_drawn();
        });

    this->_stats_rect = new SDL_GUI::Rect({1820, 0}, 100, 50);
    this->_stats_rect->_style._has_background = true;
    this->_stats_rect->_style._color = SDL_GUI::RGB(255, 255, 255, 150);

    this->add_debug_drawable(this->_stats_rect,
        [this](){
            return this->_screen->game_model()->_debugging_stats;
        });

    this->_graph_rect = new SDL_GUI::Rect({0, 0}, 1920, 1080);

    this->add_debug_drawable(this->_graph_rect,
        [this](){
            return 1 or this->_screen->game_model()->_debugging_graph;
        });
}

SDL_GUI::Rect *GuiScreen::debug_rect() {
    return this->_debug_rect;
}

SDL_GUI::Rect *GuiScreen::stats_rect() {
    return this->_stats_rect;
}

SDL_GUI::Rect *GuiScreen::graph_rect() {
    return this->_graph_rect;
}
