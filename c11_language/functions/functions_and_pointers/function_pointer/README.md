### Function Pointers

Un puntatore a funzione e' un puntatore che immagazzina l'indirizzo di una funzione,
ad esempio `int (*fp)();`, `fp` e' un puntatore a funzione che restituisce un
intero e non ha argomenti.

> **Warning**: le parentesi sono fondamentali altrimenti diventerebbe `int *fp();` 
ovvero la funzione ``fp()`` che restituisce un puntatore ad intero.

Altre dichiarazioni possono essere:

* `void (*fp)(int, int);`, `fp` e' un puntatore a funzione con due parametri
interi, e ritorna void;
* `int* (*fp)(char*);`, `fp` e' un puntatore a funzione con un parametro puntatore a char,
e ritorna un puntatore a int. E cosi' via.

> **Warning**: e' necessario porre particolare attenzione ai parametri del puntatore
a funzione, poiche' il C non prevede la verifica degli stessi nel caso specifico.


