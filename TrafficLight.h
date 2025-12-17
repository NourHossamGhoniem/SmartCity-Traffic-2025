#pragma once

class TrafficLight {
private:
    int greenLane;
    int switchTimer;

public:
    TrafficLight() {
        greenLane = 0;
        switchTimer = 0;
    }

    int getGreenLane() const {
        return greenLane;
    }

    void switchLane(int newLane, int cost) {
        if (newLane != greenLane) {
            greenLane = newLane;
            switchTimer = cost;
        }
    }

    void update() {
        if (switchTimer > 0)
            switchTimer--;
    }

    bool isSwitching() const {
        return switchTimer > 0;
    }
};
