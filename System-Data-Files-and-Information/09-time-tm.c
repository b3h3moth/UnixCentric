#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char **argv, char **envp) {
   time_t data_corrente;
   struct tm *componenti_data;

   time(&data_corrente);
   componenti_data = localtime(&data_corrente);

   printf("%02d/%02d/%04d  %02d:%02d:%02d\n",
   	 componenti_data->tm_mon +1,
   	 componenti_data->tm_mday,
   	 componenti_data->tm_year + 1900,
	 componenti_data->tm_hour,
	 componenti_data->tm_min,
	 componenti_data->tm_sec);

   return(EXIT_SUCCESS);
}
