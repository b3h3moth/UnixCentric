#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 32

int main(int argc, char *argv[], char *envp[])
{
   /*
    * Nel C le stringhe vengono trattate come vettori e quindi subiscono le
    * medesime restrizioni di questi ultimi, per cui non possono essere ne'
    * copiate ne' confrontate mediante operatori
    */

   /* COPIARE UNA STRINGA 
    * strcpy
    */
   char str1[] = "Hacking is not a crime";
   char str2[STR_LEN];
   strcpy(str2, str1);
   printf("str1 %s - strlen(str1): %d\nstr2 %s - strlen(str2): %d\n", str1, strlen(str1), str2, strlen(str2) );

   /* 
    * strncpy
    */
   char str3[STR_LEN];
   strncpy(str3, str2, sizeof(str3) -1);
   str3[sizeof(str3)-1] = '\0';
   printf("str3 %s - strlen(str3) %d\n", str3, strlen(str3));

   /* CONCATENAZIONE
    * strcat
    */
   char strb[] = "is not ";
   char strc[] = "a crime";
   char str5[] ="hacking ";
   strcat(str5, strb);
   strcat(str5, strc);
   printf("str5 %s\n", str5);

   /*
    * strncat
    */
   strncat(strb, strc, strlen(strc));
   printf("strb %s\n", strb);

   /* COMPARAZIONE
    * strcmp
    * strcmp(s1, s2)
    * restituisce un valore minore, uguale o maggiore di 0, a seconda che s1 sia
    * appunto minore, uguale o maggiore di s2
    */

   if ( strcmp(strb,strc) > 0)
      printf(" %d < %d\n", strlen(strc), strlen(strb));
   if ( strcmp(strc,strb) < 0)
      printf(" %d > %d\n", strlen(strb), strlen(strc));
   if ( strcmp(strb,strb) == 0)
      printf(" %d == %d\n", strlen(strb), strlen(strb));





   return(EXIT_SUCCESS);
}
