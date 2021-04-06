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
            return game_model->_debugging && game_model->_showing_pivot;
        });

    /* generate hitbox */
    SDL_GUI::WrapRect *hitbox_rect = new SDL_GUI::WrapRect();
    hitbox_rect->add_recalculation_callback(
        [this](SDL_GUI::Drawable *d){
            d->remove_all_children();
            const Hitbox *hitbox = this->_screen_object->hitbox();
            if (hitbox) {
                d->add_child(hitbox->drawable());
            }
        });
    this->add_debug_drawable(hitbox_rect,
        [this, game_model](){
            return game_model->_debugging
                    and ((game_model->editing_hitbox() and game_model->_debug_active == this)
                        or (not game_model->editing_box() and game_model->showing_hitbox()));
        });

    /* generate hoverbox */
    SDL_GUI::WrapRect *hover_box_rect = new SDL_GUI::WrapRect();
    hover_box_rect->add_recalculation_callback(
        [this](SDL_GUI::Drawable *d){
            d->remove_all_children();
            const Hitbox *hover_box = this->_screen_object->hover_box();
            if (hover_box) {
                d->add_child(hover_box->drawable());
            }
        });
    this->add_debug_drawable(hover_box_rect,
        [this, game_model](){
            return game_model->_debugging
                    and ((game_model->editing_hover_box() and game_model->_debug_active == this)
                        or (not game_model->editing_box() and game_model->showing_hover_box()));
        });

}

void GuiScreenObject::update() {
    Point position = this->_screen_object->position() - this->_screen_object->pivot();
    this->set_position({static_cast<int>(position.x()), static_cast<int>(position.y())});
}
