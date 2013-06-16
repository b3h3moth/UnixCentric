#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Si utilizza l'allocazione dinamica della memoria, dapprima per la costruzione
di un vettore con malloc, poi per il suo ampliamento, con realloc. */

int main(int argc, char **argv, char **envp) {
   int n, new_alloc, tmp = 0;
   int c;
   int *vettore;

   printf("Inserire lunghezza vettore: \n");
   scanf("%d", &n);

   vettore = malloc(n * sizeof(int)); /* Oppure avrei potuto utilizzare
   					 vettore = calloc(n, sizeof(int)); 
				      */

   for (c = 0; c < n; c++) {
      printf("Inserire un valore per l'elemento '%d' del vettore: ", c+1);
      scanf("%d", &vettore[c]);
   }

   for (c = n-1; c >= 0; c--) {
      printf("vettore[%d] = %d\n", c+1, vettore[c]);
   }

   printf("\nRIALLOCAZIONE: AMPLIAMENTO DEL VETTORE\n"
   	  " -> Inserire un intero : ");
   scanf("%d", &new_alloc);

   printf("\nVettore originario : \"%2d\" elementi\n", n);
   printf("Vettore ampliato   : \"%2d\" elementi\n", n+new_alloc);

   if (new_alloc > 0) {
      tmp = n;
      n += new_alloc;
      vettore = realloc(vettore, (n * sizeof(int)));
   }

   printf("\nInizializzazione nuovi elementi del vettore\n");
   for (c=tmp; c<n; c++) {
      printf("Inserire un valore per l'elemento '%d' del vettore: ", 
              ((tmp++)+1));
      scanf("%d", &vettore[c]);
   }

   printf("\n");

   for(c = n-1; c >= 0; --c) {
      printf("vettore[%d] = %d\n", c+1, vettore[c]);
   }

   free(vettore);
   return(EXIT_SUCCESS);
}
