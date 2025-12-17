#pragma once


class vehicle {
public:
    int ID;

    char type;

    int arrivaltime;

    int crossingtime;
    int priority;
    int laneid;
    int intersectionno;
    vehicle(int id, char t, int arr, int cross, int pr = 0,int li,int in) {
        ID = id;
        type = t;
        arrivaltime = arr;
        crossingtime = cross;
        priority = pr;
        laneid = li;
        intersectionno = in;
    }
};

