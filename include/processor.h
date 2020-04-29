#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <chrono>
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp
                        // TODO: Declare any necessary private members
 private:
  int user, nice, system, idle, iowait, irq, softirq, steal;
  int prevIdle, currIdle, prevNonIdle, currNonIdle, Total, prevTotal;
  float percentage;
  const int interval = 3;
  chrono::time_point<std::chrono::system_clock> time_start;
  bool Initialized = false;
  void Readfields();
  void Initialize();
  void Update();
};

#endif