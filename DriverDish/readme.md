# DRIVERDISH.APP
[Version and download](#Versions)

This is the main program that is responsible for requesting data from the ephemeris server and communicating with ControllerDish.

<img src="https://github.com/ea3hmj/EME/raw/main/img/dd10.jpg" width="640">
<img src="https://github.com/ea3hmj/EME/raw/main/img/dd2.jpg" width="640">
<img src="https://github.com/ea3hmj/EME/raw/main/img/dd30.jpg" width="640">
<img src="https://github.com/ea3hmj/EME/raw/main/img/dd4.jpg" width="640">
<img src="https://github.com/ea3hmj/EME/raw/main/img/dd5.jpg" width="640">

Communications are RS-485 at 500000 bauds.

The ESP32 port is used for debug also at 500000 bauds.

It can handle CAT radios, you need to have [OMNIRIG v2.1](https://www.hb9ryz.ch/omnirig/) installed.

If you have [SpectraVue v3.41](http://www.rfspace.com/RFSPACE/SpectraVue.html) installed, the program can get the RMS value of the signal in continuous mode, and with this data we can get a heatmap or radiomap.

<img src="https://github.com/ea3hmj/EME/raw/main/img/heatmap.jpg" width="640">

<a name="Versions"></a>
## Versions
1.0.0	Initial version.

1.0.817	Display the ControllerDish version in the setup form.

1.0.825	stop tracking whith el<0.

1.0.827 buton stop now stop tracking & motors, Fonts update, Bug in window reposition

1.0.859 read ambient temp from encoder elevation

## Download
Download the app in [latest release page](https://ea3hmj.net/download/DriverDish.Setup.rar)

## Disclaimer
This is an antenna tracking system (software and hardware) designed for amateur use in Earth–Moon–Earth communication (EME), radioastronomy, amateur Deep Sky Network (DSN) and other Space Communication applications where accurate and high precision tracking are required. 
Proper use of the system requires electronics knowledge and some software skills. Thus, it is only recommended to users with previous experience with antenna tracking systems.

This software -including the source and the whole package- and hardware are distributed "as is" without any representation or warranty of any kind, either express or implied. 

Please note that I am not able to provide support for this antenna tracking system. I designed and wrote it for myself and I am willing to share it here for those asking about my tracking system. I do not guarantee the accuracy or completeness of the information and materials distributed here. The software source has been tested on a real environment and scanned for viruses and has passed all tests.

I shall not be liable for any errors or omissions and shall not be responsible for any damages arising from the use of this antenna tracking system. I shall not be held responsible for any issues or problems that may arise from the use of it. 
By using any part of this antenna tracking system (software or hardware), you acknowledge and agree to the terms of this disclaimer.
