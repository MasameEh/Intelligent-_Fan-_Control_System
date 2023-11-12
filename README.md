# Intelligent Fan Control System

## Overview

This project aims to create an Intelligent Fan Control System using the I2C communication protocol. The system consists of a master device (PIC18F46K20) and a slave device (PIC18F46K20. The master device communicates with various peripherals, including a TC74 temperature sensor, two EEPROMs (24C02C), a DS1307 real-time clock (RTC), and an LDR sensor.

## Features

### Temperature Control

- The TC74 temperature sensor measures the ambient temperature.
- If the temperature exceeds a threshold (e.g., 30°C), the master sends a command to the slave to turn on a DC motor (acting as a fan).

### I2C Communication

- The master communicates with the slave and peripherals (TC74, EEPROMs) using the I2C bus.

### Data Storage

- Two EEPROMs (24C02C) are connected to the I2C bus for data storage.

### Real-Time Clock

- The DS1307 real-time clock provides the current time to the master via UART.

### Light Sensing

- An LDR sensor detects ambient light conditions.
- At night, the LDR triggers the master to turn on two LEDs.

## Components

### Master Device

- PIC18F46K20 microcontroller.
- I2C communication module.
- UART module for communication with DS1307 RTC.
- LDR input for light sensing.

### Slave Device

- Connects to the master via I2C.
- Controls the DC motor/fan based on temperature commands.

### Peripheral Devices

- TC74 Temperature Sensor.
- Two 24C02C EEPROMs for data storage.
- DS1307 Real-Time Clock (communicates via UART).

## Usage

### Setup

1. Connect all components as per the circuit diagram.
2. Ensure power supply to all devices.

### Programming

1. Program the master and slave devices with the provided source code.

### Operation

1. Power on the system.
2. The TC74 sensor measures temperature.
3. If temperature > 30°C, the master sends a command to the slave to turn on the fan.
4. DS1307 provides real-time clock data.
5. LDR turns on LEDs at night.

## Circuit Diagram



## Dependencies

- PIC18F46K20 libraries.
- I2C, UART libraries.
- TC74 library.
- EEPROM library.
- DS1307 library.
