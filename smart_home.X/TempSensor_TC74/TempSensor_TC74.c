/* 
 * File:   TempSensor_TC74.c
 * Author: Mohamed Sameh
 *
 * Created on October 20, 2023, 3:05 AM
 */

#include "TempSensor_TC74.h"

uint8_t TempSensor_TC74_ReadByte(i2c_address_t TC74_Address)
{
    uint8_t RetVal = I2C_Read1ByteRegister(TC74_Address, 0x00);
    return RetVal;
}