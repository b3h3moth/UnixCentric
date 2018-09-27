#include <linux/module.h>
#include <linux/kernel.h>

/*
 Diversamente dai moduli precedenti, nei quali si e' associato alla macro
 MODULE_NAME un nome specifico tra doppi apici, si utilizza come nome del modulo
 THIS_MODULE->name, ossia un riferimento al modulo corrente, ovvero il file
 contenente il modulo fatta eccezione per il suffisso .ko
*/
#define MODULE_NAME	THIS_MODULE->name
#define DIR_NAME	"test"
#define DIR_MODE	0700

/*
 Dal Kernel 2.5.7 la sys_call_table non e' piu' esportata, ma e' in memoria,
 pertanto per poter lavorarci e' necessario utilizzare il suo indirizzo,
 estraibile dalla lista dei simboli del kernel:
 $ cat /proc/kallsyms | grep sys_call_table

 E' ovvio che deve essere modificato a seconda della macchina.

#define SYS_CALL_ADDRESS	0xc0009a24    (kernel 2.6.32-5) PPC */
#define SYS_CALL_ADDRESS	0xc000a964 /* (kernel 2.6.39-2) PPC */
void **sys_call_table = (void **)SYS_CALL_ADDRESS;

MODULE_LICENSE("GPL");
MODULE_AUTHOR("B3h3m0th");
MODULE_DESCRIPTION("Intercepting mkdir() syscall");
MODULE_VERSION("0.1");

/* Un puntatore alla system call originale */
asmlinkage int (*original_mkdir)(char *path, mode_t mode);

/*
 La nuova system call; ogni qualvolta si tentera' di creare una directory che
 comprenda nel nome DIR_NAME sara' segnalato un messaggio di errore, nel log del
 kernel inoltre - tipicamente dmesg - sara' aggiunto un messaggio relativo alla
 system call intercettata.
*/
asmlinkage int new_mkdir(char *path, mode_t mode)
{
   if (strstr(path, DIR_NAME) != NULL) {
      printk(KERN_ALERT "[%s] Intercepting mkdir(\"%s\")\n", MODULE_NAME, path);
      return -1;
   }

   /*
    L'intercettazione sarebbe andata a buon fine anche senza il secondo
    parametro, tuttavia si e' potuto osservare che la nuova directory creata
    avrebbe avuto dei permessi non propriamente 'congrui' - verrebbe da dire
    generati casualmente; pertanto, per evitare la creazione di directory con
    permessi sconclusionati, e' stato  aggiunto il parametro relativo ai
    permessi stessi DIR_MODE.
   */
   return original_mkdir(path, DIR_MODE);
}

/* funzione di inizializzazione del modulo */
static int __init insert_mod(void)
{
   printk(KERN_ALERT "[%s] init\n", MODULE_NAME);

   original_mkdir = sys_call_table[__NR_mkdir];
   sys_call_table[__NR_mkdir] = new_mkdir;
   return 0;
}

/* funzione di uscita e pulizia del modulo */
static void __exit remove_mod(void)
{
   printk(KERN_ALERT "[%s] exit\n", MODULE_NAME);

   sys_call_table[__NR_mkdir] = original_mkdir;
}

module_init(insert_mod);
module_exit(remove_mod);
