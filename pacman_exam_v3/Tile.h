//
// Created by Sindre Johan Vinje on 01/04/2020.
//

#ifndef PACMAN_EXAM_TILE_H
#define PACMAN_EXAM_TILE_H

#include <SDL.h>
#include <memory>
#include <vector>


class Tile {

public:

    Tile();

    void pushAllTiles();

    void drawRects(SDL_Renderer *renderer);

    std::vector<SDL_Rect> tileRectList;

private:

    int r = 0;
    int g = 0;
    int b = 0;


};


#endif //PACMAN_EXAM_TILE_H
