#include <iostream>
#include <string>
#include "Car.h"
#include "Constants.h"

using namespace std;

int main() {
    //Car* toyota = new Car("Toyota", "Green", 30);
    Car c1("Toyota", "Green", 0);
    c1.show();
    c1.setCurrentSpeed(100);
    c1.show();

    //delete toyota;
    return 0;
}