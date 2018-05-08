#include <stdio.h>
#include <stdlib.h>

#define TRUE 		1
#define FALSE 		0

struct lista {
   int elem;
   struct lista *next;
};

typedef struct lista TipoNodoLista;
typedef TipoNodoLista *TipoLista;
typedef int Bool;

/* Nel C99 il tipo di dato booleano e' stato inserito, ed e' una parola chiave
 * del linguaggio stesso peraltro, essa e':
 * "_Bool" o "bool"
 * _Bool var; bool var; 
 * Si possono assegnare a tale tipo di variabile solo "0" o "1" */


/******************************************************************************
 * OPERAZIONI ELEMENTARI
 ******************************************************************************
 * Tali operazioni possono essere eseguite mediante operazioni che non
 * interagiscono con elementi della lista successivi al primo.
 *****************************************************************************/

/* Inizializzazione di una lista a NULL, ovvero vuota */
void InitLista(TipoLista *lis);

/* Verifica lista vuota */
Bool TestListaVuota(TipoLista lis);

/* Inserimento di un elemento nella lista */
void InserisciTestaLista(TipoLista *lis, int elem);

/* Restituisce l'elemento in testa alla lista */
void TestaLista(TipoLista lis);

/* Cancellazione del primo elemento della lista */
void CancellaTesta(TipoLista *lis);

/* Restituisce tutti gli elementi della lista */
void ScorriLista(TipoLista lis);

/* Restituisce il resto della lista, escluso il primo elemento */
void RestoLista(TipoLista *lis);

/******************************************************************************
 * OPERAZIONI NON ELEMENTARI ITERATIVE
 *****************************************************************************/
/* Inserimento di un elemento in coda  */
void InserisciCodaListaI(TipoLista *lis, int elem);

/* Cancellazione di una lista */
void CancellaLista(TipoLista *lis);

/* Funzione di supporto - Confronto tra due elementi - restutuisce TRUE o FALSE */
Bool UgualeElemento(int elem1, int elem2);

/* Verifica la presenza di un elemento nella lista */
Bool EsisteInLista(TipoLista lis, int elem);

/* Cancellazione della prima occorrenza di un elemento da una lista */
void CancellaElementoLista(TipoLista *lis, int elem);

/* Cancellazione di tutte le occorrenze di 'elem' nella lista */
void CancellaTuttaLista(TipoLista *lis, int elem);

/* Copia di una lista - Restituisce una copia della lista lis */
void CopiaLista(TipoLista lis, TipoLista *copia_lista);

/******************************************************************************
 * OPERAZIONI NON ELEMENTARI MEDIANTE RICORSIONE
 *****************************************************************************/
/* Inserimento di un elemento in coda ad una lista */
void InserisciCodaListaR(TipoLista *lis, int elem);


