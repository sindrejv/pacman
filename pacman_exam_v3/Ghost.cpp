//
// Created by Sindre Johan Vinje on 06/04/2020.
//

#include "Ghost.h"
#include <random>


Ghost::Ghost() {}


void Ghost::loadImage(SDL_Renderer *renderer, const char *surfaceFile) {

    Image::loadImage(renderer, surfaceFile);
    ghostRect = {300, 180, 50, 50};
    direction = RIGHT;
}

void Ghost::constantMove() {
    Image::constantMove(ghostRect);
}

void Ghost::onCollision(SDL_Rect *tileBlock) {
    int ghostRight;
    int ghostLeft;
    int ghostTop;
    int ghostBottom;

    int tileLeft;
    int tileRight;
    int tileTop;
    int tileBottom;

    ghostLeft = ghostRect.x;
    ghostRight = ghostRect.x + ghostRect.w;
    ghostTop = ghostRect.y;
    ghostBottom = ghostRect.y + ghostRect.h;

    tileLeft = tileBlock->x;
    tileRight = tileBlock->x + tileBlock->w;
    tileTop = tileBlock->y;
    tileBottom = tileBlock->y + tileBlock->h;

    if (ghostBottom >= tileTop && SDL_HasIntersection(&ghostRect, tileBlock)) {
        ghostRect.x += 0;
        ghostRect.y -= characterSpeed;
        randomDirection();
    }
    if ((ghostRight >= tileLeft) && SDL_HasIntersection(&ghostRect, tileBlock)) {
        ghostRect.x -= characterSpeed;
        ghostRect.y += characterSpeed;
        randomDirection();
    }
    if ((ghostTop <= tileBottom) && SDL_HasIntersection(&ghostRect, tileBlock)) {
        ghostRect.x += characterSpeed;
        ghostRect.y += characterSpeed;
        randomDirection();
    }
    if ((ghostLeft <= tileRight) && SDL_HasIntersection(&ghostRect, tileBlock)) {
        ghostRect.x += characterSpeed;
        ghostRect.y -= characterSpeed;
        randomDirection();
    }
}



void Ghost::draw(SDL_Renderer *renderer) const {

    SDL_RenderCopyEx(renderer, texture, nullptr, &ghostRect, angle, nullptr, flipType);
}

void Ghost::randomDirection() {

    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 3);
    dist(rd);

    int directionNumber = dist(rd);
    switch (directionNumber) {
        case 0:
            direction = UP;
            break;
        case 1:
            direction = DOWN;
            break;
        case 2:
            direction = RIGHT;
            break;
        case 3:
            direction = LEFT;
            break;
        default:
            break;
    }
}


