//
// Created by Sindre Johan Vinje on 30/03/2020.
//

#ifndef PACMAN_EXAM_GAMEMANAGER_H
#define PACMAN_EXAM_GAMEMANAGER_H

#include <SDL.h>
#include "InputManager.h"
#include "Ghost.h"
#include <memory>
#include <thread>
#include "Tile.h"
#include "Pills.h"
#include "GameMenu.h"


class GameManager {

public:
    bool running;

    void cap_fps(std::chrono::time_point<std::chrono::steady_clock> currentFrame) const;

    void init(const char *title, int xpos, int ypos, int window_witdh, int window_hight, int screen);

    void eventHandler();

    void render();

    void clean();

    void pacmmanTouchGhost(SDL_Rect *rect);

    void characterActions();

private:
    SDL_Event event;
    const int fps = 50;

    bool inGameMenu = false;


    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    std::vector<std::shared_ptr<Ghost>> ghostRectList;
    std::unique_ptr<Tile> tile = std::make_unique<Tile>();
    std::unique_ptr<Pills> pills = std::make_unique<Pills>();
    std::unique_ptr<GameMenu> gameMenu = std::make_unique<GameMenu>();

    void pollEvent();

    void checkPacmanCollisionWithWalls(SDL_Rect *block_a, SDL_Rect *block_b);

    void loadCharacters();

    void restartGame();

    void pacmanPickPill();

    void clearScreen();

    void victory() const;

    void gameOver() const;

    void drawImages() const;
};


#endif //PACMAN_EXAM_GAMEMANAGER_H
