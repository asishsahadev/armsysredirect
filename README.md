# armsysredirect
Redirects system calls of Android Kernel
This was done as apart of thesis work done at Amrita Vishwa Vidyapeetham.

This program is intended to produce a LKM for redirecting system calls in Anrdoid kernel. This LKM redirects one system calls to another. 

The Makefile contained with this LKM contains the relevant instructions required for cross-compiling the program to ARM architecture as a module.

The file generated sysredirect.ko is pushed to the emulator which uses goldfish kernel v.3.4 using the command
insmod sysredirect.ko

The module can be removed using the commnand
rmmod sysredirect
