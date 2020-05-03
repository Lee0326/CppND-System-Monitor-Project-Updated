#include "format.h"

#include <string>

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
inline std::string CorrectFormat(const int num) {
  if (num < 10) return "0" + std::to_string(num);
  return std::to_string(num);
}

string Format::ElapsedTime(long seconds [[maybe_unused]]) {
  const int hour = seconds / 3600;
  const int mins = (seconds % 3600) / 60;
  const int secs = seconds % 60;

  return CorrectFormat(hour) + ":" + CorrectFormat(mins) + ":" +
         CorrectFormat(secs);
}