#include "Car.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
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

std::string Car::getName() const
{
    return name;
}

std::string Car::getColor() const {
    return color;
}

double Car::getCurrentSpeed() const {
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
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n--- STAN SAMOCHODU ---" << std::endl;
    std::cout << "Nazwa: " << name << std::endl;
    std::cout << "Prędkość: " << currentSpeed << " km/h" << std::endl;
    std::cout << "Hamulec: " << (carBrake.getPressed() ? "WCIŚNIĘTY" : "ZWOLNIONY") << std::endl;
    std::cout << "Silnik: " << (carEngine.get_running() ? "WŁĄCZONY" : "WYŁĄCZONY") << std::endl;
    std::cout << "Dystans: " << distance << " km" << std::endl;
}

double Car::getThrottle() const {
    return throttle;
}

void Car::setThrottle(double throttle) {
    this->throttle = std::clamp(throttle, 0.0, 1.0);
}

void Car::update(double dt) {
    //if (!carEngine.get_running()) return;
    if (carBrake.getPressed()) {
        currentSpeed -= BRAKE_DECEL * dt;
    }
    if (throttle > 0) {
        currentSpeed += ACCELERATION * throttle * dt;
    } else {
        currentSpeed -= COAST_DECEL * dt;
    }
    if (currentSpeed < 0) {
        currentSpeed = 0;
    }
    if (currentSpeed > MAX_SPEED) {
        currentSpeed = MAX_SPEED;
    }
    distance += (currentSpeed * dt) / 3.6;

}

bool Car::getBrake() const {
    return carBrake.getPressed();
}
void Car::setBrake(bool brake) {
    carBrake = brake;
}

bool Car::getEngine() const {
    return carEngine.get_running();
}

void Car::setEngine(bool) {
    carEngine.set_running(true);
}

double Car::getDistance() const {
    return distance;
}
