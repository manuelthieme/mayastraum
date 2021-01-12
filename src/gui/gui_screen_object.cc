#include <gui/gui_screen_object.h>


GuiScreenObject::GuiScreenObject(SDL_Renderer *renderer, const ScreenObject *screen_object) :
    SDL_GUI::Texture(screen_object->path(), renderer),
    _screen_object(screen_object) {
    this->_width = screen_object->width();
    this->_height = screen_object->height();
}

void GuiScreenObject::update() {
    Point position = this->_screen_object->position() - this->_screen_object->pivot();
    this->set_position({static_cast<int>(position.x()), static_cast<int>(position.y())});
}
