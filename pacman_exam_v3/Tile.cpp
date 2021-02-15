//
// Created by Sindre Johan Vinje on 01/04/2020.
//

#include "Tile.h"


Tile::Tile() = default;

void Tile::drawRects(SDL_Renderer *renderer) {
    for (auto &currentRect : tileRectList) {
        SDL_SetRenderDrawColor(renderer, r, g, b, 255);
        SDL_RenderFillRect(renderer, &currentRect);
    }
}

void Tile::pushAllTiles() {

    tileRectList.reserve(29);

    //Top
    tileRectList.emplace_back(SDL_Rect{0,-5,1000,10});
    //Left
    tileRectList.emplace_back(SDL_Rect{-5, 0, 10, 800});
    //Bottom
    tileRectList.emplace_back(SDL_Rect{0, 795, 1000, 10});
    //Right
    tileRectList.emplace_back(SDL_Rect{995, 0, 10, 800});

    //Life container
    tileRectList.emplace_back(SDL_Rect{0, 650, 295, 60});
    tileRectList.emplace_back(SDL_Rect{270, 650, 25, 200});
    //First column
    tileRectList.emplace_back(SDL_Rect{0, 160, 140, 20});
    tileRectList.emplace_back(SDL_Rect{0, 230, 80, 20});
    tileRectList.emplace_back(SDL_Rect{60, 60, 100, 40});

    tileRectList.emplace_back(SDL_Rect{65, 305, 100, 285});

    //S
    tileRectList.emplace_back(SDL_Rect{450, 60, 50, 120});
    tileRectList.emplace_back(SDL_Rect{260, 60, 200, 50});
    tileRectList.emplace_back(SDL_Rect{230, 60, 70, 200});
    tileRectList.emplace_back(SDL_Rect{230, 250, 270, 50});
    tileRectList.emplace_back(SDL_Rect{450, 250, 50, 200});
    tileRectList.emplace_back(SDL_Rect{230, 450, 270, 50});
    tileRectList.emplace_back(SDL_Rect{230, 370, 50, 120});

    //Lowest row
    tileRectList.emplace_back(SDL_Rect{150, 560, 400, 30});
    tileRectList.emplace_back(SDL_Rect{360, 650, 190, 90});

    //Right of S
    tileRectList.emplace_back(SDL_Rect{620, 360, 60, 300});
    tileRectList.emplace_back(SDL_Rect{500, 470, 60, 30});

    //Zigzag
    tileRectList.emplace_back(SDL_Rect{620, 360, 300, 80});
    tileRectList.emplace_back(SDL_Rect{755, 500, 240, 90});
    tileRectList.emplace_back(SDL_Rect{620, 650, 310, 90});

    //Enclave
    tileRectList.emplace_back(SDL_Rect{570, 260, 370, 40});
    tileRectList.emplace_back(SDL_Rect{570, 60, 40, 240});
    tileRectList.emplace_back(SDL_Rect{960, 0, 40, 200});
    tileRectList.emplace_back(SDL_Rect{690, 0, 380, 40});
    tileRectList.emplace_back(SDL_Rect{670, 100, 220, 110});
}
















