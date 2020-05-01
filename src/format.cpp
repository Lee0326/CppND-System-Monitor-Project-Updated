#include "format.h"

#include <string>

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds [[maybe_unused]]) {
  string hour = std::to_string((seconds / 3600));
  string mins = std::to_string((seconds % 3600) / 60);
  string secs = std::to_string((seconds % 3600) % 60);

  return hour + ":" + mins + ":" + secs;
}