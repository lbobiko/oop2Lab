#ifndef OOP2LAB_CAR_H
#define OOP2LAB_CAR_H
#include <string>


class Car {
private:
    std::string name;
    std::string color;
    int currentSpeed;

public:
    Car(std::string name, std::string color, int currentSpeed);
    std::string getName();
    std::string getColor();
    int getCurrentSpeed();
    void setCurrentSpeed(int speed);
    void drive(int speed);
    void stop();
    void show();

};


#endif //OOP2LAB_CAR_H