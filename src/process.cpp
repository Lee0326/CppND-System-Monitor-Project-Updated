#include "process.h"

#include <unistd.h>

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::to_string;
using std::vector;

Process::Process(int id) : id_(id) {
  address_cmd = "/proc/" + std::to_string(id) + "/cmdline";
  address_cpu = "/proc/" + std::to_string(id) + "/stat";
};
// TODO: Return this process's ID
int Process::Pid() { return id_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() {
  string line;
  string time;
  std::ifstream stream(address_cpu);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    for (int col = 0; col < 22; ++col) {
      linestream >> time;
      switch (col) {
        case 13:
          utime = atoi(time.c_str());
          break;
        case 14:
          stime = atoi(time.c_str());
          break;
        case 15:
          cutime = atoi(time.c_str());
          break;
        case 16:
          cstime = atoi(time.c_str());
          break;
        case 21:
          starttime = atoi(time.c_str());
          break;
        default:
          break;
      }
    }
    int total_time = utime + stime + cutime + cstime;
    int uptime = LinuxParser::UpTime();
    int seconds = uptime - (starttime / hertz_);
    cpu_usage = ((float)total_time / hertz_) / seconds;
    // std::cout << cpu_usage << std::endl;
  }
  return cpu_usage;
}

// TODO: Return the command that generated this process
string Process::Command() {
  string cmd;
  string line;
  std::ifstream stream(address_cmd);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> cmd;
  }
  return cmd;
}

// TODO: Return this process's memory utilization
string Process::Ram() {
  string ram = LinuxParser::Ram(id_);
  return ram;
}

// TODO: Return the user (name) that generated this process
string Process::User() {
  string user = LinuxParser::User(id_);
  return user;
}

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() {
  int uptime = LinuxParser::UpTime();
  int seconds = uptime - (starttime / hertz_);
  return seconds;
}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a [[maybe_unused]]) const {
  return true;
}