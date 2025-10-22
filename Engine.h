#ifndef OOP2LAB_ENGINE_H
#define OOP2LAB_ENGINE_H


class Engine {
private:
    bool running;
public:
    Engine();
    //~Engine();
    //void run();
    bool get_running();
    void set_runnig(bool run);
};


#endif //OOP2LAB_ENGINE_H