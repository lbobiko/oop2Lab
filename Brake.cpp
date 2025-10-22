#include "Brake.h"

Brake::Brake(bool pressed) {
    this->pressed = pressed;
}

bool Brake::getPressed() {
    return pressed;
}

void Brake::setPressed(bool pressed) {
    this->pressed = pressed;
}
