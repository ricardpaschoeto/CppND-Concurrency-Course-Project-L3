#ifndef TRAFFICLIGTH_H
#define TRAFFICLIGTH_H


#include "TrafficObject.h"


enum TrafficLightPhase
{
    red,
    green,
};

class TrafficLight: TrafficObject
{
    public:
        void waitForGreen();
        void simulate();
        TrafficLightPhase getCurrentPhase();
    private:
        void cycleThroughPhases();
    private:
        int _currentPhase;
        MessageQueue msg;
};

#endif