#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 8
#define F_STR 11

int main(int argc, char *argv[], char *envp[])
{
	int i;

	/* Il linguaggio di programmazione C-ANSI non contiene tra i tipi di dato 
	predefinti il tipo stringa, e' cura del programmatore realizzarlo mediante
	vettori unidimensionali a cui si aggiunge un carattere finale indicante la
	terminazione della stringa, esso e' \0 (null character, null terminator).
	
	Stringa in C: Un vettore di caratteri piu' un null character finale. */
   	
	char first_string[F_STR+1] = "Hello World";
	
	/* Stampa 'char by char' della stringa */
	for (i=0; i<F_STR; i++) {
		printf("%2d - %c\n", i, first_string[i]);
	}
	
	/* La lunghezza della stringa first_string e' stata impostata a F_STR+1,
	poiche', essendo un vettore, l'indice inizia 0, come si evince dal
	seguente schema:
	  
	  0   1   2   3   4   5   6   7   8   9  10  11
	 'h' 'e' 'l' 'l' 'o' ' ' 'w' 'o' 'r' 'l' 'd' '\0'
	
	Buona abitudine: Allorquando si lavora con le stringhe, verificare sempre
	la lunghezza calcolando anche lo spazio per il null-character, inoltre,
	la lunghezza della stringa stessa, quando possibile, sarebbe opportuno
	definirla mediante una costante simbolica, utilizzando la #define.
	
	INIZIALIZZAZIONE
    ----------------
    Una variabile stringa puà essere inizializzata al momento della
    dichiarazione; l'istruzione di seguito sembrerebbe una stringa letterale,
	ma non lo e', poiche' il C la vede come un'abbreviazione dell'
    inizializzazione di un vettore */
   	
	char date[MAX_STR] = "June 14"; 
	
	/* Si può anche omettere la lunghezza, che sarà calcolata dal compilatore */
	
	char new_date[] ="March 31";
	printf("len date: %d\nlen new_date: %d\n", strlen(date), strlen(new_date));
	
	/* VETTORI DI CARATTERI E PUNTATORI A CONFRONTO
       --------------------------------------------
    Il primo tratta vett come un vettore, il secondo tratta ptr come un
    puntatore, per cui in qualsiasi funzione le potremmo utilizattzare entrambe,
    tuttavia questo non vuol dire che siano intercambiabili.
    
    In vett ogni carattere può essere modificato come in un vettore, poiche'
    lo e'; nel secondo caso invece, si tratta di una stringa letterale, 
	pertanto i caratteri non possono essere modificati, tuttavia nel corso del
	programma ptr puo' esser fatto puntare ad altre zone di memoria.
    
    char *p; dichiara un puntatore a char, il compilatore alloca lo spazio per
	contenere un puntatore a char e non per una stringa, e del resto come 
	potrebbe? E' possibile tuttavia far sì che il puntatore p punti ad una 
    stringa */
	
	char vett[] = "Carl Mark";
	char *ptr = "Unknow";
    ptr = vett;

    vett[8] = 'x'; // Correzione della stringa, rimpiazzando il carattere

    printf("%s\n", vett);
	printf("%s\n", ptr);
   

   return(EXIT_SUCCESS);
}