int main(int argc, char *argv[])
{
   TipoLista new_nodo, new_nodo_2, nodo_copia;
   InitLista(&new_nodo);
   system("tput reset"); /* Da eliminare su sistemi != da UNIX */
   printf("Test lista vuota: %d\n", TestListaVuota(new_nodo));
   InserisciTestaLista(&new_nodo, 100);
   InserisciTestaLista(&new_nodo, 200);
   ScorriLista(new_nodo);
   TestaLista(new_nodo);
   CancellaTesta(&new_nodo);
   RestoLista(&new_nodo);
   printf("-----------------------\n");
   ScorriLista(new_nodo);
   InserisciCodaListaI(&new_nodo, 1973);
   InserisciTestaLista(&new_nodo, 1);
   InserisciCodaListaI(&new_nodo, 0);
   printf("-----------------------\n");
   ScorriLista(new_nodo);
   CancellaTesta(&new_nodo);

   /* 
    * Si deve utilizzare un altro puntatore, la lista precedente non esiste
    * piu', poiche' deallocata 
    */
   InitLista(&new_nodo_2);
   InserisciCodaListaI(&new_nodo_2, 2000);
   InserisciCodaListaI(&new_nodo_2, 3000);
   InserisciTestaLista(&new_nodo_2, 1000);
   CancellaTesta(&new_nodo_2);
   printf("-----------------------\n");
   ScorriLista(new_nodo_2);
   printf("Cerca 3000 %d\n", EsisteInLista(new_nodo_2, 3000));
   printf("Cerca 1000 %d\n", EsisteInLista(new_nodo_2, 1000));
   printf("Cerca 2000 %d\n", EsisteInLista(new_nodo_2, 2000));
   InserisciTestaLista(&new_nodo_2, 4);
   InserisciCodaListaI(&new_nodo_2, 9);
   InserisciCodaListaI(&new_nodo_2, 3);
   InserisciTestaLista(&new_nodo_2, 1);
   printf("-----------------------\n");
   ScorriLista(new_nodo_2);
   printf("Cerca 3 %d\n", EsisteInLista(new_nodo_2, 3));
   printf("Cerca 1 %d\n", EsisteInLista(new_nodo_2, 1));
   printf("Cerca 2 %d\n", EsisteInLista(new_nodo_2, 2));
   printf("-----------------------\n");
   ScorriLista(new_nodo_2);
   CancellaElementoLista(&new_nodo_2, 2000);
   CancellaElementoLista(&new_nodo_2, 1);
   printf("-----------------------\n");
   ScorriLista(new_nodo_2);
   CancellaElementoLista(&new_nodo_2, 3000);
   printf("-----------------------\n");
   ScorriLista(new_nodo_2);
   InserisciTestaLista(&new_nodo_2, 100);
   InserisciTestaLista(&new_nodo_2, 100);
   InserisciCodaListaI(&new_nodo_2, 100);
   printf("-----------------------\n");
   ScorriLista(new_nodo_2);
   printf("-----------------------\n");
   CancellaTuttaLista(&new_nodo_2, 100);
   ScorriLista(new_nodo_2);
   printf("------ COPIA -------------\n");
   CopiaLista(new_nodo_2, &nodo_copia);
   ScorriLista(nodo_copia);
   CancellaLista(&nodo_copia);
   ScorriLista(nodo_copia);
   InserisciCodaListaR(&new_nodo_2, 200);
   InserisciTestaLista(&new_nodo_2, 1);
   ScorriLista(new_nodo_2);

   return(EXIT_SUCCESS);
}

void InitLista(TipoLista *lis)
{
   *lis = NULL;
}

Bool TestListaVuota(TipoLista lis)
{
   return (lis == NULL);
}

void InserisciTestaLista(TipoLista *lis, int elem)
{
   TipoLista paux;
   paux = malloc(sizeof(TipoNodoLista));
   paux->elem = elem;
   paux->next = *lis;
   *lis = paux;
}

void TestaLista(TipoLista lis)
{
   /* Avrei potuto inserire il controllo nel main e qui eseguire solo
     la printf; al momento ritengo questa tecnica piu' elegante, per cui
     la lascio.
    
     Per documentazione inserisco anche l'altra tecnica: 
     nel main avrei dovuto inserire:
    
    if (TestListaVuota != NULL)
    TestaLista(new_nodo);
    
     e qui nella funzione la sola printf; avrei avuto la certezza peraltro che
     avrebbe restituito solo il primo elemento.
    
     Oppure avrei potuto inserirlo qui:
    
   if (TestListaVuota != NULL)
      printf("Primo elemento della lista: %d\n", lis->elem);

   */
   while(TRUE) {
      if (TestListaVuota == NULL)
      	 break;
      
      printf("Primo elemento della lista: %d\n", lis->elem);
     	break;
   }

}

void CancellaTesta(TipoLista *lis)
{
   TipoLista paux;

   if (*lis != NULL) {
      paux = *lis;
      *lis = (*lis)->next;
      free(paux);
   }

}

void ScorriLista(TipoLista lis) 
{
   int i = 0;
   if (lis == NULL)
      printf("Lista Vuota\n");

   while (lis != NULL) {
      printf("[%d] - %d\n", i+1, lis->elem);
      lis = lis->next;
      i++;
   }

}

