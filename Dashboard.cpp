#include "Dashboard.h"
#include "Car.h"
#include <iostream>
#include <iomanip>

void Dashboard::render(const Car& car) {
    // Ustawienia formatowania (2 miejsca po przecinku)
    std::cout << std::fixed << std::setprecision(2);

    // Kolory ANSI
    const std::string green = "\033[32m";
    const std::string red   = "\033[31m";
    const std::string yellow = "\033[33m";
    const std::string reset = "\033[0m";

    std::cout << "================ DASHBOARD ================\n";
    std::cout << "Nazwa auta: "   << car.getName() << " (" << car.getColor() << ")\n";
    std::cout << "Predkosc:       " << car.getCurrentSpeed() << " km/h\n";
    std::cout << "Throttle:       " << car.getThrottle() << "\n";
    std::cout << "Silnik:         "
              << (car.getEngine() ? green + "ON" + reset : red + "OFF" + reset) << "\n";
    std::cout << "Hamulec:        "
              << (car.getBrake() ? yellow + "ON" + reset : "OFF") << "\n";
    std::cout << "Dystans:        " << car.getDistance() / 1000.0 << " km\n";
    std::cout << "==========================================\n";
    std::cout << "[Controls:]\n\xE2\x86\x91/\xE2\x86\x93 throttle   SPACE brake   E engine   Q quit\n";
}