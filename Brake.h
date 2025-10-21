#ifndef OOP2LAB_BRAKE_H
#define OOP2LAB_BRAKE_H


class Brake {
private:
    bool pressed;
public:
    Brake(bool pressed);
    bool getPressed();
    bool setPressed(bool);
};


#endif //OOP2LAB_BRAKE_H