void RestoLista(TipoLista *lis)
{
   if (*lis != NULL)
      *lis = (*lis)->next;
}

void InserisciCodaListaI(TipoLista *lis, int elem)
{
   TipoLista ultimo;
   TipoLista paux;

   paux = malloc(sizeof(TipoNodoLista));
   paux->elem = elem;
   paux->next = NULL;

   if (*lis == NULL)
      *lis = paux;
   else {
      ultimo = *lis;
      while (ultimo->next != NULL)
      	 ultimo = ultimo->next;
      ultimo->next = paux;
   }
}

void CancellaLista(TipoLista *lis)
{
   TipoLista paux;

   while (*lis != NULL) {
      paux = *lis;
      *lis = (*lis)->next;
      free(paux);
   }
}

Bool UgualeElemento(int elem1, int elem2)
{
   if (elem1 == elem2) 
      return TRUE;
   else
      return FALSE;

   /*
    * In letteratura c'e' anche la seguente soluzione:
    * UgualeElemento = (elem1 = elem2);
    * ma GCC fornisce un errore di lvalue.
    */
}

Bool EsisteInLista(TipoLista lis, int elem)
{
   Bool trovato = FALSE;

   while (lis != NULL && !trovato) {
      if (UgualeElemento(lis->elem, elem))
      	 trovato = TRUE; /* Oppure: UgualeElemento(lis->elem, elem); */
      else
      	 lis = lis->next;
   }
   return trovato;
}

void CancellaElementoLista(TipoLista *lis, int elem)
{
   TipoLista prec; /* nodo precedente */
   TipoLista corr; /* nodo corrente */
   TipoLista paux; /* nodo ausiliario */

   /* Caso in cui ci si trova di fronte al primo nodo */
   if (elem == (*lis)->elem) {
      /* Memorizzazione del nodo che sta per essere rimosso */
      paux = *lis;
      *lis = (*lis)->next; /* passa al secondo nodo e si sgancia dal primo nodo */
      free(paux); /* eliminina il primo nodo */
   } else {
      prec = *lis;
      corr = (*lis)->next;
      /* Cicla per individuare la corretta posizione all'interno della lista */
      while ( corr != NULL &&  corr->elem != elem) {
      	 prec = corr;		/* elabora il nodo ... */
		 corr = corr->next;	/* ... successivo */
      }

      /* elimina il nodo puntato dal nodo corrente */
      if (corr != NULL) {
      	 paux = corr;
		 prec->next = corr->next;
		 free(paux);
      }
   }
}

void CancellaTuttaLista(TipoLista *lis, int elem)
{
   TipoLista prec; /* nodo precedente */
   TipoLista corr; /* nodo corrente */

   /* creazione del nodo generatore */
   prec = malloc(sizeof(TipoNodoLista));
   prec->next = *lis;
   *lis = prec;
   corr = prec->next;

   /* Scansione della lista e cancellazione di tutti gli elementi */
   while (corr != NULL) {
      if (UgualeElemento(corr->elem, elem)) {
      	 prec->next = corr->next;
		 free(corr);
      } else
      	 prec = prec->next;
	  corr = prec->next;
   }

   /* Eliminazione del nodo generatore */
   prec = *lis;
   *lis = prec->next;
   free(prec);
}

void CopiaLista(TipoLista lis, TipoLista *copia_lista)
{
   TipoLista prec;

   prec = malloc(sizeof(TipoNodoLista));
   *copia_lista = prec;
   while (lis != NULL) {
      prec->next = malloc(sizeof(TipoNodoLista));
      prec = prec->next;
      prec->elem = lis->elem;
      lis = lis->next;
   }

   /* Fine della lista */
   prec->next = NULL;

   prec = *copia_lista;
   *copia_lista = (*copia_lista)->next;
   free(prec);
}

void InserisciCodaListaR(TipoLista *lis, int elem)
{
	if (*lis == NULL) {
		*lis = malloc(sizeof(TipoNodoLista));
		(*lis)->elem = elem;
		(*lis)->next = NULL;
	} else 
		InserisciCodaListaR(&(*lis)->next, elem);
}
