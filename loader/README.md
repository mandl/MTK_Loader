
Usage:

MTKload.py -h



*MT6223_BasebandOn.txt*

This is a CVS file.

Register value and command. MTKLoad can send this to your device
So we can switch on the device before we send the programm. And you can
release the power button. This is full for longer uploads.

```
0x80210050,0xA357,RTC_POWERKEY1
0x80210054,0x67D2,RTC_POWERKEY2
0x80210000,0x430E,Power up Baseband
0x80040000,0x2200,Disable watchdog
0x80010078,0x0,EMI_ADMUX
```

*MT6223_ExtMem.txt*  
This files configures the external memory. So we can direct 
upload to externel memory. Useful for programms bigger then 
the internal memory.

Sample:

Uploading main.bin to address 0x0000

MTKload.py --writeregfile MT6223_ExtMem.txt load_prog main.bin 0x0000




