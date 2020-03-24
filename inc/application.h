#pragma once

#include <SDL_GUI/inc/application.h>
#include <SDL_GUI/inc/models/input_model.h>

#include <input_keys.h>

class Application : public SDL_GUI::Application {
    SDL_GUI::InputModel<InputKey> *_input_model = nullptr;

    void update_running() override;
public:
    Application(std::string application_title) : SDL_GUI::Application(application_title) {}

    void init_MVCs() override;
};
