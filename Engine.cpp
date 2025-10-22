//
// Created by Łukasz Bobiński on 21/10/2025.
//

#include "Engine.h"

Engine::Engine() {
    running = true;
}

bool Engine::get_running() {
    return running;
}

void Engine::set_runnig(bool run) {
    running = run;
}
