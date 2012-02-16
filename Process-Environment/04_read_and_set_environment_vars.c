#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/*
HEADER    : <stdlib.h>
PROTOTYPE : char *getenv(const char *name);
SEMANTICS : La funzione getenv() verifica se nell'ambiente del processo
            vi e' la variabile d'ambiente 'name'.
RETURNS   : Il puntatore alla variabile d'ambiente in caso di successo, NULL in 
            caso di errore
--------------------------------------------------------------------------------
La funzione getenv() e' di sola lettura, nel senso che consente di  ottenere i 
valori delle variabili d'ambiente.

HEADER    : <stdlib.h>
PROTOTYPE : int putenv(const char *str);
            int stenev(const char* name, const char *value, in rewrite);
	    int unsetenv(const char *name);
SEMANTICS : La funzione putenv() aggiunge la stringa 'str' all'ambiente; la
            funzione setenv() imposta la variabile di ambiente 'name' al valore
	    'value', impostando la 'rewrite' ad 1 per sovrascriverla a 0 se e'
	    nuova; la funzione unsetenv() rimuove la variabile d'ambiente 'name'
	    dalla environment list.
RETURNS   : 0 in caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
Per modificare le variabili di ambiente si utilizzano le 3 funzioni su citate;
da notare che per quanto riguarda la setenv(), il terzo parametro 'rewrite' va
impostato ad 1 per sovrascrivere una variabile gia' esistente, a 0 se la
variabile e' nuova. Il parametro della funzione putenv() deve essere inserito
nella forma "name=value".

Da notare che sia la modifica sia l'aggiunta di una nuova variabile d'ambiente
avranno la durata del processo in esecuzione, ossia a programma chiuso le
modifiche andranno perdute.

Per cancellare tutte le variabili d'ambiente si usa la funzione clearenv():

HEADER    : <stdlib.h>
PROTOTYPE : int clearenv(void);
SEMANTICS : La funzione cancella tutte le variabili d'ambiente
RETURNS   : 0 in caso di sucesso, non-zero in caso di errore
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
   char *home_dir, *default_editor_envvar, *new_editor_envvar;
   char *new_var, *new_var_val;

   /* Verifica la presenza della variabile d'ambiente HOME */
   if ( (home_dir = getenv("HOME")) == NULL) {
      fprintf(stderr, "Err.(%s) get HOME env_var\n", strerror(errno));
      exit(EXIT_FAILURE);
   }
  
   /* Su stdout il valore della variabile d'ambiente HOME */
   printf("$HOME: %s\n", home_dir);

   /* Verifica la presenza della varibile d'ambiente EDITOR */
   if ((default_editor_envvar = getenv("EDITOR")) == NULL) {
      fprintf(stderr, "Err.(%s) get EDITOR env_var\n", strerror(errno));
      exit(EXIT_FAILURE);
   }

   /* Su stdout la variabile di ambiente EDITOR al default */
   printf("Valore di default $EDITOR -> ");
   printf("$EDITOR: %s\n", default_editor_envvar);

   /* Si imposta la variabile d'ambiente EDITOR ad un nuovo valore, si sarebbe
   potuto utilizzare:
   putenv("EDITOR=nano");
   */
   if ((setenv("EDITOR", "nano", 1)) == -1) {
      fprintf(stderr, "Err.(%s) set EDITOR env_var\n", strerror(errno));
      exit(EXIT_FAILURE);
   }

   /* Se si fosse stampato il vecchio risultato, si sarebbe ottenuto ancora
   il valore di default, per cui e' necessario provvedere ad una nuova 
   verifica con una nuova variabile a cui passare il valore */
   if ((new_editor_envvar = getenv("EDITOR")) == NULL) {
      fprintf(stderr, "Err.(%s) get EDITOR env_var\n", strerror(errno));
      exit(EXIT_FAILURE);
   }

   /* Su stdout la variabile di ambiente EDITOR dopo la modifica */
   printf("Valore $EDITOR modificato -> ");
   printf("$EDITOR: %s\n", new_editor_envvar);

   /* Crea una nuova variabile d'ambiente TEST */
   new_var= "TEST";
   new_var_val = "Testing";

   /* In questo caso il valore di overwrite non e' necessario, in quanto
   la variabile deve essere creata da zero */
   setenv(new_var, new_var_val, 0); 	

   printf("Nuova variabile di ambiente TEST: %s\n", getenv("TEST"));

   /* Si rimuove  la variabile precedentemente creata */
   unsetenv(new_var);

   if ((new_var = getenv("TEST")) == NULL)
      fprintf(stderr, "Variabile di ambiente TEST non esistente\n");

   return(EXIT_SUCCESS);
}
