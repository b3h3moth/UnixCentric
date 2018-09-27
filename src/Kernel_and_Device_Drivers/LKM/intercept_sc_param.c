/*
 Il codice e' identico a intercept_system_call.c, vi e' solo la possibilita' di
 poter definire il nome della directory su cui scattera' l'intercettazione.

 Uso:
 $ sudo insmod <modulo.ko> dir_name=<dir>
 Ovvero, ciascuna chiamata a mkdir() che avra' nel nome l'occorrenza <dir>
 sara'intercettata e pertanto vi sara' un errore in stderr col relativo
 messaggio nel kernel log.

 Se invece si procedera' senza parametri:
 $ sudo insmod <modulo.ko>
 La system call mkdir() intercettera' di default le occorrenze DIR_NAME.
*/
#include <linux/module.h>
#include <linux/kernel.h>

#define MODULE_NAME		"intercept-param"
#define DIR_MODE		0644
#define SYS_CALL_ADDRESS	0xc0009a24

MODULE_LICENSE("GPL");
MODULE_AUTHOR("B3h3m0th");
MODULE_DESCRIPTION("Intercepting mkdir() syscall with parameters");
MODULE_VERSION("0.2");


void **sys_call_table = (void **)SYS_CALL_ADDRESS;

module_param(dir_name, charp, 0);
MODULE_PARM_DESC(dir_name, "stringa da cercare nel nome della directory");

asmlinkage int (*original_mkdir)(char *path, mode_t mode);

asmlinkage int new_mkdir(char *path, mode_t mode)
{
   if (strstr(path, dir_name) != NULL) {
      printk(KERN_ALERT "[%s] Intercepting mkdir(\"%s\")\n", MODULE_NAME, path);
      return -1;
   }

   return original_mkdir(path, DIR_MODE);
}

static int __init insert_mod(void)
{
   printk(KERN_ALERT "[%s] init\n", MODULE_NAME);

   original_mkdir = sys_call_table[__NR_mkdir];
   sys_call_table[__NR_mkdir] = new_mkdir;
   return 0;
}

static void __exit remove_mod(void)
{
   printk(KERN_ALERT "[%s] exit\n", MODULE_NAME);

   sys_call_table[__NR_mkdir] = original_mkdir;
}

module_init(insert_mod);
module_exit(remove_mod);
