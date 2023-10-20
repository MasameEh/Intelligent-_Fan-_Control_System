/* 
 * File:   RealTimeClock.c
 * Author: Mohamed Sameh
 *
 * Created on October 19, 2023, 3:57 AM
 */

#include "RealTimeClock.h"

static realtimeclock_t RealTimeClock;
uint8_t realtimeclock_pack[19];
realtimeclock_t RealTimeClock_Get_Time_Data(void)
{
    RealTimeClock.seconds = I2C_Read1ByteRegister(0xD0, 0x00);
    RealTimeClock.minutes = I2C_Read1ByteRegister(0xD0, 0x01);
    RealTimeClock.hours = I2C_Read1ByteRegister(0xD0, 0x02);
    RealTimeClock.day = I2C_Read1ByteRegister(0xD0, 0x04);
    RealTimeClock.month = I2C_Read1ByteRegister(0xD0, 0x05);
    RealTimeClock.year = I2C_Read1ByteRegister(0xD0, 0x06);
    return RealTimeClock;
}

void RealTimeClockPrint(void)
{   
    realtimeclock_pack[0] = ((RealTimeClock.day >> 4) + 48);
    realtimeclock_pack[1] = ((RealTimeClock.day & 0xf) + 48);
    realtimeclock_pack[2] = '-';
    
    realtimeclock_pack[3] = ((RealTimeClock.month >> 4) + 48);
    realtimeclock_pack[4] = ((RealTimeClock.month & 0xf) + 48);
    realtimeclock_pack[5] = '-';
    
    realtimeclock_pack[6] = ((RealTimeClock.year >> 4) + 48);
    realtimeclock_pack[7] = ((RealTimeClock.year & 0xf) + 48);
    realtimeclock_pack[8] = '/';
    
    realtimeclock_pack[9] = ((RealTimeClock.hours >> 4) + 48);
    realtimeclock_pack[10] = ((RealTimeClock.hours & 0xf) + 48);
    realtimeclock_pack[11] = '-';
    
    realtimeclock_pack[12] = ((RealTimeClock.minutes >> 4) + 48);
    realtimeclock_pack[13] = ((RealTimeClock.minutes & 0xf) + 48);
    realtimeclock_pack[14] = '-';
    
    realtimeclock_pack[15] = ((RealTimeClock.seconds >> 4) + 48);
    realtimeclock_pack[16] = ((RealTimeClock.seconds & 0xf) + 48);
    realtimeclock_pack[17] = '\r';
    
    UART_Send_String("Date: ");
    UART_Send_String(realtimeclock_pack);
}