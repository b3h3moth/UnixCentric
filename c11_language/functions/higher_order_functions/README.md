Una funzione in grado di:
- accettare un'altra funzione come parametro;
- restituire una funzione,
e' chiamata 'Higher Order Function' (funzione di ordine superiore).

Sono estremamente utili per implementare funzioni generiche, così come per la
scrittura di funzioni cosiddette di 'Callback' e/o di 'Listener'.

La callback in particolare e' solitamente una funzione passata come parametro 
ad un'altra funzione, in tal modo puo' svolgere specifici compiti del tutto 
nascosti alla funzione chiamante - information hiding. Vi e' inoltre un altro
tipo di funzione callback, ovvero quella richiamata dal Sistema Operativo per
la gestione di eventi - ad esempio premere un bottone del mouse causera' il 
lancio di una callback.

In definitiva le callback sono decisamente efficaci per rendere il codice piu'
generale possibile, disaccoppiando la funzione chiamante dalla funzione 
chiamata, così come sono utili nella implementazione di librerie.

In C una funzione di callback e' chiamata mediante un puntatore un funzione,
nello specifico si supponga di avere una funzione 'A' a cui venga passato come
argomento il puntatore di un'altra funzione *B, ossia l'indirizzo; allorquando
la funzione A utilizza il puntatore a funzione *B, viene in quel frangente
attivata una callback.
