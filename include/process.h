#ifndef PROCESS_H
#define PROCESS_H

#include <string>

#include "linux_parser.h"
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(int pid){
      pid_ = pid;
      ram_ = LinuxParser::Ram(pid);
      command_ = LinuxParser::Command(pid);
      upTime_ = LinuxParser::UpTime(pid);
      user_ = LinuxParser::User(pid);
  }
  int Pid();                               
  std::string User();                      
  std::string Command();                   
  float CpuUtilization();                  // TODO: See src/process.cpp
  std::string Ram();                      
  long int UpTime();                       
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp

 private:
   int pid_;
   std::string ram_;
   std::string command_;
   long upTime_;
   std::string user_;

};

#endif