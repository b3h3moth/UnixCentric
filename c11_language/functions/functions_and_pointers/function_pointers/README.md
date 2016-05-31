### Function Pointers

Un puntatore a funzione e' un puntatore che immagazzina l'indirizzo di una funzione,
ad esempio `int (*pf)();` pf e' un puntatore a funzione che restituisce un
intero e non ha argomenti

> Warning: le parentesi sono fondamentali altrimenti diventerebbe `int *pf();` 
ovvero la funzione ``pf()`` che restituisce un puntatore ad intero.
