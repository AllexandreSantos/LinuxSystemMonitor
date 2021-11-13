#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>
#include <string>

using std::string;
using std::vector;

class Processor {
  public:
    Processor(vector<string> cpuUsage){
        cpuUsage_ = cpuUsage;
    }
    float Utilization();

  private:
    vector<string> cpuUsage_;
};

#endif