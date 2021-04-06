#include <gui/gui_screen_object.h>

#include <iostream>

#include <SDL_GUI/gui/primitives/wrap_rect.h>
#include <SDL_GUI/gui/primitives/line.h>


GuiScreenObject::GuiScreenObject(std::string type, SDL_Renderer *renderer,
                                 const ScreenObject *screen_object, const GameModel *game_model)
    : SDL_GUI::Texture(type, screen_object->path(), renderer),
    _screen_object(screen_object) {
    this->_width = screen_object->width();
    this->_height = screen_object->height();

    /* generate pivot cross */
    Point pivot = screen_object->pivot();
    pivot.move({-4, -4});

    SDL_GUI::WrapRect *rect = new SDL_GUI::WrapRect(pivot.position());
    //rect->_style._has_background = true;
    //rect->_style._color = SDL_GUI::RGB(255, 255, 255, 150);

    SDL_GUI::Line *l =
        new SDL_GUI::Line({0, 0}, {9, 9});
    l->set_line_width(3);
    l->_style._color = SDL_GUI::RGB("red");
    rect->add_child(l, true);

    l = new SDL_GUI::Line({0, 9}, {9, 0});
    l->_style._color = SDL_GUI::RGB("red");
    l->set_line_width(3);
    rect->add_child(l, true);

    this->add_debug_drawable(rect,
        [game_model](){
            return game_model->_debugging && game_model->_debugging_pivot;
        });

    /* generate hitbox */
    const Hitbox *hitbox = this->_screen_object->hitbox();
    if (hitbox) {
        SDL_GUI::Drawable *h = hitbox->drawable();
        this->add_debug_drawable(h,
            [game_model](){
                return game_model->_debugging && game_model->_debugging_hitboxes;
            });
    }

}

void GuiScreenObject::update() {
    Point position = this->_screen_object->position() - this->_screen_object->pivot();
    this->set_position({static_cast<int>(position.x()), static_cast<int>(position.y())});
}
