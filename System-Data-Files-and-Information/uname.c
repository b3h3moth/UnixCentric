#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>

int main() {
   struct utsname mysystem;
 

   if ( uname(&mysystem) != 0) {
      fprintf(stderr, "Spiacente, impossibile ottenere informazioni.\n");
      exit(EXIT_FAILURE);
   }

   printf("--------------------------\n");
   printf(" INFORMAZIONI SUL SISTEMA\n");
   printf("--------------------------\n");
   printf("           Il sistema operativo: %s\n", mysystem.sysname);
   printf("         L'hostname del network: %s\n", mysystem.nodename);
   printf("        Release (Kernel) in uso: %s\n", mysystem.release);
   printf("Versione corrente della release: %s\n", mysystem.version);
   printf("        Hardware (Architettura): %s\n", mysystem.machine);

   return(EXIT_SUCCESS);
}
