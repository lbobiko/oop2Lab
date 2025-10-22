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
    double distance = 0.0;

public:
    Car(const std::string& name, const std::string& color, double currentSpeed);
    std::string getName() const;
    std::string getColor() const;
    double getCurrentSpeed() const;
    void setCurrentSpeed(double speed);
    void drive(double speed);
    void stop();
    void show();
    double getThrottle() const;
    void setThrottle(double);
    void update(double dt);
    bool getBrake() const;
    void setBrake(bool);
    bool getEngine() const;
    void setEngine(bool);
    double getDistance() const;
};




#endif //OOP2LAB_CAR_H