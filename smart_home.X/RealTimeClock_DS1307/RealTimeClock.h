/* 
 * File:   RealTimeClock.h
 * Author: Mohamed Sameh
 *
 * Created on October 19, 2023, 3:57 AM
 */

#ifndef REALTIMECLOCK_H
#define	REALTIMECLOCK_H

/* Section : Includes */
#include "../mcc_generated_files/examples/i2c_master_example.h"
#include "../UART_LoggingDebugData/UART_LoggingDebugData.h"

/* Section : Data Types Declarations  */
typedef struct
{
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
    uint8_t day;
    uint8_t month;
    uint8_t year;
}realtimeclock_t;

/* Section : Functions Declarations */
realtimeclock_t RealTimeClock_Get_Time_Data(void);
void RealTimeClockPrint(void);

#endif	/* REALTIMECLOCK_H */

