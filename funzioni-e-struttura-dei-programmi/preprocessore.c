#include <stdio.h>
#include <stdlib.h>

 /* 
  * MACRO SEMPLICI
  */
#define STR_LEN 32
#define MEM_ERR "Errore nell'utilizzo della stringa"
#define CR	'\0'
#define BEGIN	{
#define END 	}
#define ETC 	"Etc...."

 /* 
  * MACRO PARAMETRICHE
  */
#define MAX(x,y)	((x)>(y)?(x):(y))
#define PRINT_INT(n)	printf("%d\n", n);

int main(int argc, char *argv[])
{
   /*
    * Il comportamento del preprocessore è controllato dalle direttive di
    * preprocessamento; riguarda i comandi che iniziano con #
    *
    * E' utile pensare al preprocessore come un componente separato rispetto
    * alla compilazione
    *
    * Per verificare in output le direttive si può immettere l'opzione
    * gcc -E al compilatore
    */

   BEGIN
   	puts("ciao");
   	puts(MEM_ERR);
	puts(ETC);
   END

   printf("Il massimo è %d\n", MAX(30,20));
   PRINT_INT(20/10);

   /*
    * Macro predefinite
    * ce ne sono altre aggiunte dal C99
    */
   printf("Esempi sul preprocessore (c) 2010 luca suriano\n");
   printf("Compilato (%s) at (%s)\n", __DATE__, __TIME__);
   printf("Line (%d) file (%s)\n", __LINE__, __FILE__);

   return(EXIT_SUCCESS);
}
