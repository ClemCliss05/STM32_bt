#pragma once
#include <cstdint>

class Uart
{
public:
    explicit Uart(uint32_t baudrate);

    void init();
    void write(const uint8_t* data, uint16_t size);
    bool read(uint8_t& byte);

private:
    uint32_t baudrate_;
};