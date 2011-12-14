#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("B3h3m0th");

/* 
 * module_param(var, type, mode):
 * Il primo parametro e' il nome della variabile
 * Il secondo parametro e' il tipo della variabile
 * Il terzo ed ultimo parametro riguarada i permessi
 */
static int int_var = 0;
static char *str_var = "default";

module_param(int_var, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(int_var, "variabile di tipo intero");

module_param(str_var, charp, 0000);
MODULE_PARM_DESC(str_var, "Stringa, vettore di caratteri");

static int __init inizializzazione(void)
{
	printk(KERN_INFO "[module init...\n");
	printk(KERN_INFO "int_var e' un intero: %d\n", int_var);
	printk(KERN_INFO "str_var e' un vettore di caratteri: %s\n", str_var);
	return 0;
}

static void __exit pulizia(void)
{
	printk(KERN_INFO "...module exit]\n");
}

module_init(inizializzazione);
module_exit(pulizia);
