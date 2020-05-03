#ifndef PROCESS_H
#define PROCESS_H

#include <fstream>
#include <iostream>
#include <string>

#include "linux_parser.h"
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(int id);
  int Pid();                               // TODO: See src/process.cpp
  std::string User();                      // TODO: See src/process.cpp
  std::string Command();                   // TODO: See src/process.cpp
  float CpuUtilization();                  // TODO: See src/process.cpp
  std::string Ram();                       // TODO: See src/process.cpp
  long int UpTime();                       // TODO: See src/process.cpp
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp
  // TODO: Declare any necessary private members
 private:
  int id_;
  std::string address_cmd;
  std::string address_cpu;
  int hertz_ = 100;
  int utime = 0;
  int stime = 0;
  int cutime = 0;
  int cstime = 0;
  int starttime = 0;
  float cpu_usage = 0.0;
};

#endif