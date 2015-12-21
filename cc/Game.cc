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
    this->clear();
	this->drawBackground();
#if 0
    this->activeScreen->sortScreenObjects();
#endif
	for (auto object: this->m_activeScreen->objects())
		this->drawScreenObject(object);
#if 0
    if (this->debug)
        for (auto e: this->screen->graph.getEdges())
            SDL_RenderDrawLine(this->renderer, e.getBegin().getX(), e.getBegin().getY(), e.getEnd().getX(), e.getEnd().getY());
#endif
    this->present();

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

void Game::drawScreenObject(ScreenObject screenObject) {
	SDL_Rect rect = {
		int(screenObject.position().x() - screenObject.size().width() * screenObject.pivot().x()),
		int(screenObject.position().y() - screenObject.size().height() * screenObject.pivot().y()),
		int(screenObject.size().width()),
		int(screenObject.size().height())
    };
#if 0
	screenObject->activeAnimation()->tick();
#endif
	SDL_RenderCopy(this->m_renderer, this->getTextureFromPath(screenObject.activeAnimation().activeImage()), NULL, &rect);
}

void Game::present() {
	SDL_RenderPresent(this->m_renderer);
}

Game::~Game() {
	SDL_DestroyWindow(this->m_window);
	SDL_DestroyRenderer(this->m_renderer);
	SDL_Quit();
}


void Game::init() {
    this->m_window = NULL;
	this->m_renderer = NULL;

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		cerr << "SDL_Init failed" << endl;
		return;
	}
	this->m_window = SDL_CreateWindow( "Mayas Traum",
		   	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->m_width,
			this->m_height, SDL_WINDOW_SHOWN );
	if(!this->m_window) {
		cerr << "Window Creation failed" << endl;
		return;
	}
	this->m_renderer = SDL_CreateRenderer(this->m_window, -1,
			SDL_RENDERER_ACCELERATED);
	if(!this->m_renderer) {
		cerr << "Renderer Creation failed" << endl;
		return;
	}
	this->m_mainEvent = new SDL_Event();

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
    this->render();

    SDL_Delay(10);
    return true;
}
