#include "../h/Game.h"

/* constructor */
Game::Game(vector<Screen> screens, float width, float height, Character* player) : m_screens(screens), m_width(width), m_height(height), m_player(player) {
    if (this->m_screens.size() > 0)
        this->m_activeScreen = &(this->m_screens[0]);

    this->init();
}

/* getter */


/* setter */
void Game::addScreen(Screen screen) {
    this->m_screens.push_back(screen);
}

bool Game::setActiveScreen(Screen screen) {
    bool success = false;
    for (auto s: this->m_screens)
        if (s == screen) {
            this->m_activeScreen = &s;
            success = true;
            break;
        }

    return success;
}

void Game::setPlayer(Character* player) {
    this->m_player = player;
}

/* misc */
void Game::render() {
    /* TODO Render!!1!!! */
}

void Game::init() {
    this->window = NULL;
	this->renderer = NULL;

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		cerr << "SDL_Init failed" << endl;
		return;
	}
	this->window = SDL_CreateWindow( "Mayas Traum",
		   	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->m_width,
			this->m_height, SDL_WINDOW_SHOWN );
	if(!this->window) {
		cerr << "Window Creation failed" << endl;
		return;
	}
	this->renderer = SDL_CreateRenderer(this->window, -1,
			SDL_RENDERER_ACCELERATED);
	if(!this->renderer) {
		cerr << "Renderer Creation failed" << endl;
		return;
	}
	this->mainEvent = new SDL_Event();

}

bool Game::run() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_ESCAPE:
                        return false;
                        break;
#if 0
                    case SDL_SCANCODE_D:
                        if (this->debug)
                            this->debug = false;
                        else
                            this->debug = true;
                        break;
#endif
                    default:
                        break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button == SDL_BUTTON_LEFT) {
                //	cout << "Mousebuttonevent incoming" << endl;
#if 0
                    this->screen->getPlayer()->startRunning();
                    this->screen->getPlayer()->setTarget(float(event.motion.x), float(event.motion.y));
#endif
                }
                break;
            case SDL_QUIT:
                //cout << "quit" << endl;
                return false;
                break;
        }
    }

    SDL_Delay(10);
    return true;
}
