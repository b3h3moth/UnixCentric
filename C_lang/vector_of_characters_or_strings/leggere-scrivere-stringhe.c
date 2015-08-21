#include <stdio.h>
#include <stdlib.h>

#define STR_LEN 64

int main(int argc, char *argv[], char *envp[])
{
   /*
    * Per scrivere una stringa si può utilizzare la funzione di conversione %s,
    * e questo si sa, una tecnica interessante è che si può scrivere solo una
    * parte della stringa stessa utilizzando %.ps, dove p è il numero di
    * caratteri da scrivere
    */
   char str[] = "hacking on planet hearth";
   printf("%.7s\n", str);
   
   /*
    * %m.ps
    * i primi p caratteri della stringa visualizzati in un campo di dimensione
    * m, allineata a destra se i caratteri sono minori di m.
    *
    * Sempre per ciò che concerne l'allineamento:
    * ("[%.2d]")
    * [00]
    * [01]
    * [02]
    * ....
    * ("%2d")
    * [ 0]
    * [ 1]
    * [ 2]
    * ....
    * ("%2.d")
    * [  ]
    * [ 1]
    * [ 2]
    * ....
    */
   printf("%10.7s %10.7s %10.7s\n", str, str, str);

   /*
    * Una stringa può essere scritta in output anche con puts();
    */
   puts(str);
   
   /*
    * La specifica di conversione %s consente alla scanf di leggere una stringa
    * e di memorizzarla all'interno di un vettore di caratteri.
    *
    * Attenzione poichè la scanf non legge gli spazi bianchi, nel senso che
    * appena ne vede uno lo considera come terminatore di fine tringa spezzando
    * la stringa stessa, stesso discorso per gli altri caratteri di tabulazione;
    * quindi la scanf non è adatta per leggere righe intere composte da
    * svariate parole.
    *
    * Meglio la gets() per leggere righe intere, o ancor meglio fgets();
    * la gets() legge fino a quando incontra il carattere di newline '\n' nel 
    * cammino, scartandolo peraltro e inserendo al suo posto il carattere
    * nullo '\0'.
    */
   char str1[STR_LEN+1];
   char str2[STR_LEN+1];
   char str3[STR_LEN+1];
   char str4[11];
   printf("Inserisci la prima stringa: ");
   scanf("%s", str1);
   printf("str1 ----------> %s\n", str1);

   /* da notare che se inserisco diverse parole nella str1, la scanf la spezza,
    * per cui il resto della stringa andrà direttamente a riempire la gets(),
    * comportamento interessante ma pericoloso.
    */
   printf("Inserisci la seconda stringa: ");
   gets(str2);
   printf("str2 ----------> %s\n", str2);


   /* la fgets(char *c, int size, FILE *stream);
    * è molto più sicura e pratica.
    */
   fgets(str3, STR_LEN+1, stdin);
   printf("str3 ----------> %s\n", str3);

   /* Il problema della scanf e della gets è che allorquando inseriscono i
    * caratteri nel vettore, continuano anche oltre il limite eventuale della
    * stringa, andando a scivere in zone di memorie che potrebbero causare
    * problemi; la scanf pertanto può essere resa sicura sicura inserendo il
    * numero di caratteri da inserire:
    * %ns dove n è il numero di caratteri da inserire
    */
   printf("Inserisci str4: ");
   scanf("%10s", str4);
   printf("str4 ----------> %s\n", str4);


   return(EXIT_SUCCESS);
}
