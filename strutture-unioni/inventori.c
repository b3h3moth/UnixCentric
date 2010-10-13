#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part
{
   int number;
   char name[NAME_LEN+1];
   int on_hand;
   char inventory[MAX_PARTS];
};

int num_parts = 0 /* il numero di componenti attualmente memorizzati */

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

/****
 * main:
 * chiede all'utente di immettere un codice, poi chiama una funzione per
 * eseguire l'azione richiesta. Continua fino a quando l'utente non immette il
 * comando 'q'. Stampa un messaggio di errore se l'utente immette un codice non
 * ammesso
 */

int main(void)
{
   char code;

   for (;;)
   {
      printf("Enter operation code: ");
      scanf(" %c", &code);

      while (getchar() != '\n') /* Salta alla fine della riga */
      	 ;
      switch(code)
      {
      	 case 'i': insert();
	 	   break;
	 case 's': search();
	 	   break;
	 case 'u': update();
	 	   break;
	 case 'p': print();
	 	   break;
	 case 'q': return 0;
	 default: printf("Illegal code\n");
      }
      printf("\n");
   }


   return(EXIT_SUCCESS);
}

/* cerca un componente nel vettore inventory.
 * Restituisce l'indice all'interno del vettore se il numero del componente
 * viene trovato, altrimenti restituisce -1
 */
int find_part(int number)
{
   int i;
   for (i=0; i<num_parts; i++)
      if(inventory[i].number == number)
      	 return i;
   return -1
}

void insert(void);
void search(void);
void update(void);
void print(void);
