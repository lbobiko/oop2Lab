#include "Car.h"
#include <iostream>
#include <stdexcept>   // potrzebne dla invalid_argument
#include "Constants.h"

Car::Car(const std::string& name, const std::string& color, double currentSpeed)
    : name(name), color(color),
      currentSpeed(currentSpeed),
      throttle(0.0),
      carBrake(false),
      carEngine()
{
    if (currentSpeed < 0 || currentSpeed > MAX_SPEED) {
        throw std::invalid_argument("Invalid speed - must be within 0 and 200");
    }
}

std::string Car::getName() {
    return name;
}

std::string Car::getColor() {
    return color;
}

double Car::getCurrentSpeed() {
    return currentSpeed;
}

void Car::setCurrentSpeed(double speed) {
    if (speed < 0) speed = 0;
    if (speed > MAX_SPEED) speed = MAX_SPEED;
    this->currentSpeed = speed;
}

void Car::drive(double speed) {
    if (speed < 0) speed = 0;
    if (speed > MAX_SPEED) speed = MAX_SPEED;
    this->currentSpeed = speed;
}

void Car::stop() {
    if (currentSpeed > 0) {
        currentSpeed = 0;
    }
}

void Car::show() {
    std::cout << name << " jedzie " << currentSpeed << " km/h" << std::endl;
    std::cout << "hamulec: " << carBrake.getPressed() << std::endl;
    std::cout << "silnik: " << carEngine.get_running() << std::endl;
}

double Car::getThrottle() {
    return throttle;
}

void Car::setThrottle(double throttle) {
    this->throttle = throttle;
}

void Car::update(double dt) {
    if (!carEngine.get_running()) return;
    if (carBrake.getPressed()) {
        currentSpeed -= BRAKE_DECEL * DT;
    }
    if (throttle > 0) {
        currentSpeed += ACCELERATION * throttle * DT;
    } else {
        currentSpeed -= COAST_DECEL * DT;
    }
    if (currentSpeed < 0) {
        currentSpeed = 0;
    }
    if (currentSpeed > MAX_SPEED) {
        currentSpeed = MAX_SPEED;
    }

}