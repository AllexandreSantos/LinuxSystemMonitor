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

Processor& System::Cpu() { return cpu_; }

vector<Process>& System::Processes() { 
    vector<int> pids = LinuxParser::Pids();
    for(long unsigned int i = 0; i<pids.size(); i++){
        Process process = Process(pids[i]);
        processes_.push_back(process);
    }
    return processes_; 
}

std::string System::Kernel() { return kernel_; }

float System::MemoryUtilization() { return memoryUtilization_; }

std::string System::OperatingSystem() { return operatingSystem_; }

int System::RunningProcesses() { return runningProcesses_; }

int System::TotalProcesses() { return totalProcesses_; }

long int System::UpTime() { return upTime_; }