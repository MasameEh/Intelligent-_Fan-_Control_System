/* 
 * File:   EEPROM_24C02C.h
 * Author: Mohamed Sameh
 *
 * Created on October 20, 2023, 2:17 AM
 */

#ifndef EEPROM_24C02C_H
#define	EEPROM_24C02C_H

/* Section : Includes */
#include "../mcc_generated_files/examples/i2c_master_example.h"

/* Section : Functions Declarations */
void EEPROM_24C02C_WriteByte(i2c_address_t EEPROM_Address, i2c_address_t Byte_Address, uint8_t data);
uint8_t EEPROM_24C02C_ReadByte(i2c_address_t EEPROM_Address, i2c_address_t Byte_Address);

#endif	/* EEPROM_24C02C_H */

