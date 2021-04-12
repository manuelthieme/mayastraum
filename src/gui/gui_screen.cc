#include <gui/gui_screen.h>

#include <SDL_GUI/models/interface_model.h>

GuiScreen::GuiScreen(std::string type, SDL_Renderer *renderer, const Screen *screen, const GameModel *game_model)
    : GuiScreenObject(type, renderer, screen, game_model), _screen(screen) {

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
        [game_model](){
            return game_model->_showing_stats;
        });

    this->_graph_rect = new SDL_GUI::Rect({0, 0}, 1920, 1080);

    this->add_debug_drawable(this->_graph_rect,
        [game_model](){
            return 1 or game_model->_showing_graph;
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
