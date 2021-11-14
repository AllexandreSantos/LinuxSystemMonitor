#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "system.h"
#include "format.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;
using std::sort;

Processor& System::Cpu() { 
    cpu_ = Processor(LinuxParser::CpuUtilization());
    return cpu_; 
    }

vector<Process>& System::Processes() { 
    processes_ = {};
    vector<int> pids = LinuxParser::Pids();
    for(long unsigned int i = 0; i<pids.size(); i++){
        Process process = Process(pids[i]);
        processes_.push_back(process);
    }
    sort(processes_.begin(), processes_.end());
    return processes_; 
}

std::string System::Kernel() { 
    kernel_ = LinuxParser::Kernel();
    return kernel_; 
}

std::string System::OperatingSystem() { 
    operatingSystem_ = LinuxParser::OperatingSystem();
    return operatingSystem_; 
}

float System::MemoryUtilization() { 
    memoryUtilization_ = LinuxParser::MemoryUtilization();
    return memoryUtilization_; 
}

long int System::UpTime() { 
    upTime_ = LinuxParser::UpTime();
    return upTime_; 
}

int System::TotalProcesses() { 
    totalProcesses_ = LinuxParser::TotalProcesses();
    return totalProcesses_; 
}

int System::RunningProcesses() { 
    runningProcesses_ = LinuxParser::RunningProcesses();
    return runningProcesses_; 
}


