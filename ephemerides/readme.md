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
This is a tracking systems designed for amateur use in Moonbounce, Radioastronomy and DSN. It requieres advanced skills of electronics and software, only recommended to users with previous experience with tracking systems.

Warning this software is distributed as is and I can not supply support. I write  it for myself and now I share it for other users that are asking about my tracking system.

This source and the whole package comes without warranty. It may or may not harm your computer or cell phone. Please use with care. Any damage cannot be related back to the author. The source has been tested on a real environment and scanned for viruses and has passed all tests.