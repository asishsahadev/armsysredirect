obj-m := sysredirect.o
KERNEL_DIR := /*Path to Android kernel source */
CCPATH := /*Path to Cross-compiler dir*/
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
