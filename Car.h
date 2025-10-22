#ifndef OOP2LAB_CAR_H
#define OOP2LAB_CAR_H
#include <string>

#include "Brake.h"
#include "Engine.h"


class Car {
private:
    std::string name;
    std::string color;
    double currentSpeed;
    double throttle;
    Brake carBrake;
    Engine carEngine;

public:
    Car(const std::string& name, const std::string& color, double currentSpeed);
    std::string getName();
    std::string getColor();
    double getCurrentSpeed();
    void setCurrentSpeed(double speed);
    void drive(double speed);
    void stop();
    void show();
    double getThrottle();
    void setThrottle(double);
    void update(double dt);

};




#endif //OOP2LAB_CAR_H