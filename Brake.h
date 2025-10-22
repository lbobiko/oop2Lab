#ifndef OOP2LAB_BRAKE_H
#define OOP2LAB_BRAKE_H


class Brake {
private:
    bool pressed;
public:
    Brake(bool pressed);
    bool getPressed() const;
    void setPressed(bool);
};


#endif //OOP2LAB_BRAKE_H