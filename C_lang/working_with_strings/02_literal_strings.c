#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
   // corretto si ma in output  andrebbe anche lo spazio
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
   alloca precisamente la dimensione della stringa n + 1 byte, quel byte
   aggiuntivo è un 'null character' i cui bit sono tutti a impostati zero.
   
   Il compilatore pertanto tratta la stringa letterale come se fosse un
   vettore, gestendola come un 'char *', puntatore a char.
   
   Quando si crea una stringa letterale e' necessario ricordare che il 
   puntatore punta alla prima lettera della stringa:
   char *ptr;
   ptr = "Hello";
   
   ptr punta alla prima lettera della stringa "Hello".
   
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
   ch1 = "abcdefghilmnop"[7]; 
   ch2 = "abcdefghilmnop"[4]; 
   ch3 = "abcdefghilmnop"[9]; 
   ch4 = "abcdefghilmnop"[9]; 
   ch5 = "abcdefghilmnop"[12]; 
   printf("5 - %c%c%c%c%c\n", ch1,ch2,ch3,ch4,ch5);

   return(EXIT_SUCCESS);
}
