# JPLASTROSERVER
Download the application and run it, you only have to define your position (Latitude, Longitude and altitude in Kms).

For spacecraft tracking, the server can calculate the doppler of the probe's emission frequency, but we must enter it in the file probes.txt.

The format of the probes.txt file is a text file with **;** delimiter.

If the line starts with **;** it is a comment.

The fields are:
Naif Id;Name;Rx frequency in MHz

Example
-170;JWST;2270.5

In the combobox list all the objects included in the file probes.txt will appear.

## Disclaimer
This is a tracking systems designed for amateur use in Moonbounce, Radioastronomy and DSN. It requieres advanced skills of electronics and software, only recommended to users with previous experience with tracking systems.

Warning this software is distributed as is and I can not supply support. I write  it for myself and now I share it for other users that are asking about my tracking system.

This source and the whole package comes without warranty. It may or may not harm your computer or cell phone. Please use with care. Any damage cannot be related back to the author. The source has been tested on a real environment and scanned for viruses and has passed all tests.