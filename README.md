MTK_Loader
==========
For more information

http://reverse-stef.blogspot.de/2011/11/gsm-tracker-gt-170.html

Usage:

*./MTKload.py load_prog MT6223main.bin* 


```
Please press power and hold the button
Try connecting. Sending beacon 0xA0....
Send sync magic
Connect done

Upload file MT6223main.bin to 0x40001400
Bytes to send 9866
Block  0 send 1024k
Block  1 send 1024k
Block  2 send 1024k
Block  3 send 1024k
Block  4 send 1024k
Block  5 send 1024k
Block  6 send 1024k
Block  7 send 1024k
Block  8 send 1024k
Send last data 650
checksum of MT6223main.bin is 0x59a8
Checksum 0x59a8
Start program. good luck....
```

Open a terminal program with 115200 8N 1
and see the output

```
HW_CODE    = 0x6223
FW_VERSION = 0x8a00
HW_VERSION = 0x8a08
```
and the leds are changing from green to red to blue ...







