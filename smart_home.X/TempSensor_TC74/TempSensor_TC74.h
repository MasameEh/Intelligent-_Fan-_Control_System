/* 
 * File:   TempSensor_TC74.h
 * Author: Mohamed Sameh
 *
 * Created on October 20, 2023, 3:05 AM
 */

#ifndef TEMPSENSOR_TC74_H
#define	TEMPSENSOR_TC74_H

/* Section : Includes */
#include "../mcc_generated_files/examples/i2c_master_example.h"

/* Section : Functions Declarations */
uint8_t TempSensor_TC74_ReadByte(i2c_address_t TC74_Address);

#endif	/* TEMPSENSOR_TC74_H */

