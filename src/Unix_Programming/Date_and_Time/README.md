# Date and Time

* [Calendar time; gettimeofday()](#headDT1)

---

## <a name="headDT1"></a>Calendar time; gettimeofday()

__Calendar time__ indica il numero di secondi a partire dalle __00:00 del 01 
gennaio 1970__, Epoch UTC, esso rappresenta il tempo a cui l'orologio del kernel 
fa riferimento, utilizzato generalmente per le date dei file oppure per il 
calcolo di tempi con precisione di 1 secondo.

Il __Calendar time__ viene gestito mediante il tipo di dato `time_t`, che sui
sistemi a 32 bit e' caratterizzato dall'essere un `signed integer`, per cui le
date disponibili vanno dal __`13 dicembre 1901 20:45:52`__ al 
__`19 gennaio 2038 03:14:07`__.

`time_t time(time_t *tm);`
La funzione time() ritorna la data espressa in numero di secondi a partire da 
Epoch, ossia 1970-01-01 00:00:00 +0000 (UTC), e salvata in nella variabile `tm`
di tipo `time_t`. In caso di errore ritorna -1.
