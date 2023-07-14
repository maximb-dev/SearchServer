#pragma once

#define PROFILE_CONCAT_INTERNAL(X, Y) X##Y
#define PROFILE_CONCAT(X, Y) PROFILE_CONCAT_INTERNAL(X, Y)
#define UNIQUE_VAR_NAME_PROFILE PROFILE_CONCAT(profileGuard, __LINE__)
#define LOG_DURATION(x) LogDuration UNIQUE_VAR_NAME_PROFILE(x)
#define LOG_DURATION_STREAM(x, y) LogDuration UNIQUE_VAR_NAME_PROFILE(x, y)

#include <chrono>
#include <iostream>
#include <string>

class LogDuration {
 public:
  using Clock = std::chrono::steady_clock;
  std::string operation_name;

  LogDuration(std::string operation, std::ostream& out = std::cerr)
      : operation_name(operation), out_(out) {}

  ~LogDuration() {
    using namespace std::chrono;
    using namespace std::literals;

    const auto end_time = Clock::now();
    const auto dur = end_time - start_time_;
    std::cerr << operation_name << ": "s
              << duration_cast<milliseconds>(dur).count() << " ms"s
              << std::endl;
  }

 private:
  const Clock::time_point start_time_ = Clock::now();
  std::ostream& out_;
};