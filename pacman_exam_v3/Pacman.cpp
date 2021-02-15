//
// Created by Sindre Johan Vinje on 01/04/2020.
//


#include "Pacman.h"

Pacman::Pacman() {}

void Pacman::loadImage(SDL_Renderer *renderer, const char *surfaceFile) {
    Image::loadImage(renderer, surfaceFile);
    pacmanRect = {20, 180, 50, 50};
    direction = NONE;
}
void Pacman::initHealth() {

    if (!healthBar.empty()) {
        healthBar.clear();
    }
    pacmanHealth = 3;
    healthBar.reserve(pacmanHealth);
    healthBar.emplace_back(SDL_Rect{25, 730, 50, 50});
    healthBar.emplace_back(SDL_Rect{108, 730, 50, 50});
    healthBar.emplace_back(SDL_Rect{190, 730, 50, 50});
}


int Pacman::getHealth() const {
    return pacmanHealth;
}

void Pacman::looseHealth() {

    if (pacmanHealth > 0) {
        healthBar.erase(healthBar.begin() + pacmanHealth - 1);
    }
    pacmanHealth -= 1;
    pacmanRect.x = 20;
    pacmanRect.y = 180;

    direction = NONE;
    angle = 0;
    flipType = SDL_FLIP_NONE;
}

void Pacman::drawHealthBar(SDL_Renderer *renderer) {
    for (const auto &current : healthBar) {

        SDL_RenderCopy(renderer, texture, nullptr, &current);
    }
}

void Pacman::draw(SDL_Renderer *renderer) const {
    SDL_RenderCopyEx(renderer, texture, nullptr, &pacmanRect, angle, nullptr, flipType);
}
SDL_Rect *Pacman::getRect() {
    return &pacmanRect;
}
void Pacman::constantMove() {
    Image::constantMove(pacmanRect);
}

void Pacman::stopOnCollision(int &&x, int &&y) {

    pacmanRect.x += x;
    pacmanRect.y += y;
}



















