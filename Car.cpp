#include "Car.h"

#include <iostream>
#include <ostream>

#include "Constants.h"

Car::Car(std::string name, std::string color, int currentSpeed) {
    this->name = name;
    this->color = color;
    if (currentSpeed > MAX_SPEED || currentSpeed < 0) {
        throw std::invalid_argument("Invalid speed - must be within 0 and 200");
    } else {
        this->currentSpeed = currentSpeed;
    }
}

std::string Car::getName () {
    return name;
}
std::string Car::getColor () {
    return color;
}
int Car::getCurrentSpeed () {
    return currentSpeed;
}

void Car::setCurrentSpeed(int speed) {
    if (speed > MAX_SPEED || speed < 0) {
        throw std::invalid_argument("Invalid speed - must be within 0 and 200");
    } else {
        this->currentSpeed = speed;
    }
}

void Car::drive(int speed) {
    if (speed ==0) {
        this->currentSpeed = 10;
    }
}

void Car::stop() {
    if (currentSpeed > 0) {
        currentSpeed = 0;
    }
}

void Car::show() {
    std::cout << name;
    std::cout << " jedzie " << currentSpeed << " km/h" << std::endl;
}