//
// Created by Sindre Johan Vinje on 07/03/2020.
//

#ifndef SDL_TEST_INPUTMANAGER_H
#define SDL_TEST_INPUTMANAGER_H


#include <SDL_surface.h>
#include <memory>
#include <vector>
#include <SDL.h>
#include "GameManager.h"


class InputManager {

public:

    static InputManager &Instance() {
        static InputManager instance;
        return instance;
    }
    void Update();

    bool KeyDown(int keyIndex) const {
        return (keys[keyIndex]);
    }
private:

    const Uint8 *keys;

    InputManager();

};

#endif //SDL_TEST_INPUTMANAGER_H
