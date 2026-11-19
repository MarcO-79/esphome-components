#pragma once

#include "esphome/core/helpers.h"
#include "esphome/core/log.h"
#include "m_bus_data.h"
#include "decode3of6.h"
#include "utils.h"
#include "crc.h"

#include <vector>

#define BLOCK1A_SIZE 12     // Size of Block 1, format A
#define BLOCK1B_SIZE 10     // Size of Block 1, format B
#define BLOCK2B_SIZE 118    // Maximum size of Block 2, format B

namespace esphome {
namespace wmbus {

inline std::string format_hex_pretty(const std::vector<uint8_t> &data) {
  if (data.empty())
    return "";
  // Każdy bajt zajmuje 2 znaki hex + 1 separator oraz znak końca ciągu
  std::vector<char> buf(data.size() * 3 + 1);
  format_hex_pretty_to(buf.data(), buf.size(), data.data(), data.size());
  return std::string(buf.data());
}

  bool mBusDecode(WMbusData &t_in, WMbusFrame &t_frame);
  bool mBusDecodeFormatA(const WMbusData &t_in, WMbusFrame &t_frame);
  bool mBusDecodeFormatB(const WMbusData &t_in, WMbusFrame &t_frame);

}
}
