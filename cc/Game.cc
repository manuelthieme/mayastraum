#include "../h/includes.h"

using namespace std;
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


    for (auto o: this->m_activeScreen->objects()) {
        cout << o->renderHitbox(this->m_activeScreen, this->m_height) << endl;
    }

    return success;
}

void Game::setPlayer(shared_ptr<Character> player) {
    this->m_player = player;
}

void Game::setDebug(shared_ptr<ScreenObject> d) {
    this->m_debug = d;
}

/* misc */
void Game::render() {
    this->clear();
	this->drawBackground();
    this->m_activeScreen->sortScreenObjects();
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
        /* Draw Bounding box */
        if (this->m_inputStates["debug_bounding"]) {
            Point renderSize = o->renderSize(this->m_activeScreen, this->m_height);
            SDL_Rect rect = {
                int(o->position().x() - renderSize.width() * o->pivot().x()),
                int(o->position().y() - renderSize.height() * o->pivot().y()),
                int(renderSize.width()),
                int(renderSize.height())
            };
            SDL_RenderDrawRect(this->m_renderer, &rect);
        }
        /* draw Pivot Point */
        if (this->m_inputStates["debug_pivot"]) {
            int size = 3;
            SDL_SetRenderDrawColor(this->m_renderer, 255, 0, 0, 0);
            SDL_RenderDrawLine(this->m_renderer, o->position().x() - size, o->position().y() - size, o->position().x() + size, o->position().y() + size);
            SDL_RenderDrawLine(this->m_renderer, o->position().x() + size, o->position().y() - size, o->position().x() - size, o->position().y() + size);
            SDL_SetRenderDrawColor(this->m_renderer, 0, 0, 0, 0);
        }
        /* draw Hitbox */
        if (this->m_inputStates["debug_hitbox"]) {
            for (auto e: o->renderHitbox(this->m_activeScreen, this->m_height).edges()) {
                SDL_RenderDrawLine(
                        this->m_renderer,
                        o->position().x() + e.begin().x(),
                        o->position().y() + e.begin().y(),
                        o->position().x() + e.end().x(),
                        o->position().y() + e.end().y());
            }
        }
    }

    /* draw Screen Hitbox */
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
    /* draw pathGraph */
    if (this->m_inputStates["debug_graph"]) {
        for (auto e: this->m_pathGraph.edges()) {
            SDL_SetRenderDrawColor(this->m_renderer, 100, 100, 100, 0);
            SDL_RenderDrawLine(this->m_renderer, e.begin().x(), e.begin().y(), e.end().x(), e.end().y());
            SDL_SetRenderDrawColor(this->m_renderer, 0, 0, 0, 0);
        }
        bool first = true;
        Point before;
        for (auto p: this->m_player->path()) {
            if (first) {
                SDL_SetRenderDrawColor(this->m_renderer, 200, 50, 50, 0);
                SDL_RenderDrawLine(this->m_renderer, this->m_player->position().x(), this->m_player->position().y(), p.x(), p.y());
                SDL_SetRenderDrawColor(this->m_renderer, 0, 0, 0, 0);
                before = p;
                first = false;
                continue;
            }
            SDL_SetRenderDrawColor(this->m_renderer, 200, 50, 50, 0);
            SDL_RenderDrawLine(this->m_renderer, before.x(), before.y(), p.x(), p.y());
            SDL_SetRenderDrawColor(this->m_renderer, 0, 0, 0, 0);
            before = p;
        }

    }
    this->m_inputStates["out"] = false;

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
	if (not (this->m_inputStates["debug"] and this->m_inputStates["debug_notick"]))
        screenObject->tick(this->tick++, this->m_activeScreen, this->m_height);
    Point renderSize = screenObject->renderSize(this->m_activeScreen, this->m_height);
	SDL_Rect rect = {
		int(screenObject->position().x() - renderSize.width() * screenObject->pivot().x()),
		int(screenObject->position().y() - renderSize.height() * screenObject->pivot().y()),
		int(renderSize.width()),
		int(renderSize.height())
    };
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
                                this->m_inputStates["out"] = true;
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
                                this->m_inputStates["out"] = true;
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
                                this->m_inputStates["out"] = true;
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
                    case SDL_SCANCODE_G:
                        if (this->m_inputStates["debug"]) {
                            if (this->m_inputStates["debug_graph"]) {
                                this->m_inputStates["debug_graph"] = false;
                                cout << "Hiding Graph" << endl;
                            } else {
                                this->m_inputStates["debug_graph"] = true;
                                cout << "Showing Graph" << endl;
                            }
                        }
                        break;
                    case SDL_SCANCODE_N:
                        if (this->m_inputStates["debug"]) {
                            if (this->m_inputStates["debug_notick"]) {
                                this->m_inputStates["debug_notick"] = false;
                                cout << "Ticking enabled" << endl;
                            } else {
                                this->m_inputStates["debug_notick"] = true;
                                cout << "Ticking disabled" << endl;
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
                if (event.button.button == SDL_BUTTON_LEFT) {
                    if (this->m_debug != nullptr) {
                        float factor = 1 / ((this->m_debug->position().y() / this->m_height) * (1 - this->m_activeScreen->sizeFactor()) + this->m_activeScreen->sizeFactor());
                        cout << Point(event.motion.x, event.motion.y) << this->m_debug->position() << Point(factor * (this->m_debug->position().x() - event.motion.x), factor * (this->m_debug->position().y() - event.motion.y)) << endl;
                    }
                    else {
                        this->m_player->startRunning();
                        this->m_player->setTarget(this->shortestPath(this->m_player, Point(float(event.motion.x), float(event.motion.y))));
                        this->m_inputStates["out"] = true;
                    }
                } else if (event.button.button == SDL_BUTTON_RIGHT) {
                    if (this->m_inputStates["debug"] and this->m_inputStates["debug_notick"]) {
                        this->m_player->setPosition(Point(float(event.motion.x),float(event.motion.y)));
                    }
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

list<Point> Game::shortestPath(shared_ptr<Character> character, Point target) {
    for (auto o: this->m_activeScreen->objects()) {
        if (o->collides(target, this->m_activeScreen, this->m_height)) {
            target = o->nearestPoint(target);
            break;
        }
    }
    Graph pathGraph = this->pathGraph(character->position(), target);
    return pathGraph.shortestPath(character->position(), target);
}

Graph Game::pathGraph(Point position, Point target) {
    vector<Point> points;
    for (auto o: this->m_activeScreen->objects())
        for (auto p: o->renderHitbox(this->m_activeScreen, this->m_height).points())
            points.push_back(p + o->position());

    for (auto p: this->m_activeScreen->hitbox().points())
        points.push_back(p);

    points.push_back(position);
    points.push_back(target);
    this->m_pathGraph.clear();
    /* check every possible set of 2 points */
    int count = 0;
    int inserted = 0;
    for (auto p1 = points.begin(); p1 != points.end(); ++p1) {
        for (auto p2 = p1 + 1; p2 != points.end(); ++p2) {
            ++count;
            Edge edge(*p1, *p2);
            /* check if the edge, consisting of this 2 Points, collides with a screenObject */
            bool toInsert = true;
            bool isHitbox = false;

            /* check whether the Edge is a hitbox edge */
            for (auto o: this->m_activeScreen->objects()) {
                for (auto e: o->renderHitbox(this->m_activeScreen, this->m_height).edges()) {
                    if ((e + o->position()) == edge) {
                        isHitbox = true;
                        break;
                    }
                }
                if (isHitbox)
                    break;
            }
            /* check whether the Edge is a Screen Hitbox Edge */
            for (auto e: this->m_activeScreen->hitbox().edges()) {
                if (e == edge) {
                    isHitbox = true;
                    break;
                }
            }

            if (not isHitbox) {
                for (auto o: this->m_activeScreen->objects()) {
                    if (o->collides(edge, this->m_activeScreen, this->m_height)) {
                        toInsert = false;
                    }
                    if (o->collides(edge.middle(), this->m_activeScreen, this->m_height)) {
                        toInsert = false;
                        break;
                    }
                }
                if (this->m_activeScreen->collides(edge))
                    toInsert = false;
                if (this->m_activeScreen->collides(edge.middle()))
                    toInsert = false;
            }

            if (toInsert) {
                ++inserted;
                this->m_pathGraph.addEdge(edge);
            }
        }
    }
    //cout << count << " possible edges, " << inserted << " inserted." << endl;
    return this->m_pathGraph;
}

