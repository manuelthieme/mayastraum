#include "../h/Game.h"

/* constructor */
Game::Game(vector<shared_ptr<Screen>> screens, float width, float height, Character* player) : m_screens(screens), m_width(width), m_height(height), m_player(player) {
    if (this->m_screens.size() > 0)
        this->m_activeScreen = this->m_screens[0];

    this->init();
}

/* getter */


/* setter */
shared_ptr<Screen> Game::addScreen(shared_ptr<Screen> screen) {
    this->m_screens.push_back(screen);
    return this->m_screens.back();
}

bool Game::setActiveScreen(shared_ptr<Screen> screen) {
    bool success = false;
    for (auto s: this->m_screens)
        if (s == screen) {
            this->m_activeScreen = s;
            success = true;
            break;
        }

    return success;
}

void Game::setPlayer(shared_ptr<Character> player) {
    this->m_player = player;
}

/* misc */
void Game::render() {
    this->clear();
	this->drawBackground();
#if 0
    this->activeScreen->sortScreenObjects();
#endif
	for (auto object: this->m_activeScreen->objects())
		this->drawScreenObject(object);

    if (this->m_inputStates["debug"]) this->drawDebug();

    this->present();

}

void Game::drawDebug() {
    SDL_Color color = {255, 0, 0, 1};
    SDL_Surface* surface = TTF_RenderText_Solid(this->m_font, "D", color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(this->m_renderer, surface);

    SDL_Rect rect = {0, 0, 20, 30};
    SDL_RenderCopy(this->m_renderer, texture, NULL, &rect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);

    for (auto o: this->m_activeScreen->objects()) {
        if (this->m_inputStates["debug_bounding"]) {
            SDL_Rect rect = {
                int(o->position().x() - o->size().width() * o->pivot().x()),
                int(o->position().y() - o->size().height() * o->pivot().y()),
                int(o->size().width()),
                int(o->size().height())
            };
            SDL_RenderDrawRect(this->m_renderer, &rect);
        }
        if (this->m_inputStates["debug_pivot"]) {
            int size = 3;
            SDL_SetRenderDrawColor(this->m_renderer, 255, 0, 0, 0);
            SDL_RenderDrawLine(this->m_renderer, o->position().x() - size, o->position().y() - size, o->position().x() + size, o->position().y() + size);
            SDL_RenderDrawLine(this->m_renderer, o->position().x() + size, o->position().y() - size, o->position().x() - size, o->position().y() + size);
            SDL_SetRenderDrawColor(this->m_renderer, 0, 0, 0, 0);
        }
        if (this->m_inputStates["debug_hitbox"]) {
            for (auto e: o->hitbox().edges()) {
                SDL_RenderDrawLine(
                        this->m_renderer,
                        o->position().x() + e.begin().x(),
                        o->position().y() + e.begin().y(),
                        o->position().x() + e.end().x(),
                        o->position().y() + e.end().y());
            }
        }
    }

    if (this->m_inputStates["debug_screen_hitbox"]) {
        for (auto e: this->m_activeScreen->hitbox().edges()) {
            SDL_RenderDrawLine(
                    this->m_renderer,
                    e.begin().x(),
                    e.begin().y(),
                    e.end().x(),
                    e.end().y());
        }
    }
#if 0
    for (auto e: this->screen->graph.getEdges())
        SDL_RenderDrawLine(this->renderer, e.getBegin().getX(), e.getBegin().getY(), e.getEnd().getX(), e.getEnd().getY());
#endif

}

void Game::drawBackground() {
	SDL_Rect rect = {0, 0, int(this->m_width), int(this->m_height)};
	SDL_RenderCopy(this->m_renderer, this->getTextureFromPath(this->m_activeScreen->backgroundPath()), NULL, &rect);
}

SDL_Texture* Game::getTextureFromPath(string texturePath) {
	if(!this->m_textures.count(texturePath))
		this->m_textures.insert(pair<string, SDL_Texture*>(texturePath, IMG_LoadTexture(this->m_renderer, texturePath.c_str())));
	return this->m_textures.at(texturePath);
}

void Game::clear() {
	SDL_RenderClear(this->m_renderer);
}

void Game::drawScreenObject(shared_ptr<ScreenObject> screenObject) {
	SDL_Rect rect = {
		int(screenObject->position().x() - screenObject->size().width() * screenObject->pivot().x()),
		int(screenObject->position().y() - screenObject->size().height() * screenObject->pivot().y()),
		int(screenObject->size().width()),
		int(screenObject->size().height())
    };
	screenObject->tick(this->tick++);
	SDL_RenderCopy(this->m_renderer, this->getTextureFromPath(screenObject->activeAnimation()->activeImage()), NULL, &rect);
}

void Game::present() {
	SDL_RenderPresent(this->m_renderer);
}

Game::~Game() {
	SDL_DestroyWindow(this->m_window);
	SDL_DestroyRenderer(this->m_renderer);
    TTF_CloseFont(this->m_font);
    TTF_Quit();
	SDL_Quit();
}


void Game::init() {
    this->m_window = NULL;
	this->m_renderer = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cerr << "SDL_Init failed" << endl;
		return;
	}
    if (TTF_Init() < 0) {
        cerr << "TTF_Init failed: " << TTF_GetError() << endl;
        return;
    }
    this->m_font = TTF_OpenFont("fonts/KeepCalm-Medium.ttf", 24);
    if (this->m_font == NULL) {
        cout << " Failed to load font : " << TTF_GetError() << endl;
        return;
    }
	this->m_window = SDL_CreateWindow( "Mayas Traum",
		   	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->m_width,
			this->m_height, SDL_WINDOW_SHOWN );
	if (!this->m_window) {
		cerr << "Window Creation failed" << endl;
		return;
	}
	this->m_renderer = SDL_CreateRenderer(this->m_window, -1,
			SDL_RENDERER_ACCELERATED);
	if (!this->m_renderer) {
		cerr << "Renderer Creation failed" << endl;
		return;
	}
	this->m_mainEvent = new SDL_Event();

}

