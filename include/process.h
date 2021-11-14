#ifndef PROCESS_H
#define PROCESS_H

#include <string>

#include "linux_parser.h"
#include "format.h"
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(int pid){
      pid_ = pid;
  }
  int Pid();                               
  std::string User();                      
  std::string Command();                   
  float CpuUtilization();                  
  std::string Ram();                      
  long int UpTime();                       
  bool operator<(Process const& a) const;

 private:
   int pid_;
   std::string ram_;
   std::string command_;
   long upTime_;
   std::string user_;
   float cpuUtilization_;
};

#endif