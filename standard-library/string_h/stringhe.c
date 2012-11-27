#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv, char **envp) {
   char str1[] = "Learning C on GNU/Linux System";
   char str2[] = "lEARniNg c ON gNu/liNux sYsTeM";
   int size1 = strlen(str1);
   int size2 = strlen(str2);
   /*
	* La funzione strcasecmp(str1, str2) confronta la stringa 'str1' con la
	* stringa str2. Non e' case sensitive.
	*
	* Restituisce un intero:
	* <  0  se 'str1' e' minore di   'str2'
	* == 0  se 'str1' e' uguale a    'str2'
	* >  0  se 'str1' e' maggiore di 'str2'
	*
	*/
   if (strcasecmp(str1, str2) < 0)
   	   printf("%s (%d) < %s (%d)\n", str1, size2, str2, size2);
   if (strcasecmp(str1, str2) > 0)
   	   printf("%s (%d) > %s (%d)\n", str1, size2, str2, size2);
   else
   	   printf("%s (%d) == %s (%d)\n", str1, size2, str2, size2);


   /*
	* La funzione strpbrk(str, s) cerca la prima occorrenza della stringa 's' in 
	* 'string', carattere per carattere. Non e' case sensitive. E' sufficiente
	* anche un solo carattere.
	*
	* Restituisce:
	* In caso di esito positivo un puntatore alla prima occorrenza di 'str'
	* In caso di esito negativo, NULL
	*
	*/
   if (strpbrk(str1, "hello") == NULL)
   	   printf("Occorrenza non trovata\n");
    else
   	   printf("Occorrenza trovata\n");

   if (strpbrk(str2, "wjd") == NULL)
   	   printf("Occorrenza non trovata\n");
    else
   	   printf("Occorrenza trovata\n");


   return(EXIT_SUCCESS);
}
