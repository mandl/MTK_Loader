
**Usage:**

MTKload.py -h



**MT6223_BasebandOn.txt**

This is a simple CVS file.

Register value and command. MTKload can send this to your device
before doing a upload.
So we can switch on the device, before we send the programm.
And you can release the power button. This is very usefull for
longer uploads.

```
0x80210050,0xA357,RTC_POWERKEY1
0x80210054,0x67D2,RTC_POWERKEY2
0x80210000,0x430E,Power up Baseband
0x80040000,0x2200,Disable watchdog
0x80010078,0x0,EMI_ADMUX
```

**MT6223_ExtMem.txt**  
This files configures the external memory. So we can direct 
upload to externel memory. Useful for programms bigger then 
the internal memory.

Sample:

Uploading main.bin to address 0x0000

*MTKload.py --writeregfile MT6223_ExtMem.txt load_prog main.bin 0x0000*

**MT6223_GetRegs.txt**

Read some registers from device

*MTKload.py --readregfile MT6223_GetRegs.txt load_prog main.bin*

Format: 

Register Value, 0x32=32 bit read oder 0x16=16 bit read , Comment

```
0x80010078,0x32,EMI_ADMUX
0x80010000,0x32,EMI_CONA
0x80010008,0x32,MTK6223_EMI_CONB
0x80010044,0x32,MTK6223_EMI_GEN
0x80010040,0x16,MTK6223_EMI_REMAP
0x00000000,0x16,Memory at 0x0
```





