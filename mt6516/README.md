

**MT6515**


TCM RAM 32K  0x5000 0000

0x4000_0000 ~ 0x4001_7fff 96 KB Internal SRAM
0x4002_0000 ~ 0x4004_3fff 144KB Internal SRAM


make ARCH=arm CROSS_COMPILE=arm-none-eabi- 


./MTKload.py  --speed load_prog u-boot.bin 0x40020000


50004970: 00000000 68f17348 68f17348 68f17348    ....Hs.hHs.hHs.h               
50004980: 68f17348 544f4f42 44414f4c 00215245    Hs.hBOOTLOADER!.               
50004990: 36313156 0000f7ac 40002000 a040c7ad    V116..... .@..@.               
500049a0: 4949464e 004f464e 08000001 00400005    NFIINFO.......@.               
500049b0: 10000040 00160010 00000000 00000000    @...............               
500049c0: 00000000 ffff0000 00000000 00000000    .

**Using U-Boot**

=> bdinfo                                                                       
arch_number = 0x00000000                                                        
boot_params = 0x00000000                                                        
DRAM bank   = 0x00000000                                                        
-> start    = 0x00000000                                                        
-> size     = 0x08000000                                                        
baudrate    = 115200 bps                                                        
relocaddr   = 0x07FF0000                                                        
reloc off   = 0xC7FD0000                                                        
irq_sp      = 0x07ECFEF0                                                        
sp start    = 0x07ECFEE0    
