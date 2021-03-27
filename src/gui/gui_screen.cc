#include <gui/gui_screen.h>

#include <SDL_GUI/inc/models/interface_model.h>


GuiScreen::GuiScreen(std::string type, const Screen *screen, SDL_Renderer *renderer)
    : Texture(type, screen->background_path(), renderer), _screen(screen) {

    this->_debug_rect = new SDL_GUI::Rect({1600, 700}, 320, 380);
    this->_debug_rect->_default_style._has_background = true;
    this->_debug_rect->_default_style._color = SDL_GUI::RGB(255, 255, 255, 150);

    this->add_debug_drawable(this->_debug_rect,
        [this](){
            return this->_interface_model->debug_information_drawn();
        });
}

SDL_GUI::Rect *GuiScreen::debug_rect() {
    return this->_debug_rect;
}
