#pragma once

class TrafficLight {
private:
    int greenLane;
    int switchTimer;
    int switchCost;
    int numSwitches;

public:
    TrafficLight(int cost = 0) {
        greenLane = 0;
        switchTimer = 0;
        switchCost = cost;
        numSwitches = 0;
    }

    int getGreenLane() const {
        return greenLane;
    }

    int getNumSwitches() const {
        return numSwitches;
    }

    bool isSwitching() const {
        return switchTimer > 0;
    }

    void requestSwitch(int newLane) {
        if (newLane != greenLane && switchTimer == 0) {
            greenLane = newLane;
            switchTimer = switchCost;
            numSwitches++;
        }
    }

    void update() {
        if (switchTimer > 0)
            switchTimer--;
    }
};

