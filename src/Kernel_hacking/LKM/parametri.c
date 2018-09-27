#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h> /* Per lavorare coi parametri */

#define MODULE_NAME "parametri_md"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("B3h3m0th");
MODULE_DESCRIPTION("LKM; routine per la gestione dei parametri");
MODULE_VERSION("0.1");

/* 
 Una delle routine mediante la quale e' possibile implementare i parametri in 
 un modulo e':
 module_param(var, type, mode):
 
 - var; Il primo parametro e' il nome della variabile
 - type; Il secondo parametro e' il tipo della variabile
 - mode; Il terzo ed ultimo parametro riguarada i permessi
*/

static int int_var = 0;
static char *str_var = "default";

module_param(int_var, int, 0);
MODULE_PARM_DESC(int_var, "variabile di tipo intero");

module_param(str_var, charp, 0);
MODULE_PARM_DESC(str_var, "Stringa, vettore di caratteri");

static int __init insert_mod(void)
{
	printk(KERN_ALERT "[%s] Init\n", MODULE_NAME);
	printk(KERN_ALERT "int_var e' un intero: %d\n", int_var);
	printk(KERN_ALERT "str_var e' un vettore di caratteri: %s\n", str_var);
	return 0;
}

static void __exit remove_mod(void)
{
	printk(KERN_ALERT "[%s] Exit\n", MODULE_NAME);
}

module_init(insert_mod);
module_exit(remove_mod);
