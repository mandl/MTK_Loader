#preferences for cross development


TOOLCHAIN=/opt/arm/arm-2013.05/bin/arm-none-eabi-

CC=$(TOOLCHAIN)gcc
AS=$(TOOLCHAIN)as
LD=$(TOOLCHAIN)ld
OBJCOPY=$(TOOLCHAIN)objcopy

#flags
CFLAGS =  -march=armv5t -O0 -g -fomit-frame-pointer -nostartfiles -nostdlib -Wa,-adhlns=$(subst $(suffix $<),.lst,$<)

ASFLAGS = 

BASENAME = main

ELFFILE = $(BASENAME).elf
BINARY = $(BASENAME).bin
SREC = $(BASENAME).srec
HEX = $(BASENAME).hex

#LSCRIPT = flash6223.lds
LSCRIPT = ram6223.lds
#LSCRIPT = ext_ram6223.lds



#target
TARGETS = $(ELFFILE) $(BINARY) $(SREC) $(HEX)

OBJS = crt.o main.o delay.o uart.o led.o
       

all:$(TARGETS)


$(ELFFILE): $(OBJS) Makefile
	$(LD) -o $(ELFFILE) $(OBJS) -L . -l mini -T $(LSCRIPT) \
	-Map $(BASENAME).map


$(BINARY): $(ELFFILE)
	$(OBJCOPY) -O binary -S $(ELFFILE) $(BINARY)

$(SREC): $(ELFFILE)
	$(OBJCOPY) -O srec -S $(ELFFILE) $(SREC)

$(HEX): $(ELFFILE)
	$(OBJCOPY) -O ihex -S $(ELFFILE) $(HEX)

clean:
	rm -f *.o *.lst *.map $(TARGETS)


