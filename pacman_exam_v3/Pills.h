//
// Created by Sindre Johan Vinje on 10/04/2020.
//

#ifndef PACMAN_EXAM_PILLS_H
#define PACMAN_EXAM_PILLS_H

#include <SDL.h>
#include <vector>
#include "Image.h"
#include <list>

class Pills : public Image {

public:

    Pills();

    void loadImage(SDL_Renderer *renderer, const char *surfaceFile) override;

    void draw(SDL_Renderer *renderer) const override;

    void pushAllPills();

    std::vector<SDL_Rect> pillRectList;
};


#endif //PACMAN_EXAM_PILLS_H
