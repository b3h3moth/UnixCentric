# Date and Time

* [Calendar time; time(), gettimeofday()](#headDT1)

---

## <a name="headDT1"></a>Calendar time; time(), gettimeofday()

__Calendar time__ indica il numero di secondi a partire da Epoch, 
__1970-01-01 00:00:00 +0000 (UTC)__, esso rappresenta il tempo a cui l'orologio
del kernel fa riferimento, utilizzato generalmente per le date dei file oppure 
per il calcolo dei tempi con precisione al secondo.

Il __Calendar time__ viene gestito mediante il tipo di dato `time_t`, che sui
sistemi a 32 bit e' caratterizzato dall'essere un `signed integer`, per cui le
date disponibili vanno dal __`13 dicembre 1901 20:45:52`__ al 
__`19 gennaio 2038 03:14:07`__.

`time_t time(time_t *tm);` 

La funzione time() restituisce la data espressa in numero di secondi a partire 
da __Epoch__, ossia dal __1970-01-01 00:00:00 +0000 (UTC)__, e salvata in nella 
variabile `tm` di tipo `time_t`. 
Ritorna `0` in caso di successo, `-1`
altrimenti. Header da includere `time.h`.

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
La funzione 'gettimeofday()` puo' essere indicata per verificare i tempi di 
reazione di un programma o di un pezzo di codice e, con opportuni accorgimenti, 
anche per stampare la data corrente.
