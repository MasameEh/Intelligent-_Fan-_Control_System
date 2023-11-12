/* 
 * File:   main.c
 * Author: Mohamed Sameh
 * Description:
 * Source file for Smart Home application.
 * Created on October 20, 2023, 3:05 AM
 */

#include "mcc_generated_files/mcc.h"

uint8_t Rec_TC74_Value;

void I2C_CustomSlaveReadIntHandler(void)
{
    Rec_TC74_Value = SSPBUF;
}

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    I2C_Open();
    I2C_SlaveSetReadIntHandler(I2C_CustomSlaveReadIntHandler);
    
    while(1)
    {   //Fan on
        if(Rec_TC74_Value > 30)
        {
            Motor_pin1_SetHigh();
            Motor_pin2_SetLow();
        //Fan off    
        }else
        {
            Motor_pin1_SetHigh();
            Motor_pin2_SetHigh();
        }
    }
}
/**
 End of File
*/
