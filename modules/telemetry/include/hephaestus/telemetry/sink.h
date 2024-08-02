//=================================================================================================
// Copyright (C) 2023-2024 HEPHAESTUS Contributors
//=================================================================================================

#pragma once

#include <chrono>
#include <string>

namespace heph::telemetry {
using ClockT = std::chrono::system_clock;

// TODO(filippo): Seems redundant. Remove lint warning?
// NOLINTBEGIN(cppcoreguidelines-pro-type-member-init)
struct MetricEntry {
  std::string component;
  std::string tag;
  ClockT::time_point log_timestamp;
  std::string json_values;
};
[[nodiscard]] auto toJSON(const MetricEntry& log) -> std::string;
void fromJSON(std::string_view json, MetricEntry& log);

class ITelemetrySink {
public:
  virtual ~ITelemetrySink() = default;

  virtual void send(const MetricEntry& log_entry) = 0;
};

/// Create a sink that print logs to the terminal.
[[nodiscard]] auto createTerminalSink() -> std::unique_ptr<ITelemetrySink>;

struct RESTSinkConfig {
  std::string url;
};
[[nodiscard]] auto createRESTSink(RESTSinkConfig config) -> std::unique_ptr<ITelemetrySink>;

struct InfluxDBSinkConfig {
  std::string url;
  std::string token;
  std::string database;
  std::size_t batch_size{ 0 };
};
[[nodiscard]] auto createInfluxDBSink(InfluxDBSinkConfig config) -> std::unique_ptr<ITelemetrySink>;
// NOLINTEND(cppcoreguidelines-pro-type-member-init)

}  // namespace heph::telemetry