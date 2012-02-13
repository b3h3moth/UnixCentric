#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

/*
Nota: Le funzioni per la gestione del tempo in "calendar time (epoch)"  non sono
affatto intuitive qualora si volesse rappresentare una data.

Le date sono gestite mediante l'implementazione "broken-down time", che consente
di suddividere i tempi di "calendar time", in ore, minuti, secondi, etc..., tale
suddivisione viene opportunamente implementata nella struttura 'tm' definita in
<time.h>:

struct tm
{
  int tm_sec;			 Seconds.	[0-60] (1 leap second) 
  int tm_min;			 Minutes.	[0-59] 
  int tm_hour;			 Hours.		[0-23] 
  int tm_mday;			 Day.		[1-31] 
  int tm_mon;			 Month.		[0-11] 
  int tm_year;			 Year		- 1900.  
  int tm_wday;			 Day of week.	[0-6] 
  int tm_yday;			 Days in year.	[0-365]	
  int tm_isdst;			 DST.		[-101]

  long int tm_gmtoff;		 Seconds east of UTC.  
  long int __tm_gmtoff;		 Seconds east of UTC.  
};

HEADER    : <time.h>
PROTOTYPE : struct tm *localtime(cons time_t *tp);
SEMANTICS : La funzione local_time converte la variabile 'tp' dal formato 
            calendar time al formato broken-down time, espresso nell'ora locale
RETURNS   : Un puntatore alla struttura 'tm' in caso di successo, NULL in caso
            di errore
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
   time_t t;
   struct tm *local_time;
  
   if ((t = time(NULL)) < 0) {
      fprintf(stderr,"Err.(%s) getting time\n", strerror(errno));
      exit(EXIT_FAILURE);
   }
   
   /* Si ricorda che la conversione avviene da calendar time a broken-down time
   espresso nell'ora locale */
   local_time = localtime(&t);
   
   printf("  Anno: %d\n  Mese: %d\nGiorno: %d\n   Ora: %d:%d:%d\n",
            local_time->tm_year, 
	    local_time->tm_mon, 
	    local_time->tm_mday,
            local_time->tm_hour, 
	    local_time->tm_min, 
	    local_time->tm_sec);

   return(EXIT_SUCCESS);
}
