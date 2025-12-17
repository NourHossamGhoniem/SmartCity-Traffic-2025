#pragma once
#include "vehicle.h"
#include "Queue.h"
#include "PriorityQue.h"
#include "TrafficLight.h"

class Intersection {
private:
    TrafficLight light;

public:
    PriorityQueue<vehicle*> emergencyvqueue;
    Queue<vehicle*> PTqueue;
    Queue<vehicle*> NCqueue;
    Queue<vehicle*> FVqueue;

    Intersection() {}

    void addVehicle(vehicle* v) {
        if (v->type == 'E') emergencyvqueue.enqueue(v);
        else if (v->type == 'P') PTqueue.enqueue(v);
        else if (v->type == 'F') FVqueue.enqueue(v);
        else NCqueue.enqueue(v);
    }

    vehicle* getNextVehicle() {
        if (!emergencyvqueue.isEmpty()) return emergencyvqueue.dequeue();
        if (!PTqueue.isEmpty()) return PTqueue.dequeue();
        if (!FVqueue.isEmpty()) return FVqueue.dequeue();
        if (!NCqueue.isEmpty()) return NCqueue.dequeue();
        return nullptr;
    }
};
