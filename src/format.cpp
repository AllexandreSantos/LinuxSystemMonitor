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

string Format::FormatString(std::string s, int targetSize){
    string sCut = s.substr(0, targetSize);
    string formatedString;
    int size = sCut.size();
    if (size < targetSize) {
        int pos = size -1;
        for (int i = pos; i<targetSize; i++){
            formatedString = sCut.append(" ");
        }
    }
    else{
        formatedString = sCut;
    }
    return formatedString;
}