# armsysredirect
Redirects system calls of Android Kernel
This program is intended to produce a LKM has been made as a part of dissertation done on analysing system calls in Anrdoid kernel. This LKM redirects one system calls to another. 

The Makefile contained with this LKM contains the relevant instructions required for cross-compiling the program to ARM architecture as a module.

The file generated sysredirect.ko is pushed to the emulator which uses goldfish kernel v.3.4 using the command
insmod sysredirect.ko

The module can be removed using the commnand
rmmod sysredirect
