#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>

/* I demoni sono processi che godono di una vita media sensibilimente maggiore 
rispetto agli alri processi, solitamente sono eseguiti subito dopo la fase di 
boostrap e chiusi nella fase di shutdown del sistema, una delle caratteristiche
tipiche di un demone e' l'assenza del terminale di controllo, per cui sono 
eseguiti in background. 

I sistemi operativi UNIX, sia BSD sia SystemV, utilizzano specifici demoni per
la gestione di ogni sorta di caratteristica del sistema.*/

int main(int argc, char *argv[]) {
    return(EXIT_SUCCESS);
}
