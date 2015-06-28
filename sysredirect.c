/* 
  Jun 2015 pmateti@wright.edu and asishsahadev@gmail.com
ARM KERNEL MODULE
This kernel module is intended to work on ARM architecture and can redirect one system call to another, perhaps
  to sys-ni-syscall (sys-call-not-implemented).
The module was tested on Goldfish kernel v3.4 and runs successfully in Lollipop.
*/

#include <linux/kernel.h>       
#include <linux/module.h>       
#include <linux/unistd.h>       
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("asish + pmateti");
MODULE_DESCRIPTION("syscall redirect 20150624");

void * * sys_call_table = 0;
void * oldptr  = 0;
void * newptr  = 0;
#define SYSCALLTBLGF  0xc000ef44   // System call table address of Goldfish kernel.
int init_module()
{
        sys_call_table = (void*)SYSCALLTBLGF;
	oldptr = sys_call_table[__NR_read];
	printk(KERN_DEBUG "Sys_call_table address = %p", sys_call_table);
        printk(KERN_DEBUG "Address of __NR_read = %p\n", oldptr);

	// Here __NR_read is pointing to __NR_read itself. Hence, the new address is the same as old address.
	sys_call_table[__NR_read]  = sys_call_table[__NR_read];
	newptr = sys_call_table[__NR_read];
	printk(KERN_DEBUG "New Address of __NR_read = %p\n", newptr);
	
        return 0;
}

void cleanup_module()
{
        printk("\nCleaning up!!\n");

        sys_call_table[__NR_read]  = oldptr;
        printk(KERN_DEBUG "Address of __NR_read = %p\n", oldptr);
}
