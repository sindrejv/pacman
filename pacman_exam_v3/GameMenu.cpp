//
// Created by Sindre Johan Vinje on 11/04/2020.
//

#include "GameMenu.h"

GameMenu::GameMenu() = default;

void GameMenu::loadImage(SDL_Renderer *renderer, const char *surfaceFile) {
    Image::loadImage(renderer, surfaceFile);
}

void GameMenu::draw(SDL_Renderer* renderer) const {
    SDL_RenderCopy(renderer, texture, nullptr, &menuRect);
}






