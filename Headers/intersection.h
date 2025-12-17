#pragma once

#include "../Headers/vehicle.h"
#include "../Headers/Queue.h"
#include "../Headers/PriorityQue.h"
#include "../Headers/TrafficLight.h"


class Intersection {
private:
    TrafficLight light;
    vehicle* crossingVehicle[4];
    bool laneBlocked[4];
    bool intersectionClosed;
    int closureTimer;
    int busyTime;
    int totalVehiclesCrossed;

public:
    PriorityQueue<vehicle*> EVqueue;
    Queue<vehicle*> PTqueue;
    Queue<vehicle*> FVqueue;
    Queue<vehicle*> NCqueue;

    Intersection(int switchingCost = 0) : light(switchingCost) {
        for (int i = 0; i < 4; i++) {
            crossingVehicle[i] = nullptr;
            laneBlocked[i] = false;
        }
        intersectionClosed = false;
        closureTimer = 0;
        busyTime = 0;
        totalVehiclesCrossed = 0;
    }

    void addVehicle(vehicle* v) {
        if (v->type == 'E') EVqueue.enqueue(v);
        else if (v->type == 'P') PTqueue.enqueue(v);
        else if (v->type == 'F') FVqueue.enqueue(v);
        else NCqueue.enqueue(v);
    }

    void schedule(int currentTime) {
        if (intersectionClosed) return;
        if (light.isSwitching()) return;

        int lane = light.getGreenLane();
        if (laneBlocked[lane]) return;
        if (crossingVehicle[lane] && crossingVehicle[lane]->type == 'F') return;

        vehicle* next = nullptr;

        if (!EVqueue.isEmpty()) next = EVqueue.dequeue();
        else if (!PTqueue.isEmpty()) next = PTqueue.dequeue();
        else if (!FVqueue.isEmpty()) next = FVqueue.dequeue();
        else if (!NCqueue.isEmpty()) next = NCqueue.dequeue();

        if (next) {
            crossingVehicle[lane] = next;
            next->remainingcrossing = next->crossingtime;
        }
    }

    void updateCrossing(int currentTime) {
        bool active = false;

        for (int i = 0; i < 4; i++) {
            if (crossingVehicle[i]) {
                crossingVehicle[i]->remainingcrossing--;
                active = true;

                if (crossingVehicle[i]->remainingcrossing <= 0) {
                    crossingVehicle[i]->completiontime = currentTime;
                    crossingVehicle[i] = nullptr;
                    totalVehiclesCrossed++;
                }
            }
        }

