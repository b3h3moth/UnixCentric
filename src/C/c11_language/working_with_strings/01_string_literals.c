#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[], char *envp[]) {
    /* Una stringa letterale (literal string) e' una sequenza di caratteri
    racchiusa tra doppi apici */
   
   // L'istruzione e' corretta ma in output andrebbero anche gli spazi
   printf("1 - Take a walk \
   	 on the \
	 wild side");

   // In tal modo lo spazio non sara' visualizzato in output
   printf("\n2 - take a walk \
on the \
wild side");

  // Con i doppi apici si puo' gestire con maggior flessibilita'
   printf("\n3 - take a walk "
   	 "on the "
	 "wild side\n");

   /* Allorquando il compilatore deve allocare spazio per una stringa letterale
   alloca precisamente la dimensione della stringa + 1 byte, quel byte
   aggiuntivo è il 'null character' - caratttere di terminazione di stringa - 
   i cui 8 bit sono tutti a impostati zero.
   
   Il compilatore pertanto tratta la stringa letterale come se fosse un
   vettore, gestendola come un 'char *', puntatore a char.
   
   Quando si crea una stringa letterale e' necessario ricordare che il 
   puntatore punta alla locazione in cui e' contenuto il primo carattere della 
   stringa.
   
   E' possibile pertanto usare una stringa letterale ovunque il C ammetta un
   puntatore a char. */

   char *name;
   name = "Lou Reed";
   printf("4 - %s\n", name);
   
   /* Poichè i puntatori possono essere indicizzati, altrettanto si puo' fare
   con le stringhe letterali.
  
   Nel caso specifico, grazie all'operatore di subscript si vanno ad
   estrapolare caratteri */

   char ch1, ch2, ch3, ch4, ch5;

   ch1 = "abcdefghijklmnopqrstuvwxyz"[7];   // Si estrapola il carattere 'h'
   ch2 = "abcdefghijklmnopqrstuvwxyz"[4];   // Si estrapola il caratteri 'e'
   ch3 = "abcdefghijklmnopqrstuvwxyz"[11];  // Si estrapola il caratteri 'l'
   ch4 = "abcdefghijklmnopqrstuvwxyz"[11];  // Si estrapola il caratteri 'l'
   ch5 = "abcdefghijklmnopqrstuvwxyz"[14];  // Si estrapola il caratteri 'o'
   
   printf("5 - %c%c%c%c%c\n", ch1,ch2,ch3,ch4,ch5);

   // Stessa operazione, utilizzando una stringa
   char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

   char ch6,ch7,ch8,ch9,ch10;
   
   ch6  = alphabet[7];  // Si estrapola il carattere 'h'
   ch7  = alphabet[4];  // Si estrapola il caratteri 'e'
   ch8  = alphabet[11]; // Si estrapola il caratteri 'l'
   ch9  = alphabet[11]; // Si estrapola il caratteri 'l'
   ch10 = alphabet[14]; // Si estrapola il caratteri 'o'
   
   printf("6 - %c%c%c%c%c\n", ch6,ch7,ch8,ch9,ch10);

   return(EXIT_SUCCESS);
}
