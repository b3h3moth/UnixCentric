#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nota "Vector of strings" e "array of pointers" sono sinonimi

#define MAX_STR 10
#define ARRAY_SIZE 8

int main(int argc, char *argv[]) {
   /* E' possibile omettere il numero di righe poichè sara automaticamente
   determinato dal numero degli elementi presenti, è necessario invece inserire
   il numero delle colonne, in questo caso ARRAY_SIZE.

   Nei casi in cui la stringa di caratteri dovesse risultare di minor
   lunghezza rispetto a MAX_STR, al resto delle celle sarà inserito il
   'null character, vale a dire '\0'.

   C'è però un problema evidente, ovver solo 3 stringhe di caratteri
   hanno nomi sufficientemente lunghi, per il resto ci sarà spreco di spazio.
   */
   char planets[][ARRAY_SIZE] = {"plutone", "nettuno", "giove", "mercurio",
                                "marte", "urano", "terra"};

   /* Per ovviare allo spreco di byte, come nel caso precedente, ed essere
   anche piu' efficienti, e' consigliabile implementare un puntatore ad un
   array di stringhe, dove ciascuna stringa sara' esattamente delle dimensioni
   richieste. */
   char *pianeti[ARRAY_SIZE] = {"plutone", "nettuno", "giove", "mercurio",
                                "marte", "urano", "terra"};

   for (int i=0; i<ARRAY_SIZE-1; i++)
      printf("A: %d:%10s (%d byte)\n", i, pianeti[i], strlen(pianeti[i]));

   int dim;
   printf("Grandezza del vettore: ");
   scanf("%d", &dim);
   char *dyn_planets[dim];
   char temp[MAX_STR];

   /* Creazione dinamica di un vettore di stringhe */
   for (int i=0; i<dim; i++) {
      printf("inserisci il pianeta '%d': ", i);
      scanf("%10s", temp);
      dyn_planets[i] = malloc(strlen(temp) * sizeof(char));
      strcpy(dyn_planets[i], temp);
   }

   for(int y=0; y<dim; y++)
      printf("B: %d:%10s (%d byte)\n", y, dyn_planets[y], strlen(dyn_planets[y]));

   return(EXIT_SUCCESS);
}
