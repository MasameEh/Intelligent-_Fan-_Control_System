/* 
 * File:   UART_LoggingDebugData.c
 * Author: Mohamed Sameh
 *
 * Created on October 19, 2023, 9:16 PM
 */

#include "UART_LoggingDebugData.h"

void UART_Send_String(uint8_t* string)
{
    while (*string != '\0') {
        EUSART_Write(*string++);
    }
}