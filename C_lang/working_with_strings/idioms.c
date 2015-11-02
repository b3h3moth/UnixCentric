#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(const char *s);
char *my_strcat(char *s1, const char *s2);
void my_strcpy(char *dest, const char *src);

int main(int argc, char *argv[], char *envp[])
{
   char str[] = "C Language Programming ";
   char str2[] = "Kernighan and Ritchie";
   char *str3 = malloc(strlen(str) + 1);

   printf("len: %d\n", my_strlen(str));

   my_strcat(str, str2);
   printf("%s\n", str);
   
   my_strcpy(str3, str);
   printf("%s\n", str3);

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
void my_strcpy(char *dest, const char *src)
{
    while ((*dest++ = *src++) != 0)
        ;
}
