
#include <memory>
#include <SDL.h>
#include "InputManager.h"
#include <thread>


int main(int argc, char *args[]) {

    auto gameManager = std::make_unique<GameManager>();

    gameManager->init(
            "Pacman",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            1000,
            800,
            SDL_WINDOW_SHOWN);


    auto currentFrame = std::chrono::high_resolution_clock::now();

    while (gameManager->running) {

        gameManager->cap_fps(currentFrame);
        gameManager->eventHandler();
        gameManager->characterActions();
        gameManager->render();
        InputManager::Instance().Update();
    }
    gameManager->clean();
}

