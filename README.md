# EA3HMJ Antenna Tracking System

<img src="https://github.com/ea3hmj/EME/raw/main/img/eme%20system.jpg" width="640">

## Under construction
Please note that this is work-in-progress

## Description
This is an antenna tracking system that integrates dedicated hardware and software designed for amateur use in Earth–Moon–Earth communication (EME), radioastronomy, amateur Deep Sky Network (DSN) and other Space Communications applications where accurate and high precision tracking are required. Proper use of the system requires electronics knowledge and some software skills. Thus, it is only recommended to users with previous experience with antenna tracking systems.
The hardware components of this system are specifically selected to support the software applications that run on it. These components include a DishController unit -with a ESP32 microcontroller unit (MCU), DC motor driver board with high-performance and high-current driver devices, RS485 input/output devices and DC voltage step-up converter-, other peripherals like a variety of absolute digital encoders and inclinometers to sense the motion and position of the motorized slewing drive system and a remote-control unit. In order to support single-turn and multiturn absolute encoders with parallel output interface there is also an optional Parallel to RS485 MODBUS converter board. Obviously, the latter is not needed if the sensors output are Modbus RS485 compliant.
The software components of this system are also specifically designed to work with the hardware components. This software includes the microcontroller and remote-control firmware, communications protocol, device drivers, and application software. The DishController MCU firmware controls and monitors the operation of the slewing drive motors, azimuth encoders, and elevation inclinometers. 
The application software includes the DriverDish program, which is responsible for requesting data from the ephemeris server and communicating with the DishController unit and a suite of servers (JPLastroserver, Astroserver and Astronomyserver) that obtain the most accurate positioning data that is feasible and obtainable from trustworthy sources. 
The integration of dedicated hardware and software in such a system provides several benefits. First, it improves system performance and reliability by allowing the DishController firmware to directly access and control the specialized hardware components like the motor drivers and position sensors. This reduces overhead and improve response times. Second, it simplifies system design and development by providing a standardized set of hardware and software components that are optimized for narrow beamwidth antenna tracking. Third, in contrast to other antenna tracking system designs, the movement and position sensors in this particular system actively monitor the antenna's pointing direction. By doing so, the system is able to minimize the impact of mechanical tolerances and gear backslash.

## Disclaimer
This software -including the source and the whole package- and hardware are distributed "as is" without any representation or warranty of any kind, either express or implied. 

Please note that I am not able to provide support for this antenna tracking system. I designed and wrote it for myself and I am willing to share it here for those asking about my tracking system. I do not guarantee the accuracy or completeness of the information and materials distributed here. The software source has been tested on a real environment and scanned for viruses and has passed all tests.

I shall not be liable for any errors or omissions and shall not be responsible for any damages arising from the use of this antenna tracking system. I shall not be held responsible for any issues or problems that may arise from the use of it. 
By using any part of this antenna tracking system (software or hardware), you acknowledge and agree to the terms of this disclaimer.
