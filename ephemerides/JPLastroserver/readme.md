# JPLASTROSERVER
Download the application and run it, you only have to define your position (Latitude, Longitude and altitude in Kms).

For spacecraft tracking, the server can calculate the doppler of the probe's emission frequency, but we must enter it in the file sondas.txt.

The format of the probes.txt file is a text file with **;** delimiter.

If the line starts with **;** it is a comment.

The fields are:
Naif Id;Name;Rx frequency in MHz

Example
-170;JWST;2270.5

In the combobox list all the objects included in the file sondas.txt will appear.

It`s now possible to send commands to SigDigger software to control the Doppler Rate in the Doppler Tool menu.
Both machines IP must be known, JPL Server must be configured with the IP and port from SigDigger machine:

<img src="https://github.com/ea3hmj/EME/raw/main/img/JPL1.jpg" width="640">

SigDigger must have enabled the remote operation, with its own IP and port:

<img src="https://github.com/ea3hmj/EME/raw/main/img/SD1.jpg" width="640">

Sometimes the spacecraft is locked to some Groundstation from Deep Space Network.

<img src="https://github.com/ea3hmj/EME/raw/main/img/DSN1.jpg" width="640">
It`s now possible to compensate also this difference in Doppler by selecting the Ground Station. The software will perform all the calculations needed and send the results to SigDigger.

<img src="https://github.com/ea3hmj/EME/raw/main/img/JPL3.JPG" width="640">

<img src="https://github.com/ea3hmj/EME/raw/main/img/JPL4.jpg" width="640">

## Disclaimer
This is a tracking systems designed for amateur use in Moonbounce, Radioastronomy and DSN. It requieres advanced skills of electronics and software, only recommended to users with previous experience with tracking systems.

Warning this software is distributed as is and I can not supply support. I write  it for myself and now I share it for other users that are asking about my tracking system.

This source and the whole package comes without warranty. It may or may not harm your computer or cell phone. Please use with care. Any damage cannot be related back to the author. The source has been tested on a real environment and scanned for viruses and has passed all tests.
