//
// Created by Sindre Johan Vinje on 06/04/2020.
//

#ifndef PACMAN_EXAM_IMAGE_H
#define PACMAN_EXAM_IMAGE_H

#include <SDL.h>
#include <vector>


class Image {
public:

    Image();

    virtual void loadImage(SDL_Renderer *renderer, const char *surfaceFile);

    virtual void draw(SDL_Renderer *renderer) const = 0;

    virtual void constantMove(SDL_Rect &rect);

    void changeDirection(int &&x, int &&y);


protected:
    SDL_Surface *surface = nullptr;
    SDL_Texture *texture = nullptr;

    SDL_RendererFlip flipType = SDL_FLIP_NONE;
    double angle{};

    enum Direction {
        NONE, UP, DOWN, LEFT, RIGHT
    } direction;

    const int characterSpeed = 3;


};


#endif //PACMAN_EXAM_IMAGE_H
