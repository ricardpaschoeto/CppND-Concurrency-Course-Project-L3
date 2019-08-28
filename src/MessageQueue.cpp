#include "MessageQueue.h"
#include "TrafficLight.h"

void MessageQueue::send(TrafficLightPhase &&msg){

    std::lock_guard<std::mutex> uLock(_mutex);

    std::cout << "   Message #" << msg << " will be added to the queue" << std::endl;
    _queue.push_back(std::move(msg));
    _cond.notify_one();
}

TrafficLightPhase MessageQueue::receive(){

    std::unique_lock<std::mutex> uLock(_mutex);
    _cond.wait(uLock, [this] { return !_queue.empty(); }); // pass unique lock to condition variable

    // remove last vector element from queue
    TrafficLightPhase msg = std::move(_queue.back());
    _queue.pop_back();

    return msg;
}