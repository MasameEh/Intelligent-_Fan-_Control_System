/* 
 * File:   EEPROM_24C02C.c
 * Author: Mohamed Sameh
 *
 * Created on October 20, 2023, 2:17 AM
 */

#include "EEPROM_24C02C.h"


void EEPROM_24C02C_WriteByte(i2c_address_t EEPROM_Address, i2c_address_t Byte_Address, uint8_t data)
{
    I2C_Write1ByteRegister(EEPROM_Address, Byte_Address, data);
}
uint8_t EEPROM_24C02C_ReadByte(i2c_address_t EEPROM_Address, i2c_address_t Byte_Address)
{
    uint8_t RetVal = I2C_Read1ByteRegister(EEPROM_Address, Byte_Address);
    return RetVal;
}