#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

#include <condition_variable>
#include <iostream>
#include <deque>
#include <mutex>
#include "TrafficLight.h"

class MessageQueue
{
    public:
        void send(TrafficLightPhase&&);
        TrafficLightPhase receive();
    public:
        std::deque<TrafficLightPhase> _queue;
    private:
        std::condition_variable _cond;
        std::mutex _mutex;
};

#endif