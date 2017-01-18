#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nota "Vector of strings" e "array of pointers" sono sinonimi

#define STR_LEN 10
#define ARR_SIZE 7

int main(int argc, char *argv[]) {
   /* E' possibile omettere il numero di righe poichè sara automaticamente
   determinato dal numero degli elementi presenti, è necessario invece inserire
   il numero delle colonne, in questo caso STR_LEN.

   Nei casi in cui la stringa di caratteri dovesse risultare di minor
   lunghezza rispetto a STR_Len, al resto delle celle sarà inserito il
   'null character, vale a dire '\0'.

   C'è però un problema evidente, ovver solo 3 stringhe di caratteri
   hanno nomi sufficientemente lunghi, per il resto ci sarà spreco di spazio.
   */
   char planets[][STR_LEN] = {"plutone", "nettuno", "giove", "mercurio",
                                "marte", "urano", "terra"};

   printf("Size of 'planets': %zu\n", sizeof(planets));
   for (int i=0; i<ARR_SIZE; i++)
      printf("A: %d:%10s (%zu byte)\n", i, planets[i], strlen(planets[i]));

   /* Per ovviare allo spreco di byte, come nel caso precedente, ed essere
   anche piu' efficienti, e' consigliabile implementare un puntatore ad un
   array di stringhe, dove ciascuna stringa sara' esattamente delle dimensioni
   richieste. */
   char *pianeti[ARR_SIZE] = {"plutone", "nettuno", "giove", "mercurio",
                                "marte", "urano", "terra"};

   printf("Size of 'pianeti': %zu\n", sizeof(pianeti));
   for (int i=0; i<ARR_SIZE; i++)
      printf("A: %d:%10s (%zu byte)\n", i, pianeti[i], strlen(pianeti[i]));

   puts("\n(dynamic array of pointers)");
   int dim;
   printf("Please type how many planet do you want: ");
   scanf("%d", &dim);
   char *dyn_planets[dim];
   char temp[STR_LEN];

   /* Creazione dinamica di un vettore di stringhe */
   for (int i=0; i<dim; i++) {
      printf("type the planet's name '%d': ", i);
      scanf("%10s", temp);
      dyn_planets[i] = malloc(strlen(temp) * sizeof(char));
      strcpy(dyn_planets[i], temp);
   }

   for(int y=0; y<dim; y++)
      printf("B: %d:%10s (%zu byte)\n", y, dyn_planets[y], strlen(dyn_planets[y]));

   return(EXIT_SUCCESS);
}
