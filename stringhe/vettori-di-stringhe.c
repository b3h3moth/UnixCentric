#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
   int i;
   char planets[][8] = {"plutone","nettuno","giove","mercurio","marte","urano","terra"};

   /* più efficiente così
    */
   char *pianeti[8] = {"plutone","nettuno","giove","mercurio","marte","urano","terra"};

   for (i=0; i<7; i++) 
      printf("%s %s\n", planets[i], pianeti[i]);

   int dim;
   printf("Grandezza del vettore: ");
   scanf("%d", &dim);
   char *test[dim];
   char temp[40];

   for (i=0; i<dim; i++) { 
      printf("inserisci la '%d' squadra: ", i);
      scanf("%s", temp);
      test[i] = malloc(strlen(temp) * sizeof(char));
      strcpy(test[i], temp);
   }

   for(i=0; i<dim; i++)
      printf("%s %d\n", test[i], strlen(test[i]));

   return(EXIT_SUCCESS);
}