bool Game::run() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_ESCAPE:
                        cout << "Quit" << endl;
                        return false;
                        break;
                    case SDL_SCANCODE_D:
                        if (this->m_inputStates["debug"]) {
                            this->m_inputStates["debug"] = false;
                            cout << "Debug Mode off" << endl;
                        } else {
                            this->m_inputStates["debug"] = true;
                            cout << "Debug Mode on" << endl;
                        }
                        break;
                    case SDL_SCANCODE_B:
                        if (this->m_inputStates["debug"]) {
                            if (this->m_inputStates["debug_bounding"]) {
                                this->m_inputStates["debug_bounding"] = false;
                                cout << "Hiding Bounding boxes" << endl;
                            } else {
                                this->m_inputStates["debug_bounding"] = true;
                                cout << "Showing Bounding boxes" << endl;
                            }
                        }
                        break;
                    case SDL_SCANCODE_P:
                        if (this->m_inputStates["debug"]) {
                            if (this->m_inputStates["debug_pivot"]) {
                                this->m_inputStates["debug_pivot"] = false;
                                cout << "Hiding Pivot points" << endl;
                            } else {
                                this->m_inputStates["debug_pivot"] = true;
                                cout << "Showing Pivot points" << endl;
                            }
                        }
                        break;
                    case SDL_SCANCODE_H:
                        if (this->m_inputStates["debug"]) {
                            if (this->m_inputStates["debug_hitbox"]) {
                                this->m_inputStates["debug_hitbox"] = false;
                                cout << "Hiding Hitboxes" << endl;
                            } else {
                                this->m_inputStates["debug_hitbox"] = true;
                                cout << "Showing Hitboxes" << endl;
                            }
                        }
                        break;
                    case SDL_SCANCODE_S:
                        if (this->m_inputStates["debug"]) {
                            if (this->m_inputStates["debug_screen_hitbox"]) {
                                this->m_inputStates["debug_screen_hitbox"] = false;
                                cout << "Hiding Screen Hitbox" << endl;
                            } else {
                                this->m_inputStates["debug_screen_hitbox"] = true;
                                cout << "Showing Screen Hitbox" << endl;
                            }
                        }
                        break;
                    case SDL_SCANCODE_R:
                        if (this->m_player->running())
                            this->m_player->stopRunning();
                        else
                            this->m_player->startRunning();
                    default:
                        break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button == SDL_BUTTON_LEFT) {
                    cout << Point(event.motion.x, event.motion.y) << endl;
                //	cout << "Mousebuttonevent incoming" << endl;
#if 0
                    this->screen->getPlayer()->startRunning();
                    this->screen->getPlayer()->setTarget(float(event.motion.x), float(event.motion.y));
#endif
                }
                break;
            case SDL_QUIT:
                cout << "Quit" << endl;
                return false;
                break;
        }
    }
    this->render();

    SDL_Delay(10);
    return true;
}
