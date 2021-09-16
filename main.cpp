#include <iostream>
#include <ctime>
#include <iomanip>

void delaySec(int n){
    std::time_t start, current;
    start = std::time(nullptr);
    do{
        current = std::time(nullptr);
    }while(current < (start +(std::time_t)n));
}
std::string timeRemaining(std::time_t stop){
    std::time_t current = std::time(nullptr);
    std::time_t diff = (std::time_t)std::difftime(stop, current);
    int min = diff / 60;
    int sec = diff % 60;
    return std::to_string(min) + "m " + std::to_string(sec) + "s";
}

int main() {
    std::time_t currentTime, stopTime, t;
    int min, sec;
    std::tm *timeStruct;
    t = std::time(nullptr);
    timeStruct = std::localtime(&t);
    std::cout << "Input time interval (mm:ss): ";
    std::cin >> std::get_time(timeStruct, "%M:%S");
    min = timeStruct->tm_min;
    sec = timeStruct->tm_sec;
    t = std::time(nullptr);
    timeStruct = std::localtime(&t);
    //std::cout << "min= " << min << " sec= " << sec << std::endl;
    stopTime = std::mktime(timeStruct) + min*60 + sec;
    std::cout << "Starting!" <<std::endl;

    do{
        delaySec(1);
        std::cout << "time remaining: " << timeRemaining(stopTime) << std::endl;
        currentTime = std::time(nullptr);
    }while(currentTime < stopTime);
    std::cout << "DING! DING! DING!" << std::endl;
    return 0;
}
