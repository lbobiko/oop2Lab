#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Car.h"
#include "Constants.h"

using namespace std;

int main() {
    //Car* toyota = new Car("Toyota", "Green", 30);
    Car c1("Toyota", "Green", 0);
    c1.show();
    bool running = true;

    c1.setThrottle(1.0);

    while (running) {
        c1.update(DT);
        c1.show();
        std::this_thread::sleep_for(std::chrono::duration<double>(DT));
    }

    //delete toyota;
    return 0;
}