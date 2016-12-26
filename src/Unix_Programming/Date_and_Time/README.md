# The measure of the Time in Unix

* [Calendar time and Process time](#headDT0)
* [Calendar time; time(), gettimeofday()](#headDT1)
* [Converting time_t to string; ctime()](#headDT2)
* [Converting time_t to broken-down time; gmtime(), localtime()](#headDT3)
* [Converting broken-down time to time_t; mktime()](#headDT4)
* [Converting broken-down time to string; asctime(), strftime()](#headDT5)
* [Converting string to broken-down time; strptime()](#headDT6)

---

## <a name="headDT0"></a>Calendar time and Process time

Il __calendar time__ indica il numero di secondi a partire da Epoch, ovvero da
__1970-01-01 00:00:00 +0000 (UTC)__, esso rappresenta il tempo a cui l'orologio
del kernel fa riferimento, utilizzato generalmente per indicare i tempi dei 
file o le date di avvio dei processi con una precisione al secondo.

> Definito anche __tempo d'orologio reale__ oppure __tempo reale__.

Il calendar time viene gestito mediante il tipo di dato `time_t`, che sui
sistemi a 32 bit e' caratterizzato dall'essere un `signed integer`, per cui le
date disponibili vanno dal __`13 dicembre 1901 20:45:52`__ al 
__`19 gennaio 2038 03:14:07`__.

Il __process time__ invece misura il tempo impiegato dal processore nell'
esecuguire il codice di un programma nel contesto di un processo, ossia 
l'ammontare del tempo di CPU usato da un processo. 

> Definito anche __tempo di processore__ oppure __tempo di CPU__.

A differenza del calendar time, il process time utilizza il tipo di dato 
`clock_t`, la cui unita' di misura e' il cosiddetto __clock trick__, ovvero il 
numero di interruzioni del processore causato dal timer di sistema.

## <a name="headDT1"></a>Calendar time; time(), gettimeofday()

`time_t time(time_t *tm);` 

La funzione time() restituisce la data espressa in numero di secondi a partire
da __Epoch__, il risultato e' memorizzato nella  variabile `tm` di tipo 
`time_t`. Ritorna `0` in caso di successo, `-1` altrimenti. Header da includere 
`time.h`.

`int gettimeofday(struct timeval *tv, struct timezone *tz);`

La funzione `gettimeofday()` salva nella struttura `tv` di tipo `timeval, la 
data corrente, a partire da __Epoch__. La struttura `tz` di tipo `timezone` e'
un argomento obsoleto, mantenuto solo per motivi storici, e' sufficiente 
inserire `NULL`. Ritorna `0` in caso di successo, `-1` altrimenti. Header da 
includere `sys/time.h`.

> La struttura `timeval` e' definita in `sys/time.h`

Precisione al microsecondo

```
struct timeval {
     long tv_sec;	// Secondi da 00:00:00, 1 Jan 1970 UTC
     long tv_usec;	// Microsecondi
};
```

> Le funzioni `time()` e `gettimeofday()` restituiscono gli stessi valori, 
> time() infatti ritorna il numero di secondi a partire da __Epoch__, così come
> `gettimeofday()` mediante il campo `tv_sec`. La differenza sostanziale sta
> nella precisione, la prima e' al secondo, la secondo al microsecondo.

## <a name="headDT2"></a>Converting time_t to string; ctime()

Lo scopo della funzione `ctime()` e' di fornire una forma stampabile e quindi
facilmente interpretabile da un essere umano ad un valore di tipo `time_t`.

` char *ctime(const time_t *timep);`

La funzione `ctime()` partendo dal parametro `timep` di tipo `time_t` produce
una stringa con data e tempo corrente, simile al comando `date`. Ritorna il 
puntatore alla stringa in caso di successo, `NULL` in caso di errore.

> La stringa termina con un carattere di `new-line` e un byte `null-terminated`,
> ed ha un peso di 26 byte.

## <a name="headDT3"></a>Converting time_t to broken-down time; gmtime(), localtime()

Le funzioni per la gestione del tempo in __calendar time__ (the Epoch)  non 
sono affatto intuitive qualora si volesse rappresentare una data, pertanto le 
date sono gestite mediante l'implementazione __broken-down time__ (__ora 
legale__), esso infatti altro non e' che la rappresentazione binaria di 
__calendar time__ suddivisa in anni, mesi, giorni, e così via, tale 
suddivisione viene opportunamente implementata nella struttura `tm`  
definita in `time.h`:

```
struct tm {
  int tm_sec;           // Seconds             [0-60] (1 leap second) 
  int tm_min;           // Minutes             [0-59] 
  int tm_hour;          // Hours               [0-23] 
  int tm_mday;          // Day                 [1-31] 
  int tm_mon;           // Month               [0-11] 
  int tm_year;          // Year                1900, ...
  int tm_wday;          // Day of week         [0-6] 
  int tm_yday;          // Days in year        [0-365]	
  int tm_isdst;         // DST (ora legale)    [-101]

  long int tm_gmtoff;   // Seconds east of UTC
  long int tm_gmtoff;   // Seconds east of UTC
};
```

`struct tm *gmtime(const time_t *tp);`

La funzione `gmtime()` converte la variabile `tp` di tipo `time_t`, dal formato 
__calendar time__ al formato __broken-down time__ espresso in UTC. Ritorna un 
puntatore alla struttura `tm` in caso di successo, NULL in caso di errore.

`struct tm *localtime(const time_t *tp);`

La funzione `localtime()` converte la variabile `tp` dal formato 
__calendar time__ al formato __broken-down time__, espresso nell'ora locale del
sistema in uso. Ritorna un puntatore alla struttura `tm` in caso di successo, 
`NULL` in caso di errore

## <a name="headDT4"></a>Converting broken-down time to time_t; mktime()

`time_t mktime(struct tm *timep);`

La funzione `mktime` converte la variabile `timep` di tipo `struct tm` dal
formato __broken-down time__, espresso in orario locale, in un valore di tipo 
`time_t`. Ritorna il numero di secondi da __The Epoch__ corrispondenti al 
valore espresso da `timep` in caso di successo, `-1` altrimenti.

## <a name="headDT5"></a>Converting broken-down time to string; asctime(), strftime()

`char *asctime(const struct tm *tm);`

La funzione `asctime()`, da un parametro __broken-down time__ `tm` produce 
una stringa __null-terminated__, simile al comando `date`. Ritorna un puntatore
alla stringa in caso di successo, `NULL` in caso di errore.

`size_s strftime(char *str, size_t max, const char *format, const struct tm *tm);`

La funzione `strftime()` converte la variabile `tm` di tipo `struct tm` dal
formato __broken-down time__ ad una stringa `str` caratterizzata dal formato
definito in `format` e di dimensioni `max. Ritorna il numero di caratteri 
contenuti in `str`, `0` altrimenti.

> La costante stringa `format` puo' contenere diversi specificatori di 
> conversione - similmente alla la `printf()` -, ciascuno di essi introdotto 
> dal carattere `%`.

La funzione `strftime()`, a differenza di `ctime()` e `asctime()`, non include 
il carattere new-line alla fine della stringa, a meno che non sia espressamente 
indicato da `format`.

## <a name="headDT6"></a>Converting string to broken-down time; strptime()

`char *strptime(const char *str, const char *format, struct tm *tm);`

La funzione strptime() si occupa di convertire la stringa `str` in
__broken-down time__ nella struttura `tm`, secondo il formato indicato da
`format`.
