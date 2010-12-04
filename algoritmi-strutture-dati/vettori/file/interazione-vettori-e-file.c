#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_ARR_SIZE 20

typedef enum{TRUE, FALSE} bool;
typedef int TipoElemVett;
typedef TipoElemVett TipoVettore[MAX_ARR_SIZE];

int LeggiVettore(char *f_input, TipoVettore A);
void ScriviVettore(char *file_input, char *file_output, TipoVettore A, int n);
bool Ricerca(TipoVettore A, int elem, int n);
bool RicercaBinariaR(int inf, int sup, TipoVettore A, TipoElemVett elem);
void CreaFile(void);

int main(int argc, char **argv, char **envp) {
   TipoVettore vettore;
   int n_elementi_letti;
   char *file_input = "inputFile.txt";
   char *file_output = "outputFile.txt";
   int n_elementi_ricerca, cerca = 15;

   CreaFile();

   n_elementi_letti = LeggiVettore(file_input, vettore);

   printf("Il vettore letto ha '%d' elementi.\n", n_elementi_letti);
   
   ScriviVettore(file_input, file_output, vettore, n_elementi_letti);
   
   n_elementi_ricerca = Ricerca(vettore, cerca, n_elementi_letti);

   printf("\nRisultato ricerca = '%d'\n", n_elementi_ricerca);
   
   printf("Risultato %d->'%d'\n", cerca, RicercaBinariaR(0, n_elementi_letti, vettore, cerca));

   return(EXIT_SUCCESS);
}

/* Restituisce il numero degli elementi letti dal file */
int LeggiVettore(char *f_input, TipoVettore A) {
   int i = 0;
   FILE *datafile;

   if ((datafile = fopen(f_input, "r")) == NULL) {
   	   fprintf(stderr, "Errore: '%s' file in lettura\n", f_input);
	   exit(0);
   } else {
   	   while (fscanf(datafile, "%d", &A[i]) != EOF) {
	   	   printf("Vettore letto dal file vettore[%d] = %d\n", i, A[i]);
		   i++;
	   }
	   fclose(datafile);
   }
   
   return i;
}

/* Riceve n elementi del file file_input e li scrive nel file file_output */
void ScriviVettore(char *file_input, char *file_output, TipoVettore A, int n) {
	int i;
	FILE *datafiler;
	FILE *datafilew;
	
	if ( ((datafiler = fopen(file_input, "r")) == NULL) || ((datafilew = fopen(file_output,"w")) == NULL) ) {
		fprintf(stderr, "Errore\n");
		exit(0);
	} else {
		for (i=0; i<n; i++) {
			printf("\n%d", A[i]);
			fprintf(datafilew, "%d\n", A[i]);
		}
		fclose(datafiler);
		fclose(datafilew);
	}
}

/* Ricerca sequenziale di un elemento all'interno del vettore, non appena lo
 * individua si ferma; restitusce TRUE se trova l'elemento, FALSE altrimenti */
bool Ricerca(TipoVettore A, int elem, int n) {
   int i = 0;
   bool trovato = FALSE;

   for (i=0; i<n; i++) {
	 printf("\nvettore[%d] = %d", i, A[i]);
      if (A[i] == elem) {
      	 trovato = TRUE;
		 printf(" <--- trovato --->");
      }
   }
   
   return trovato;
}

/* Ricerca binaria ricorsiva.
 * Cerca elem nel vettore, tra gli elementi inf sup */
bool RicercaBinariaR(int inf, int sup, TipoVettore A, TipoElemVett elem) {
   int med;
   bool trovato;

   if (inf > sup)
   	   trovato = FALSE;
   else {
   	   med = (inf + sup) / 2;
	   if(elem == A[med]) {
	   	   trovato = TRUE;
	   } else {
	   	   if (elem < A[med])
		   	   trovato = RicercaBinariaR(inf, med-1, A, elem);
		   else
		   	   trovato = RicercaBinariaR(med+1, sup, A, elem);
	   }
   }
   
   return trovato;
}

/* Crea il file iniziale e lo riempie con degli interi */
void CreaFile(void)
{
	FILE *fp;
	int vett[MAX_ARR_SIZE];
	int i;

	if ((fp = fopen("inputFile.txt", "w+")) == NULL) {
		fprintf(stderr, "%s- creazione file di input", (char *)strerror(errno));
		exit(EXIT_FAILURE);
	}

	for (i=0; i<MAX_ARR_SIZE; i++) {
		vett[i] = MAX_ARR_SIZE*(1.0*rand()/RAND_MAX);
		fprintf(fp, "%d\n", vett[i]);
	}

	fclose(fp);
}
