#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Luca Suriano");
MODULE_DESCRIPTION("A Hello, World module");

/* init function, called when the modudle is loading */
static int hello_init(void)
{
   printk(KERN_ALERT "Hello world module.\n");
   printk(KERN_INFO "KERN_INFO ... hello\n");
   return 0;
}

/* the exit function, called when the module is rmoved */
static void hello_exit(void)
{
   printk(KERN_ALERT "Exit hello world module.\n");
}

module_init(hello_init);
module_exit(hello_exit);

/* 
 * KERN_ALERT
 * KERN_INFO
 * KERN_NOTICE
 * KERN_WARNING
 * KERN_ERR
 * KERN_CRIT
 */
