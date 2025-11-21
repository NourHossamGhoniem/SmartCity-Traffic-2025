#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "Organizer.h" 
#include "vehicle.h"
#include "event.h"
#include "intersection.h" 

using namespace std;
const string INPUT_FILENAME = "input.txt";

void LoadSimulationData(Organizer& organizer) {
    ifstream inputFile(INPUT_FILENAME);
    if (!inputFile.is_open()) {
        cout << "error: could not open input file \"" << INPUT_FILENAME << "\"the file doesn't exist" << endl;
        return;
    }
    int I, cost, ap, ct;
    string flag;
    int NumEvents;
    string line;

    // bn2ra awl 5 lines fel input.text ----------------------------------------------------------------------------
    if (!(inputFile >> I >> cost >> ap >> ct >> flag)) {
        cout << "error: failed to read global configuration " << endl;
        return;
    }
    organizer.setNumIntersections(I);
    organizer.setSwitchingCost(cost);
    organizer.setAPThreshold(ap);
    organizer.setCancelTThreshold(ct);
    organizer.setReroutingFlag(flag);

    // b3d keda el Connections-------------------------------------------------------------------------------------------
    if (!(inputFile >> line) || line != "Connections:") {
        cout << "error: expected 'Connections:' header but found " << line << endl;
        return;
    }
    organizer.resizeReroutingMap(I);
    for (int i = 1; i <= I; ++i) {
        if (!getline(inputFile, line) && i <= I) {
            cout << "error: rerouting map incomplete" << endl;
            return;
        }
        stringstream ss(line);
        int currentInt;
        char colon;
        int neighbor;
        if (!(ss >> currentInt >> colon) || colon != ':') continue;
        while (ss >> neighbor) {
            organizer.addReroutingConnection(currentInt, neighbor);
        }
    }
    
    // b3d keda el events ------------------------------------------------------------------------------------------------
    if (!(inputFile >> NumEvents)) {
        cout << "error: failed to read event count" << endl;
        return;
    }
    for (int i = 0; i < NumEvents; ++i) {
        string EventType;
        if (!(inputFile >> EventType)) break;

    // ( AT=ArrivalTime / ID=VehicleID / INT=Intersection / LN=Lane / XD=CrossingTime / DUR=Duration / PR=Priority )
        int AT, ID, INT, LN, XD, DUR, PR;
    // hn3ml check 3ala no3 el event 3ala4an mayeb2a4 fi conflict fel switch
        if (EventType == "ACC") {
            if (!(inputFile >> AT >> INT >> LN >> DUR)) break;
            Event* newEvent = new AccidentEvent(AT,INT,LN,DUR);
            organizer.addEvent(newEvent);
        }
        else {
            char TypeChar = EventType[0];
            switch (TypeChar) {
            case 'A': {
                string VehicleType;
                if (!(inputFile >> VehicleType >> AT >> ID >> INT >> LN >> XD)) break;
                PR = 0;
                char VehicleTypeChar = VehicleType[0];
                if (VehicleType == "EV") {
                    if (!(inputFile >> PR)) break;
                }

                // vehicle.h ( int id / char t / int arr / int intID / int laneID / int cross / int pr = 0 )
                vehicle* newVehicle = new vehicle(ID,VehicleTypeChar,AT,INT,LN,XD,PR);
                organizer.addVehicle(newVehicle);
                Event* newEvent = new ArrivalEvent(AT,newVehicle,INT,LN);
                organizer.addEvent(newEvent);
                break;
            }
            case 'P': {
                if (!(inputFile >> AT >> ID)) break;
                vehicle* targetVehicle = organizer.findVehicleID(ID);
                if (targetVehicle) {
                    Event* newEvent = new PromotionEvent(AT,targetVehicle);
                    organizer.addEvent(newEvent);
                }
                else {
                    cout << "error: promotion event P " << AT << " " << ID << " vehicle ID not found" << endl;
                }
                break;
            }
            case 'X': { 
                if (!(inputFile >> AT >> ID)) break;
                vehicle* targetVehicle = organizer.findVehicleID(ID);
                if (targetVehicle) {
                    Event* newEvent = new CancellationEvent(AT,targetVehicle);
                    organizer.addEvent(newEvent);
                }
                else {
                    cout << "error: cancellation event X " << AT << " " << ID << " vehicle ID not found" << endl;
                }
                break;
            }
            case 'R': {
                if(!(inputFile >> AT >> ID >> INT >> DUR)) break;
                Event* newEvent = new RoadCloseEvent(AT,INT,DUR);
                organizer.addEvent(newEvent);
                break;
            }
            default:
                cout << "unknown event type: " << eventTypeStr << " at event :" << i + 1 << endl;
            }
        }
    }
    inputFile.close();
}