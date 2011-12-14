#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

/* Nota: Gli headers dei moduli sono diversi dagli headers delle normali
 * applicazioni in UserSpace, essi infatti sono collocati tipicamente in
 * linux-headers-`uname -r` */

/* MACRO documentative, collocate in ../linux/module.h */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("B3h3m0th");
MODULE_DESCRIPTION("Basic LKM; hello world module");
MODULE_VERSION("0.0");

/* funzione di inizializzazione, chiamata da insmod */
static int __init init_routine(void)
{
   printk(KERN_ALERT "Init: \"Hello World\" module is up\n");
   return 0;
}

/* funzione di uscita o pulizia, chiamata con rmmod */
static void __exit exit_routine(void)
{
   printk(KERN_ALERT "Exit: \"Hello World\" module is down\n");
}

module_init(init_routine);
module_exit(exit_routine);

/* Loglevel MACRO collocate in ../linux/kernel.h
 * KERN_EMERG	<0>
 * KERN_ALERT	<1>
 * KERN_CRIT	<2>
 * KERN_ERR	<3>
 * KERN_WARNING	<4>
 * KERN_NOTICE	<5>
 * KERN_INFO	<6>
 * KERN_DEBUG	<7>
 */
