//
// Created by Sindre Johan Vinje on 10/04/2020.
//


#include "Pills.h"
#include "Image.h"

Pills::Pills() = default;

void Pills::loadImage(SDL_Renderer *renderer, const char *surfaceFile) {
    Image::loadImage(renderer, surfaceFile);
}

void Pills::draw(SDL_Renderer *renderer) const {

    for (auto &currentPill : pillRectList) {
        SDL_RenderCopy(renderer, texture, nullptr, &currentPill);
    }
}

void Pills::pushAllPills() {

    if (!pillRectList.empty()) {
        pillRectList.clear();
    }

    pillRectList.reserve(144);
    const int pillWidth = 15;
    const int pillHeight = 25;

    int ypos = 20;
    int xpos = 25;
    int counter = 0;
    while (counter < 12) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        xpos += 55;
        counter++;
    }

    xpos = 630;
    ypos = 60;
    counter = 0;
    while (counter < 6) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        xpos += 55;
        counter++;
    }


    xpos = 25;
    ypos = 120;
    counter = 0;
    while (counter < 4) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        xpos += 55;
        counter++;
    }

    xpos = 135;
    ypos = 195;
    counter = 0;
    while (counter < 2) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        xpos += 55;
        counter++;
    }


    xpos = 25;
    ypos = 265;
    counter = 0;
    while (counter < 4) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        xpos += 55;
        counter++;
    }


    xpos = 25;
    ypos = 315;
    counter = 0;
    while (counter < 5) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        ypos += 65;
        counter++;
    }

    xpos = 80;
    ypos = 615;
    counter = 0;
    while (counter < 9) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        xpos += 55;
        counter++;
    }

    xpos = 320;
    ypos = 755;
    counter = 0;
    while (counter < 12) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        xpos += 55;
        counter++;
    }

    xpos = 190;
    ypos = 525;
    counter = 0;
    while (counter < 7) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        xpos += 55;
        counter++;
    }

    xpos = 190;
    ypos = 315;
    counter = 0;
    while (counter < 4) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        ypos += 55;
        counter++;
    }

    xpos = 580;
    ypos = 320;
    counter = 0;
    while (counter < 8) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        ypos += 55;
        counter++;
    }

    xpos = 525;
    ypos = 100;
    counter = 0;
    while (counter < 7) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        ypos += 55;
        counter++;
    }

    xpos = 630;
    ypos = 320;
    counter = 0;
    while (counter < 6) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        xpos += 55;
        counter++;
    }

    xpos = 960;
    ypos = 220;
    counter = 0;
    while (counter < 4) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        ypos += 55;
        counter++;
    }

    xpos = 630;
    ypos = 220;
    counter = 0;
    while (counter < 6) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        xpos += 55;
        counter++;
    }

    xpos = 740;
    ypos = 460;
    counter = 0;
    while (counter < 4) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        xpos += 55;
        counter++;
    }

    xpos = 700;
    ypos = 460;
    counter = 0;
    while (counter < 3) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        ypos += 55;
        counter++;
    }
    xpos = 700;
    ypos = 620;
    counter = 0;
    while (counter < 5) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        xpos += 55;
        counter++;
    }

    xpos = 960;
    ypos = 620;
    counter = 0;
    while (counter < 3) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        ypos += 55;
        counter++;
    }

    xpos = 920;
    ypos = 110;
    counter = 0;
    while (counter < 2) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        ypos += 55;
        counter++;
    }

    xpos = 630;
    ypos = 110;
    counter = 0;
    while (counter < 2) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        ypos += 55;
        counter++;
    }

    xpos = 320;
    ypos = 110;
    counter = 0;
    while (counter < 3) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        ypos += 55;
        counter++;
    }
    xpos = 350;
    ypos = 110;
    counter = 0;
    while (counter < 3) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        ypos += 55;
        counter++;
    }
    xpos = 380;
    ypos = 110;
    counter = 0;
    while (counter < 3) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        ypos += 55;
        counter++;
    }
    xpos = 410;
    ypos = 110;
    counter = 0;
    while (counter < 3) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        ypos += 55;
        counter++;
    }

    xpos = 320;
    ypos = 310;
    counter = 0;
    while (counter < 3) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        ypos += 55;
        counter++;
    }
    xpos = 350;
    ypos = 310;
    counter = 0;
    while (counter < 3) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        ypos += 55;
        counter++;
    }
    xpos = 380;
    ypos = 310;
    counter = 0;
    while (counter < 3) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        ypos += 55;
        counter++;
    }
    xpos = 410;
    ypos = 310;
    counter = 0;
    while (counter < 3) {
        pillRectList.emplace_back(SDL_Rect{xpos, ypos, pillWidth, pillHeight});
        ypos += 55;
        counter++;
    }

    pillRectList.emplace_back(SDL_Rect{25, 70, pillWidth, pillHeight});
    pillRectList.emplace_back(SDL_Rect{190, 70, pillWidth, pillHeight});
    pillRectList.emplace_back(SDL_Rect{525, 60, pillWidth, pillHeight});
    pillRectList.emplace_back(SDL_Rect{325, 660, pillWidth, pillHeight});
    pillRectList.emplace_back(SDL_Rect{325, 710, pillWidth, pillHeight});

}

