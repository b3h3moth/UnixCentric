#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 32

int read_line(char str[], int n);
void view_char_by_char(char str[], int n);
int count_spaces(const char str[]);
int vect_count_spaces(const char *s);

int main(int argc, char *argv[], char *envp[])
{
   char str[STR_LEN+1];
   printf("Totale caratteri: %d\n", read_line(str, STR_LEN+1));
   printf("Stringa: %s\n", str);
   view_char_by_char(str, strlen(str));
   printf("Conteggio degli spazi bianchi: %d\n", count_spaces(str) );
   printf("Conteggio degli spazi bianchi (vettori): %d\n", vect_count_spaces(str));

   return(EXIT_SUCCESS);
}

int read_line(char str[], int n)
{
   int ch, i = 0;

   while ( (ch = getchar()) != '\n')
      if (i < n)
      	 str[i++] = ch;

   str[i] = '\0'; /* termina la stringa */

   return i;
}

void view_char_by_char(char str[], int n)
{
   int i;

   for (i=0; i<n; i++)
      printf("[%.2d] %c\n", i, str[i]);
}

int count_spaces(const char str[])
{
   int i, count = 0;

   /* Avrebbe funzionato anche con:
    * i=0; i<n; i++
    * (char str[], int n) 
    * ma decisamente meno elegante
    */
   for (i=0; str[i] != '\0'; i++)
   {
      if (str[i] == ' ')
      	 count++;
   }

   return count;
}

/*
 * La stessa funzione utilizzando i puntatori
 */
int vect_count_spaces(const char *s)
{
   int count = 0;
   /*
    * Alternativa con for
    *
   for (; *s != '\0'; s++)
      if (*s == ' ')
      	 count++;

    * Alternativa con il ciclo while
    *
   while (*s != '\0')
   {
      if (*s == ' ')
      	 count++;
      s++;
   }
    * Alternativa con il ciclo do while
    */

   do 
   {
      if (*s == ' ')
      	 count++;
      s++;
   } while (*s != '\0');

   return count;
}

