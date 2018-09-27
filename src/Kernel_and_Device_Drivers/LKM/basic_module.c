#include <linux/module.h>
#include <linux/kernel.h>

/* 
 Si specifica il nome del modulo; nel log del kernel pertanto sara' visualizzato 
 il nome associato a MODULE_NAME, naturalmente solo se lo si inserisse con una 
 loglevel macro, tipicamente KERN_ALERT e/o KERN_INFO.
*/

#define MODULE_NAME "hello_md"

/* 
 Gli headers dei moduli sono diversi dagli headers delle normali applicazioni in
 UserSpace, si deve far presente infatti che si sta interagendo con il kernel, 
 per cui sono necessari gli headers specifici del kernel in uso; le tipiche 
 sistem call sono implementate ad un livello piu' alto.
 
 MACRO documentative, collocate in ../linux/module.h 
*/

MODULE_LICENSE("GPL");
MODULE_AUTHOR("B3h3m0th");
MODULE_DESCRIPTION("Basic LKM; hello world module");
MODULE_VERSION("0.0");

/* routine di inizializzazione del modulo */
static int __init insert_mod(void)
{
   printk(KERN_ALERT "[%s] Init: \"Hello World\"\n", MODULE_NAME);
   return 0;
}

/* routine di pulizia/disattivazione  del modulo */
static void __exit remove_mod(void)
{
   printk(KERN_ALERT "[%s] Exit\n", MODULE_NAME);
}

module_init(insert_mod);
module_exit(remove_mod);

/* 
 Loglevel MACRO (collocate in ../linux/kernel.h):
 KERN_EMERG	<0>
 KERN_ALERT	<1>
 KERN_CRIT	<2>
 KERN_ERR	<3>
 KERN_WARNING	<4>
 KERN_NOTICE	<5>
 KERN_INFO	<6>
 KERN_DEBUG	<7>
*/
