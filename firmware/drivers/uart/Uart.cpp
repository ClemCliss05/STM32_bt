#include "Uart.hpp"

Uart::Uart(uint32_t baudrate)
    : baudrate_(baudrate)
{
}

void Uart::init()
{
    // Config registre STM32 ici
}

void Uart::write(const uint8_t* data, uint16_t size)
{
    for(uint16_t i = 0; i < size; ++i)
    {
        // Attendre TXE
        // Ecrire registre DR
    }
}

bool Uart::read(uint8_t& byte)
{
    // Vérifier RXNE
    return false;
}