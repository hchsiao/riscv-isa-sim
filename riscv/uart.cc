#include <iostream>
#include "devices.h"

uart_device_t::uart_device_t(int data)
  : data(data)
{
}

bool uart_device_t::load(reg_t addr, size_t len, uint8_t* bytes)
{
  std::cout << "UART read: len = " << len << ", addr = " << addr << std::endl;
  if (len != 4) { // address must be aligned
    std::cerr << "Error: UART memory access not aligned" << std::endl;
    return false;
  }

  memset(bytes, 1, len);
  return true;
}

bool uart_device_t::store(reg_t addr, size_t len, const uint8_t* bytes)
{
  std::cout << "UART write: len = " << len << ", addr = " << addr << std::endl;
  if (len != 4) { // address must be aligned
    std::cerr << "Error: UART memory access not aligned" << std::endl;
    return false;
  }

  std::cout << "data = " << ((bytes[3] << 24) |
                             (bytes[2] << 16) |
                             (bytes[1] <<  8) |
                             (bytes[0])) << std::endl;
  return true;
}
