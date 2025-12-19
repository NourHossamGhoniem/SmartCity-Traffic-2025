#include <iostream>
Using namespace std;
#include "../Headers/TrafficLight.h"

TrafficLight::TrafficLight(int cost) {
    greenLane = 0;
    switchTimer = 0;
    switchCost = cost;
    numSwitches = 0;
}

int TrafficLight::getGreenLane() const {
    return greenLane;
}

int TrafficLight::getNumSwitches() const {
    return numSwitches;
}

bool TrafficLight::isSwitching() const {
    return switchTimer > 0;
}

void TrafficLight::requestSwitch(int newLane) {
    if (newLane != greenLane && switchTimer == 0) {
        greenLane = newLane;
        switchTimer = switchCost;
        numSwitches++;
    }
}

void TrafficLight::update() {
    if (switchTimer > 0)
        switchTimer--;
}
