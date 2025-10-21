#include "Brake.h"

Brake::Brake(bool pressed) {
    this->pressed = pressed;
}

bool Brake::getPressed() {
    return pressed;
}

bool Brake::setPressed(bool pressed) {
    this->pressed = pressed;
}
