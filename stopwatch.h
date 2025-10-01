// *************************************************************************** 
// 
//   Your Name 
//   Your Harper ID
//   Your Course and Section Number 
// 
//   I certify that this is my own work and where appropriate an extension 
//   of the starter code provided for the assignment. 
// ***************************************************************************

#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>
#include <string>

class StopWatch {
private:
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point endTime;
    bool running;
    long totalElapsed;

public:
    // Constructors
    StopWatch();
    StopWatch(bool startNow);
    // Methods
    void start();      // Start or restart timer
    void stop();       // Stop timer
    long elapsed() const; // Elapsed time in seconds
    std::string toString() const;

    // Static
    static StopWatch add(const StopWatch& sw1, const StopWatch& sw2);
    static StopWatch subtract(const StopWatch& sw1, const StopWatch& sw2);
};

#endif
