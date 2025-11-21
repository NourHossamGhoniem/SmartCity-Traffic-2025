#pragma once

#include "vehicle.h"
#include "Queue.h"
#include "PriorityQue.h"

class Intersection {
public:
    PriorityQueue<vehicle*> emergencyvqueue;
    Queue<vehicle*> PTqueue;
    Queue<vehicle*> NCqueue;
    Queue<vehicle*> FVqueue;

    Intersection() {}
};