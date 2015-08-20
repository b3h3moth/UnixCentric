#include <stdio.h>
#include <stdlib.h>

int my_strlen(const char *s);
char *my_strcat(char *s1, const char *s2);
char *my_strdup(char *s);

int main(int argc, char *argv[], char *envp[])
{
   char str[] = "C Language Programming ";
   char str2[] = "Kernighan and Ritchie";

   printf("len: %d\n", my_strlen(str));
   my_strcat(str, str2);
   printf("%s\n", str);

   return(EXIT_SUCCESS);
}

/* Clacola la lunghezza della stringa */
int my_strlen(const char *s)
{
   const char *p = s;

   while (*s)
      s++;
   /*
    * Gli idiomi sono
    * while(*s)
    *     s++;
    * 
    * e
    *
    * while(*s++)
    * ;
    * La prima punta a null, la seconda punta dopo il carattere null
    */
   return s - p;
}

/* Concatenazione di due stringhe */
char *my_strcat(char *s1, const char *s2)
{
   char *p = s1;

   while (*p)
      p++;
   while ( (*p++ = *s2++) )
      ;
   /*
    * L'dioma per la copia e'
    * *p++ = *s2++
    */
   return s1;
}

/* Copia di una stringa */
char *my_strdup(char *s) 
{
    char *p;

    p = malloc(my_strlen(s) + 1);

    while (s)
        *p++ = *s++;

    return p;
}
