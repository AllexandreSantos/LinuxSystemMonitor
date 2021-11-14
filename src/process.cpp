#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "format.h"

using std::string;
using std::to_string;
using std::vector;
using std::stoi;

int Process::Pid() {return pid_;}

// Return this process's CPU utilization
float Process::CpuUtilization() { 
    cpuUtilization_ = LinuxParser::CpuUtilization(pid_);
    return cpuUtilization_; 
}

// Return the command that generated this process
string Process::Command() { 
    command_ = LinuxParser::Command(pid_);
    return command_; 
}

// Return this process's memory utilization
string Process::Ram() {
    ram_ = LinuxParser::Ram(pid_); 
    string formatedRam = Format::FormatString(ram_, 6);
    return formatedRam; 
}

// Return the user (name) that generated this process
string Process::User() { 
    user_ = LinuxParser::User(pid_);
    string formatedUser = Format::FormatString(user_, 10);
    return formatedUser;
}

// Return the age of this process (in seconds)
long int Process::UpTime() { 
    upTime_ = LinuxParser::UpTime(pid_);
    return upTime_; 
}

// Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process const& a) const { 
    return(this->cpuUtilization_ > a.cpuUtilization_);
    //return( this->pid_ > a.pid_);
}