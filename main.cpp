//*************************************************************
//
//Danil Alieinikov
//H00880905
//CSC122-01
//
//I certify that this is my work and where appropriate an extension
//of the starter code provided by the assignment
//*************************************************************

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include "StopWatch.h"

std::string currentSystemTime() {
    std::time_t now = std::time(nullptr);
    return std::ctime(&now); // includes newline
}

bool askToContinue() {
    std::string input;
    std::cout << "Would you like to test again? (yes/no): ";
    std::getline(std::cin, input);

    for (char& c : input) c = std::tolower(c);

    return (input == "yes" || input == "y");
}

int main() {
    std::cout << "StopWatch Test Program\n";

    do {
        std::cout << "Current system time: " << currentSystemTime();
        std::cout << "Press Enter to start timing...";
        std::cin.ignore();

        StopWatch sw(true);  // Starts immediately

        std::cout << "Timer started. Press Enter to stop...";
        std::cin.ignore();

        sw.stop();

        std::cout << "Timer stopped.\n";
        std::cout << "Elapsed time: " << sw.toString();
        std::cout << "System time now: " << currentSystemTime();

    } while (askToContinue());

    return 0;
}
