/* 
 * File:   main.c
 * Author: Mohamed Sameh
 * Description:
 * Source file for Smart Home application.
 * Created on October 18, 2023, 3:05 AM
 */

#include "mcc_generated_files/mcc.h"


void ADC_Interrupt(void);

realtimeclock_t realtimeclock;
uint8_t U4_EEPROM;
uint8_t U3_EEPROM;
uint8_t A7_TC74_Value;
uint16_t convertedValue;
float convertedValue_volt;

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    EEPROM_24C02C_WriteByte(0xA2, 0x09, 0x01);
    EEPROM_24C02C_WriteByte(0xA6, 0x09, 0x01);
    __delay_us(100);
   
    U4_EEPROM = EEPROM_24C02C_ReadByte(0xA2, 0x09);
    U3_EEPROM = EEPROM_24C02C_ReadByte(0xA6, 0x09);
   
    ADC_Initialize();
    ADC_SetInterruptHandler(ADC_Interrupt);

    while(1)
    {
        ADC_StartConversion();
        //Display the date and time
        realtimeclock = RealTimeClock_Get_Time_Data();
        RealTimeClockPrint();
        //Read the Sensor temperature
        A7_TC74_Value = TempSensor_TC74_ReadByte(0x9A);
        //Send the Sensor reading to another MCU
        I2C_Write1ByteRegister(0x60, 0x00, A7_TC74_Value);
        //turns led on when the light is weak.
        if(convertedValue_volt < 0.75)
        {
            LED_SetHigh();
        }else 
        {
            LED_SetLow();
        }
        
    }
}

void ADC_Interrupt(void)
{
    convertedValue = ADC_GetConversionResult();
    convertedValue_volt = (convertedValue * ADC_STEP);
}

/**
 End of File
*/


