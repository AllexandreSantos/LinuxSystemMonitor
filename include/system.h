#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "linux_parser.h"

class System {
 public:
  Processor& Cpu();                   
  std::vector<Process>& Processes();
  float MemoryUtilization();          
  long UpTime();                      
  int TotalProcesses();               
  int RunningProcesses();           
  std::string Kernel();               
  std::string OperatingSystem();      

 private:
  Processor cpu_{Processor(LinuxParser::CpuUtilization())};
  std::vector<Process> processes_;
  std::string operatingSystem_{LinuxParser::OperatingSystem()}; 
  std::string kernel_{LinuxParser::Kernel()};
  float memoryUtilization_ {LinuxParser::MemoryUtilization()};
  long upTime_ {LinuxParser::UpTime()};
  int totalProcesses_ {LinuxParser::TotalProcesses()};
  int runningProcesses_{LinuxParser::RunningProcesses()};
};

#endif