# DRIVERDISH.APP
This is the main program that is responsible for requesting data from the ephemeris server and communicating with ControllerDish.

<img src="https://github.com/ea3hmj/EME/raw/main/img/dd1.jpg" width="640">
<img src="https://github.com/ea3hmj/EME/raw/main/img/dd2.jpg" width="640">
<img src="https://github.com/ea3hmj/EME/raw/main/img/dd3.jpg" width="640">
<img src="https://github.com/ea3hmj/EME/raw/main/img/dd4.jpg" width="640">
<img src="https://github.com/ea3hmj/EME/raw/main/img/dd5.jpg" width="640">

Communications are RS-485 at 500000 bauds.

The ESP32 port is used for debug also at 500000 bauds.

It can handle CAT radios, you need to have [OMNIRIG v2.1](https://www.hb9ryz.ch/omnirig/) installed.



If you have [SpectraVue v3.41](http://www.rfspace.com/RFSPACE/SpectraVue.html) installed, the program can get the RMS value of the signal in continuous mode, and with this data we can get a heatmap or radiomap.

<img src="https://github.com/ea3hmj/EME/raw/main/img/heatmap.jpg" width="640">

## Disclaimer
This is a tracking systems designed for amateur use in Moonbounce, Radioastronomy and DSN. It requieres advanced skills of electronics and software, only recommended to users with previous experience with tracking systems.

Warning this software is distributed as is and I can not supply support. I write  it for myself and now I share it for other users that are asking about my tracking system.

This source and the whole package comes without warranty. It may or may not harm your computer or cell phone. Please use with care. Any damage cannot be related back to the author. The source has been tested on a real environment and scanned for viruses and has passed all tests.