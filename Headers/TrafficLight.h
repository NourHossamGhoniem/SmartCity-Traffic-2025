#pragma once
#include <iostream>
using namespace std;

class TrafficLight {
private:
    int greenLane;
    int switchTimer;
    int switchCost;
    int numSwitches;

public:
    TrafficLight(int cost = 0);

    int getGreenLane() const;
    int getNumSwitches() const;
    bool isSwitching() const;

    void requestSwitch(int newLane);
    void update();
};


