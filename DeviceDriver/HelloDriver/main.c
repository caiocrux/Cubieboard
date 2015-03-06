/*Write a Linux kernel module, and stand-alone Makefile, that when loaded
prints to the kernel debug log level, "Hello World!"  Be sure to make
the module unloadable as well.

The Makefile should build the kernel module against the source for the
currently running kernel, or, use an environment variable to specify
what kernel tree to build it against.*/

#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>      // included for __init and __exit macros

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Caio Cruz");
MODULE_DESCRIPTION("A Simple Hello World module to Eudyptula Challenge");

static int hello_init(void)
{
    printk(KERN_DEBUG "Hello world!\n");
    return 0;    // Non-zero return means that the module couldn't be loaded.
}

static void hello_cleanup(void)
{
    printk(KERN_DEBUG "Cleaning up module.\n");
}

module_init(hello_init);
module_exit(hello_cleanup);
