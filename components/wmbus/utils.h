#pragma once

#include "esphome/core/helpers.h"
#include "esphome/core/log.h"
#include <algorithm> 
#include <assert.h>
#include <memory.h>
#include <vector>

#ifndef MAX
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#endif

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

  uint16_t packetSize(uint8_t t_L);
  uint16_t byteSize(uint16_t t_packetSize);

  unsigned char *safeButUnsafeVectorPtr(std::vector<unsigned char> &v);
  void xorit(unsigned char *srca, unsigned char *srcb, unsigned char *dest, int len);
  void incrementIV(unsigned char *iv, int len);

  bool decrypt_ELL_AES_CTR(std::vector<unsigned char> &frame, std::vector<unsigned char> &aeskey);
  bool decrypt_TPL_AES_CBC_IV(std::vector<unsigned char> &frame, std::vector<unsigned char> &aeskey);

}
}
