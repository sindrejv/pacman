//
// Created by Sindre Johan Vinje on 01/04/2020.
//

#ifndef PACMAN_EXAM_PACMAN_H
#define PACMAN_EXAM_PACMAN_H

#include <SDL.h>

#include "Image.h"

class Pacman : public Image {


public:

    static Pacman &PacmanInstance() {
        static Pacman instance;
        return instance;
    }

    void loadImage(SDL_Renderer *renderer, const char *surfaceFile) override;

    void draw(SDL_Renderer *renderer) const override;

    void stopOnCollision(int &&x, int &&y);

    SDL_Rect *getRect();

    void constantMove();

    int getHealth() const;

    void looseHealth();

    void initHealth();

    void drawHealthBar(SDL_Renderer *renderer);

    SDL_Rect pacmanRect;


private:
    Pacman();

    std::vector<SDL_Rect> healthBar;
    int pacmanHealth = 3;


};


#endif //PACMAN_EXAM_PACMAN_H
