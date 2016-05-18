La callback function e' solitamente una funzione passata come parametro 
ad un'altra funzione, in tal modo puo' svolgere specifici compiti del tutto 
nascosti alla funzione chiamante - information hiding. Vi e' inoltre un altro
tipo di funzione callback, ovvero quella richiamata dal Sistema Operativo per
la gestione di eventi - ad esempio il semplice 'click' del mouse lancia una
callback.

In definitiva le callback sono decisamente efficaci per rendere il codice piu'
generale possibile, disaccoppiando la funzione chiamante dalla funzione 
chiamata, così come sono utili nella implementazione di librerie.

In C una funzione di callback e' invocata mediante un puntatore un funzione.
Nello specifico, si supponga di avere una funzione 'A' a cui venga passato come
argomento il puntatore di un'altra funzione *B - in pratica l'indirizzo;
allorquando la funzione A utilizza il puntatore a funzione *B, viene in quel 
frangente attivata una callback
