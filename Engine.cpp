//
// Created by Łukasz Bobiński on 21/10/2025.
//

#include "Engine.h"

Engine::Engine() {
    running = true;
}

bool Engine::get_running() const {
    return running;
}

void Engine::set_running(bool run) {
    running = run;
}
