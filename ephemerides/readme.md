# EPHEMERIDES
An integral part of the system is to obtain the most accurate positioning data that is feasible and obtainable from trustworthy sources.

As a principle, the data will be accessible through a TCP server on port 8888.

For this purpose, we have three separate servers to meet different requirements.

## Astroserver

A JPL SPICE based server that provides data from any object in the kernel space available.

## JPLastroserver

A server that sources its data from the NASA JPL Horizons on-line solar system data and ephemeris computation service. Horizons provides access to key solar system data and highly accurate ephemerides for solar system objects including selected spacecraft. The file "sondas.txt" contains the list of objects whose ephemeris will be retrieved from the Horizons system.
## Astronomyserver
An autonomous version based on Don Cross' [Astronomy Engine library](https://github.com/cosinekitty/astronomy) that provides Solar System planets data.

## AstroserverHelper.App
This App enables you to create a list of coordinates were an object can be found at a specific time.

## Documentation

## Disclaimer
This is an antenna tracking system (software and hardware) designed for amateur use in Earth–Moon–Earth communication (EME), radioastronomy, amateur Deep Sky Network (DSN) and other Space Communication applications where accurate and high precision tracking are required. 
Proper use of the system requires electronics knowledge and some software skills. Thus, it is only recommended to users with previous experience with antenna tracking systems.

This software -including the source and the whole package- and hardware are distributed "as is" without any representation or warranty of any kind, either express or implied. 

Please note that I am not able to provide support for this antenna tracking system. I designed and wrote it for myself and I am willing to share it here for those asking about my tracking system. I do not guarantee the accuracy or completeness of the information and materials distributed here. The software source has been tested on a real environment and scanned for viruses and has passed all tests.

I shall not be liable for any errors or omissions and shall not be responsible for any damages arising from the use of this antenna tracking system. I shall not be held responsible for any issues or problems that may arise from the use of it. 
By using any part of this antenna tracking system (software or hardware), you acknowledge and agree to the terms of this disclaimer.
