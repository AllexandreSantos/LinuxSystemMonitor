#include <string>

#include "format.h"

using std::string;
using std::to_string;

// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long times) {
    unsigned long hours = times/3600;
    unsigned short minutes = (times%3600)/60;
    unsigned short seconds = times - ( (hours*3600) + (minutes*60) );
    string hourOutput, minuteOutput, secondOutput;
    if (hours<10)
        hourOutput = "0" + to_string(hours);
    else
        hourOutput = to_string(hours);

    if (minutes<10)
        minuteOutput = "0" + to_string(minutes);
    else
        minuteOutput = to_string(minutes);

    if (seconds<10)
        secondOutput = "0" + to_string(seconds);
    else
        secondOutput = to_string(seconds);

    string output = hourOutput + ":" + minuteOutput + ":" + secondOutput;
    return output; 
}