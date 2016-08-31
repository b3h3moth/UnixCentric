#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Si utilizza l'allocazione dinamica della memoria, dapprima per la costruzione
di un vettore con malloc, poi per il suo ampliamento, con realloc. */

int main(int argc, char **argv, char **envp) {
   int n, new_alloc, tmp = 0;
   int c;
   int *vettore;

   printf("Entry vector of integer's size [1-9]: ");
   
   if (scanf("%1d", &n) != 0) {
       vettore = malloc(n * sizeof(int)); 
       /* Oppure avrei potuto utilizzare: vettore = calloc(n, sizeof(int)); */
   } else {
       fprintf(stderr, "Err. please entry an integer\n");
       exit(EXIT_FAILURE);
   }

   for (c = 0; c < n; c++) {
      printf("Entry '%d' element value: ", c+1);
      scanf("%d", &vettore[c]);
   }

   for (c = n-1; c >= 0; c--) {
      printf("vector[%d] = %d\n", c+1, vettore[c]);
   }

   printf("\nRealloc\n"
   	  " -> Entry new size: ");
   if (scanf("%1d", &new_alloc) != 0) {
      if (new_alloc > 0) {
          tmp = n;
          n += new_alloc;
          vettore = realloc(vettore, (n * sizeof(int)));
      }
   } else {
       fprintf(stderr, "Err. please entry an integer\n");
       exit(EXIT_FAILURE);
   }

   printf("\n  Originary vector: \"%2d\" elements\n", n);
   printf("Reallocated vector: \"%2d\" elements\n", n+new_alloc);


   printf("\nInit new vector elements\n");
   for (c=tmp; c<n; c++) {
      printf("Entry '%d elemen value: ",  (tmp++) + 1);
      scanf("%d", &vettore[c]);
   }

   printf("\n");

   for(c = n-1; c >= 0; --c) {
      printf("vector[%d] = %d\n", c+1, vettore[c]);
   }

   free(vettore);
   return(EXIT_SUCCESS);
}
