//*************************************************************
//
//Danil Alieinikov
//H00880905
//CSC122-01
//
//I certify that this is my work and where appropriate an extension
//of the starter code provided by the assignment
//*************************************************************

#include "stopwatch.h"
#include <sstream>

// Constructor timer starts
StopWatch::StopWatch() : running(false), totalElapsed(0) {}

// Constructor optionally start now
StopWatch::StopWatch(bool startNow) : running(false), totalElapsed(0) {
    if (startNow) {
        start();
    }
}

void StopWatch::start() {
    startTime = std::chrono::steady_clock::now();
    running = true;
    totalElapsed = 0; // reset elapsed when starting
}

void StopWatch::stop() {
    if (running) {
        endTime = std::chrono::steady_clock::now();
        totalElapsed = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
        running = false;
    }
}
long StopWatch::elapsed() const {
    if (running) {
        auto now = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();
    } else {
        return totalElapsed;
    }
}

std::string StopWatch::toString() const {
    std::ostringstream out;
    out << elapsed() << " seconds";
    return out.str();
}

// Add two watches
StopWatch StopWatch::add(const StopWatch& sw1, const StopWatch& sw2) {
    StopWatch result;
    result.totalElapsed = sw1.elapsed() + sw2.elapsed();
    result.running = false;
    return result;
}

// Subtract two watches
StopWatch StopWatch::subtract(const StopWatch& sw1, const StopWatch& sw2) {
    StopWatch result;
    long diff = sw1.elapsed() - sw2.elapsed();
    if (diff < 0) diff = 0;
    result.totalElapsed = diff;
    result.running = false;
    return result;
}
