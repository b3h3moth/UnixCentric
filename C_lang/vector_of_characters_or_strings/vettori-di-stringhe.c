#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 20
#define ARRAY_SIZE 8

int main(int argc, char *argv[])
{
   /*
    * E' possibile omettere il numero di righe poichè sara automaticamente
    * determinato dal numero degli elementi presenti; però è necessario inserire
    * il numero delle colonne, in questo caso 8, nei casi in cui la stringa di
    * caratteri dovesse risultare di minor lunghezza, al resto delle celle sarà
    * inserito il carattere nullo '\0'.
    *
    * C'è però un problema evidente, e cioè che solo 3 stringhe di caratteri
    * hanno nomi sufficientemente lunghi, per il resto ci sarà spreco di
    * spazio
    */
   char planets[][ARRAY_SIZE] = { "plutone", "nettuno", "giove", "mercurio",
                                  "marte", "urano", "terra"};

   /* più efficiente  poiche' non si spreca spazio, ciascun puntatore puntera'
	* ad una stringa con dimensioni differenti l'un l'altra */
   char *pianeti[ARRAY_SIZE] = {"plutone", "nettuno", "giove", "mercurio", 
                                "marte","urano","terra"};

   for (int i=0; i<ARRAY_SIZE-1; i++) 
      printf("B: %d:%9s (%d byte)\n", i, pianeti[i], strlen(pianeti[i]));

   int dim;
   printf("Grandezza del vettore: ");
   scanf("%d", &dim);
   char *test[dim];
   char temp[MAX_STR];

   /* Creazione dinamica di un vettore di stringhe */
   for (int i=0; i<dim; i++) { 
      printf("inserisci la squadra '%d': ", i);
      scanf("%s", temp);
      test[i] = malloc(strlen(temp) * sizeof(char));
      strcpy(test[i], temp);
   }

   for(int i=0; i<dim; i++)
      printf("%s %d\n", test[i], strlen(test[i]));

   return(EXIT_SUCCESS);
}
