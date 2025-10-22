#include "Brake.h"

Brake::Brake(bool pressed) {
    this->pressed = pressed;
}

bool Brake::getPressed() const {
    return pressed;
}

void Brake::setPressed(bool pressed) {
    this->pressed = pressed;
}
