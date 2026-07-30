# Non-Invasive Glucometer Using Saliva and Pulse Oximeter

## Overview

This project presents a prototype for non-invasive estimation of blood glucose levels using saliva, combined with pulse rate and blood oxygen monitoring. The system uses signal conditioning circuits, a microcontroller, and sensor interfacing to process biological signals.

## Features

- Non-invasive glucose estimation using saliva
- Pulse rate monitoring
- Blood oxygen (SpO₂) monitoring
- Analog signal conditioning using Op-Amps
- Embedded system implementation
- Real-time serial monitoring

## Hardware Components

- ESP8266 (NodeMCU)
- Saliva glucose sensing setup
- Pulse Oximeter Sensor
- LF356 Op-Amp
- LM358 Op-Amp
- Power Supply
- Resistors and Capacitors

## Software

- Arduino IDE
- Embedded C
- Serial Monitor

## Project Workflow

1. Collect saliva sample.
2. Sensor detects the electrical response.
3. Op-Amp amplifies and conditions the signal.
4. ESP8266 reads the analog value.
5. The estimated glucose value is displayed.
6. Pulse oximeter measures pulse rate and SpO₂.

## Applications

- Academic research
- Embedded systems learning
- IoT healthcare prototypes

## Future Improvements

- Cloud data logging
- Mobile application
- Improved sensor calibration
- Compact PCB design
- ## Repository Structure

```
code/
 ├── glucometer.ino
 ├── pulse_oximeter.ino
 └── combined_system.ino

docs/
images/
circuit/
```

## Disclaimer

This repository contains an academic prototype developed for educational and research purposes. It is not intended for clinical or diagnostic use.
