# EPHEMERIDES
An important part of the system is to obtain the most accurate positioning data possible.

As a philosophy the data will be served by a TCP server on port 8888.

For this we have 3 different servers depending on the need.

## Astroserver

A server based on JPL SPICE that serves us data from any object in the kernel space available.

## JPLastroserver

It is a reduced version that connects to Horizonts to obtain the data that it will later serve, there is a file "sondas.txt" where the data of the probes/astros that we want to request are introduced.

## Astronomyserver
An autonomous version based on the [Astronomy Engine library of Don Cross](https://github.com/cosinekitty/astronomy) that provides data of the planets of the solar system.

## Documentation

## Disclaimer
This is an antenna tracking system (software and hardware) designed for amateur use in Earth–Moon–Earth communication (EME), radioastronomy, amateur Deep Sky Network (DSN) and other Space Communication applications where accurate and high precision tracking are required. 
Proper use of the system requires electronics knowledge and some software skills. Thus, it is only recommended to users with previous experience with antenna tracking systems.

This software -including the source and the whole package- and hardware are distributed "as is" without any representation or warranty of any kind, either express or implied. 

Please note that I am not able to provide support for this antenna tracking system. I designed and wrote it for myself and I am willing to share it here for those asking about my tracking system. I do not guarantee the accuracy or completeness of the information and materials distributed here. The software source has been tested on a real environment and scanned for viruses and has passed all tests.

I shall not be liable for any errors or omissions and shall not be responsible for any damages arising from the use of this antenna tracking system. I shall not be held responsible for any issues or problems that may arise from the use of it. 
By using any part of this antenna tracking system (software or hardware), you acknowledge and agree to the terms of this disclaimer.
