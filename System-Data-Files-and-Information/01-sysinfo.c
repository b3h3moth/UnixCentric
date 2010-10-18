#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

#define MB (1024 * 1024)

int main() {

   struct sysinfo info;
   sysinfo(&info);

   printf("    Uptime %6ld\n", info.uptime);
   printf(" Total RAM %6d MB\n", info.totalram / MB);
   printf("  Free RAM %6d MB\n", info.freeram / MB);
   printf("Share DRAM %6ld MB\n", info.sharedram / MB);
   printf("Buffer RAM %6ld MB\n", info.bufferram / MB);
   printf("Total SWAP %6ld MB\n", info.totalswap / MB);
   printf(" Free SWAP %6ld MB\n", info.freeswap / MB );

   return(EXIT_SUCCESS);
}

