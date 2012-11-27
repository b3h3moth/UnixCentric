#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_LEN 30

/*
 * Le struture nascono per contenere raccolte di dati eterogenei concettualmente
 * collegati; 
 */

struct persona
{
   int eta;
   char nome[STR_LEN];
} var1 = {37, "luca"},
  var2 = {20, "pippo"};

/* 
 * Ho appena creato due variabili struttura, e contestualmente inizializzate
 */

/*
 * Il tag di struttura nasce per identificare il tipo della struttura, possono
 * essere copiati o equiparati solo strutture col medesimo tag di strutura
 * struct structTag
 * {
 * ...
 * };
 */

/* 
 * Posso utilizzare una struttura sia come argomento sia come valore restituito
 * da una funzione.
 */
struct persona creaPersona(int eta, const char *nome);
void printPersona(struct persona s);

int main(int argc, char *argv[])
{
   struct persona test;
   test = creaPersona(40, "suriano");
   printPersona(test);
   printPersona(var1);
   printPersona(var2);

   /*
    * Da notare che le due funzioni causano un grosso overhead, poiche' vengono
    * copiate membro per membro le strutture stesse, per cui sarebbe meglio
    * utilizzare i puntatori
    */

   return(EXIT_SUCCESS);
}

struct persona creaPersona(int eta, const char *nome)
{
   struct persona p;
   p.eta = eta;
   strcpy(p.nome, nome);

   return p;
}

void printPersona(struct persona s)
{
   printf("eta %d\nnome %s\n", s.eta, s.nome);
}
