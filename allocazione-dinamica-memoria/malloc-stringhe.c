#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * L'allocazione dinamica della memoria è usato di continuo con le stringhe.
 *
 * Prototipo malloc:
 *
 * void *malloc(size_t size);
 * 
 * Alloca un blocco di size byte di tipo size_t, ossia un intero senza segno, 
 * restituendo un puntatore a quest'ultimo.
 * 
 * Per allocare una stringa, in un certo senso, il lavoro è facilitato, poichè
 * per si dovrà utilizzare un char che corrisponde esattamente a 1byte, per cui,
 * una stringa di n caratteri, corrisponderà esattamente a sizeof(char) * n.
 *
 * Da non dimenticare di aggiungere un byte per il carattere di fine stringa \0.
 */

/*
 * Come esempio si crea una funzione che concatena due stringhe
 */

char *concat(const char *s1, const char *s2);
void freeMemory(char *block);

int main(int argc, char *argv[])
{
   char *stringa = concat("Learning"," C-ANSI (C99)");
   printf("%s\n", stringa);
   freeMemory(stringa);
   printf("%s\n", stringa);


   return(EXIT_SUCCESS);
}

char *concat(const char *s1, const char *s2)
{
   char *result;

   result = malloc(strlen(s1) + strlen(s2) +1);

   if (result == NULL) {
      printf("Error: malloc failed in concat\n");
      exit(EXIT_FAILURE);
   }

   strcpy(result, s1);
   strcat(result, s2);

   return result;
}

void freeMemory(char *block)
{
   printf("-- FREE --\n");
   free(block);
}
