//
// Created by Sindre Johan Vinje on 06/04/2020.
//

#ifndef PACMAN_EXAM_GHOST_H
#define PACMAN_EXAM_GHOST_H

#include <SDL.h>
#include <vector>
#include "Image.h"


class Ghost : public Image {


public:
    Ghost();

    void loadImage(SDL_Renderer *renderer, const char *surfaceFile) override;

    void draw(SDL_Renderer *renderer) const override;

    void onCollision(SDL_Rect *tileBlock);

    void constantMove();

    SDL_Rect ghostRect;

private:

    void randomDirection();
};


#endif //PACMAN_EXAM_GHOST_H
