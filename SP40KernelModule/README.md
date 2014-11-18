**Building a kernel driver for SP40 ( MT6516 )**

More information

http://reverse-stef.blogspot.de/2012/04/simvally-sp-40-mt-6516.html


**Install the kernel** 

**Install Android NDK ann SDK**


Compile the module

*make -e TOOLS=<path to your toolchain (kernel sdk ndk )>*

Load the kernel via adb to the device and load the driver

*make copy*

*make load*

Take a look at the Makefile
