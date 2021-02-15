//
// Created by Sindre Johan Vinje on 06/04/2020.
//

#include <iostream>
#include "Image.h"

Image::Image() = default;

void Image::loadImage(SDL_Renderer *renderer, const char* surfaceFile) {

    surface = SDL_LoadBMP(surfaceFile);
    if (surface == nullptr) {
        std::cout << "failed to load image" << SDL_GetError() << std::endl;
        SDL_Quit();
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr) {
        std::cout << "failed to create texture from surface" <<  SDL_GetError() << std::endl;
        SDL_Quit();
    }

    SDL_FreeSurface(surface);
}


void Image::changeDirection(int&& x, int&& y) {

    if (x > 0) {
        direction = RIGHT;
    }
    if (x < 0) {
        direction = LEFT;
    }
    if (y > 0) {
        direction = DOWN;
    }
    if (y < 0) {
        direction = UP;
    }
}

void Image::constantMove(SDL_Rect &rect) {

    if (direction == NONE) {
        rect.x += 0;
        rect.y += 0;
        flipType = SDL_FLIP_NONE;
    }
    if (direction == RIGHT) {
        rect.x += characterSpeed;
        rect.y += 0;
        angle = 0;
        flipType = SDL_FLIP_NONE;
    }
    if (direction == LEFT) {
        rect.x -= characterSpeed;
        rect.y += 0;
        angle = 0;
        flipType = SDL_FLIP_HORIZONTAL;
    }
    if (direction == UP) {
        rect.x += 0;
        rect.y -= characterSpeed;
        angle = -90;
        flipType = SDL_FLIP_NONE;
    }
    if (direction == DOWN) {
        rect.x += 0;
        rect.y += characterSpeed;
        angle = 90;
        flipType = SDL_FLIP_NONE;
    }
}







