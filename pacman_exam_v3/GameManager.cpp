//
// Created by Sindre Johan Vinje on 30/03/2020.
//

#include <iostream>
#include "GameManager.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Tile.h"


void GameManager::init(const char *title, int xpos, int ypos, int window_witdh, int window_hight, int screen) {

    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(title, xpos, ypos, window_witdh, window_hight, screen);

    if (window == nullptr) {
        std::cout << "Not able to create window " <<  SDL_GetError() << std::endl;
        running = false;
        SDL_Quit();
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr) {
        std::cout << "Not abler to create renderer " << SDL_GetError() << std::endl;
        running = false;
        SDL_Quit();
    }

    tile->pushAllTiles();
    pills->loadImage(renderer, "../resources/pill.bmp");
    pills->pushAllPills();
    loadCharacters();

    running = true;
}
void GameManager::cap_fps(std::chrono::time_point<std::chrono::steady_clock> currentFrame) const {
    using std::chrono::duration_cast;
    using std::chrono::high_resolution_clock;
    using namespace std::chrono_literals;

    auto lastFrame = currentFrame;

    currentFrame = high_resolution_clock::now();
    high_resolution_clock::duration timeSpan = currentFrame - lastFrame;
    std::this_thread::sleep_for(1000ms/fps -(high_resolution_clock::now()-currentFrame));
}


void GameManager::loadCharacters() {

    Pacman::PacmanInstance().initHealth();
    Pacman::PacmanInstance().loadImage(renderer, "../resources/pacman.bmp");
    ghostRectList.reserve(4);

    for (int i = 0; i < 4; i++) {
        auto ghost = std::__1::make_shared<Ghost>();
        ghostRectList.emplace_back(ghost);
        ghost->loadImage(renderer, "../resources/ghost.bmp");
    }
    if(ghostRectList.empty()){
        std::cout << "Not able to create ghosts " <<  SDL_GetError() << std::endl;
    }
}

void GameManager::characterActions() {

    Pacman::PacmanInstance().constantMove();
    pacmanPickPill();

    for (const auto &currentGhost : ghostRectList) {
        currentGhost->constantMove();
    }
    for (auto &currentTile : tile->tileRectList) {
        checkPacmanCollisionWithWalls(Pacman::PacmanInstance().getRect(), &currentTile);

        for (const auto &currentGhost : ghostRectList) {
            currentGhost->onCollision(&currentTile);
            pacmmanTouchGhost(&currentGhost->ghostRect);
        }
    }
}

void GameManager::render() {

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    if (inGameMenu) {
        gameMenu->draw(renderer);
    }

    pills->draw(renderer);
    tile->drawRects(renderer);

    drawImages();

    SDL_RenderPresent(renderer);
}

void GameManager::eventHandler() {

    pollEvent();
    if (!inGameMenu) {
        //Down
        if (InputManager::Instance().KeyDown(SDL_SCANCODE_S)) {
            Pacman::PacmanInstance().changeDirection(0, 1);
        }
        //Up
        if (InputManager::Instance().KeyDown(SDL_SCANCODE_W)) {
            Pacman::PacmanInstance().changeDirection(0, -1);
        }
        //Right
        if (InputManager::Instance().KeyDown(SDL_SCANCODE_D)) {
            Pacman::PacmanInstance().changeDirection(1, 0);
        }
        //Left
        if (InputManager::Instance().KeyDown(SDL_SCANCODE_A)) {
            Pacman::PacmanInstance().changeDirection(-1, 0);
        }
    } else {
        if (InputManager::Instance().KeyDown(SDL_SCANCODE_R)) {
            restartGame();
        }
    }
}

void GameManager::pollEvent() {
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }
        } else if (event.type == SDL_QUIT) {
            running = false;
        }
    }
}

void GameManager::drawImages() const {
    for (const auto &currentRect : ghostRectList) {
        currentRect->draw(renderer);
    }
    Pacman::PacmanInstance().drawHealthBar(renderer);
    Pacman::PacmanInstance().draw(renderer);
}


void GameManager::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


void GameManager::checkPacmanCollisionWithWalls(SDL_Rect *block_a, SDL_Rect *block_b) {
    int rightA;
    int leftA;
    int topA;
    int bottomA;

    int leftB;
    int rightB;
    int topB;
    int bottomB;

    leftA = block_a->x;
    rightA = block_a->x + block_a->w;
    topA = block_a->y;
    bottomA = block_a->y + block_a->h;

    leftB = block_b->x;
    rightB = block_b->x + block_b->w;
    topB = block_b->y;
    bottomB = block_b->y + block_b->h;

    if (bottomA >= topB && SDL_HasIntersection(block_a, block_b)) {
        Pacman::PacmanInstance().stopOnCollision(0, -3);
    }
    if (rightA >= leftB && SDL_HasIntersection(block_a, block_b)) {
        Pacman::PacmanInstance().stopOnCollision(-3, 3);
    }
    if (topA <= bottomB && SDL_HasIntersection(block_a, block_b)) {
        Pacman::PacmanInstance().stopOnCollision(3, 3);
    }
    if (leftA <= rightB && SDL_HasIntersection(block_a, block_b)) {
        Pacman::PacmanInstance().stopOnCollision(3, -3);
    }
}

void GameManager::pacmanPickPill() {

    auto i = pills->pillRectList.begin();

    while (i != pills->pillRectList.end()) {

        if (SDL_HasIntersection(Pacman::PacmanInstance().getRect(), i.base())) {
            i = pills->pillRectList.erase(i++);
            if (pills->pillRectList.empty()) {
                clearScreen();
                victory();
            }
        } else {
            i++;
        }
    }
}

void GameManager::pacmmanTouchGhost(SDL_Rect *rect) {

    if (SDL_HasIntersection(Pacman::PacmanInstance().getRect(), rect)) {
        Pacman::PacmanInstance().looseHealth();
        if (Pacman::PacmanInstance().getHealth() == 0) {
            clearScreen();
            gameOver();
        }
    }
}

void GameManager::restartGame() {
    inGameMenu = false;
    tile->pushAllTiles();
    pills->pushAllPills();
    loadCharacters();
}

void GameManager::clearScreen() {
    inGameMenu = true;
    tile->tileRectList.clear();
    pills->pillRectList.clear();
    ghostRectList.clear();
}

void GameManager::gameOver() const {
    gameMenu->loadImage(renderer, "../resources/game_over.bmp");
}

void GameManager::victory() const {
    gameMenu->loadImage(renderer, "../resources/victory.bmp");
}







