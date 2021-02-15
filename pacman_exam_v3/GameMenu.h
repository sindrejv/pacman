//
// Created by Sindre Johan Vinje on 11/04/2020.
//

#ifndef PACMAN_EXAM_GAMEMENU_H
#define PACMAN_EXAM_GAMEMENU_H


#include "Image.h"

class GameMenu : public Image {

public:
    GameMenu();

    void loadImage(SDL_Renderer *renderer, const char *surfaceFile) override;

    void draw(SDL_Renderer *renderer) const override;

private:
    SDL_Rect menuRect = {120, 0, 800, 600};


};


#endif //PACMAN_EXAM_GAMEMENU_H
