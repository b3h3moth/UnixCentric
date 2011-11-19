#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

/* MACRO for documentation purposes */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Luca Suriano");
MODULE_DESCRIPTION("Basic hello world module, just for learning the basics");

/* init function, called when the modudle is loading */
static int hello_init(void)
{
   printk(KERN_ALERT "Init: \"Hello World\" module is up\n");
   return 0;
}

/* the exit function, called when the module is rmoved */
static void hello_exit(void)
{
   printk(KERN_ALERT "Exit: \"Hello World\" module is down\n");
}

module_init(hello_init);
module_exit(hello_exit);

/* Loglevel MACRO:
 * KERN_ALERT
 * KERN_INFO
 * KERN_NOTICE
 * KERN_WARNING
 * KERN_ERR
 * KERN_CRIT
 * KERN_DEBUG
 * KERN_EMERG
 */
