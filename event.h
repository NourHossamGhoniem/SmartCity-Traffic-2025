#pragma once


class event {
public:
    char eventtype;   

    int eventtime;
    
    int vehicleid;


    event(char type, int time, int vid) {
        eventtype = type;
        eventtime = time;
        vehicleid = vid;
    }
};



