obj-m := sysredirect.o
KERNEL_DIR := /media/kdev/Work1/Androidkernel/goldfish
CCPATH := /media/kdev/Work1/Androidkernel/NDK/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/
CCPATH_EXT := $(CCPATH)arm-linux-androideabi-
ARCH=arm
SUBARCH=arm
 
all:
	        make ARCH=arm CROSS_COMPILE=$(CCPATH_EXT) -C $(KERNEL_DIR) M=$(PWD) modules
clean:
	        make -C $(KERNEL_DIR) M=$(PWD) clean
		rm -rf *.c~
		rm -rf *.o
		rm -f modules.order
