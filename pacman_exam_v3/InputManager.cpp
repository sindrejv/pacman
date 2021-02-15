//
// Created by Sindre Johan Vinje on 07/03/2020.
//

#include "InputManager.h"


InputManager::InputManager() {

    int numKeys;
    keys = SDL_GetKeyboardState(&numKeys);
}

void InputManager::Update() {

    SDL_PumpEvents();
}







