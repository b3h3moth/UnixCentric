#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 10
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
   char planets[][ARRAY_SIZE] = {"plutone", "nettuno", "giove", "mercurio", 
                                "marte", "urano", "terra"};

   for (int j=0; j<ARRAY_SIZE-1; j++) 
      printf("A: %d:%100s (%d byte)\n", j, planets[j], strlen(planets[j]));


   /* più efficiente  poiche' non si spreca spazio, ciascun puntatore puntera'
	* ad una stringa con dimensioni differenti l'un l'altra */
   char *pianeti[ARRAY_SIZE] = {"plutone", "nettuno", "giove", "mercurio", 
                                "marte", "urano", "terra"};

   for (int i=0; i<ARRAY_SIZE-1; i++) 
      printf("B: %d:%10s (%d byte)\n", i, pianeti[i], strlen(pianeti[i]));

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
