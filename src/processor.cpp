#include "processor.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  if (!Initialized) {
    Initialize();
    Initialized = true;
  } else if ((chrono::system_clock::now() - time_start) >=
             chrono::seconds(interval)) {
    Update();
  }
  return percentage;
}
void Processor::Update() {
  Readfields();
  currIdle = idle + iowait;
  currNonIdle = user + nice + system + irq + softirq + steal;
  Total = currIdle + currNonIdle;
  float totald = (float)(Total - prevTotal);
  float idled = (float)(currIdle - prevIdle);
  percentage = (totald - idled) / totald;
  prevIdle = currIdle;
  prevNonIdle = currNonIdle;
  prevTotal = Total;
}
void Processor::Initialize() {
  Readfields();
  time_start = chrono::system_clock::now();
  currIdle = idle + iowait;
  currNonIdle = user + nice + system + irq + softirq + steal;
  Total = currIdle + currNonIdle;
  prevTotal = Total;
  prevIdle = currIdle;
  prevNonIdle = currNonIdle;
  percentage = (float)currNonIdle / Total;
}

void Processor::Readfields() {
  std::string line;
  std::string key;
  std::string value;
  std::ifstream filestream("/proc/stat");
  if (filestream.is_open()) {
    getline(filestream, line);
    std::istringstream linestream(line);
    linestream >> key >> user >> nice >> system >> idle >> iowait >> irq >>
        softirq >> steal;
  }
}