# The measure of the Time in Unix

* [Calendar time and Process time](#headDT0)
* [Calendar time; time(), gettimeofday()](#headDT1)

---

## <a name="headDT0"></a>Calendar time and Process time]

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
l'ammonare del tempo di CPU usato da un processo. 

> Definito anche __tempo di processore__ oppure __tempo di CPU__.

A differenza del calendar time utilizza il tipo di dato `clock_t` e l'unita' di 
misura e' il cosiddetto __clock trick__, ovvero il numero di interruzioni del
processore causato dal timer di sistema.

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
