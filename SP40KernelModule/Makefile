# Install the kernel
# prepage the kernel
# Install Android ndk and sdk

# set your path
TOOLS=
obj-m := pcf8574.o hello_sample.o i2c-dev.o
# path to the SP40 kernel
KDIR := $(TOOLS)/alps/kernel
PWD := $(shell pwd)
# The Android ndk Version 4. Do not use a higer version. we need right gcc version
CCPATH := $(TOOLS)/android-ndk-r4/build/prebuilt/linux-x86/arm-eabi-4.4.0/bin

default:
	$(MAKE) ARCH=arm CROSS_COMPILE=$(CCPATH)/arm-eabi- -C $(KDIR) M=$(PWD) modules

copy:
	$(TOOLS)/android-sdk/android-sdk-linux/platform-tools/adb push hello_mod.ko /data
	
load:
	$(TOOLS)/android-sdk/android-sdk-linux_x86/platform-tools/adb shell rmmod hello_mod.ko
	$(TOOLS)/android-sdk/android-sdk-linux_x86/platform-tools/adb shell insmod /data/hello_mod.ko
#	$(TOOLS)/android-sdk-linux_x86/platform-tools/adb shell insmod /data/pcf8574.ko force=2,0x7E

clean:
	rm -f *.o *.ko *.mod.c Module.symvers modules.order