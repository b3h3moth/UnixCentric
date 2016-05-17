Una funzione in grado di:
- accettare un'altra funzione come parametro;
- restituire una funzione,
e' chiamata 'Higher Order Function' (funzione di ordine superiore).

Sono estremamente utili per implementare funzioni generiche, così come per la
scrittura di funzioni cosiddette di 'Callback' e/o di 'Listener'.

La callback in particolare e' solitamente una funzione passata come parametro 
ad un'altra funzione, in tal modo puo' svolgere specifici compiti del tutto 
nascosti alla funzione chiamante - information hiding. Vi e' inoltre un altro
tipo di funzione callback, ossia quella richiamata dal Sistema Operativo per
la gestione di eventi - ad esempio premere un bottone del mouse causera' il 
lancio di una callback.
