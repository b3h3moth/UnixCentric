# Process Credentials

Un processo e' un'entita' astratta definita dal kernel, a cui sono allocate 
delle risorse del sistema al fine di eseguire un programma.

A ciascun nuovo processo e' assegnato un intero di 16 bit con segno e 
progressivo che lo identifica univocamente rispetto agli altri processi, il 
"Process ID" (PID); essendo peraltro un intero a 16 bit puo' raggiungere al 
massimo il valore di 32768, dopodiche' eventualmente, dopo la terminazione di un
processo puo' anche  essere riutilizzato, ma solo dopo uno specifico lasso di 
tempo.

> Il primo bit e' riservato al segno, per cui il valore e' 32768 (2^15)

PID 0, solitamente e' assegnato allo schedulatore dei processi, detto "swapper";
PID 1, e' assegnato ad "init", invocato dal kernel alla fine della procedura di 
"bootstrap", per cui e' il primo processo ad essere eseguito, e si occupa di 
far partire tutti gli altri processi. 

Il processo "init" non muore mai e sebbene venga eseguito con privilegi da 
"superuser" e' un normale processo utente e non un processo kernel.

## Function prototypes

Vi sono diverse funzioni che consentono l'identificazione dei processi:

`pid_t getpid(void);`

La funzione getpid() ritorna il PID del processo chiamante; nessun errore.

`pid_t getppid(void);`

La funzione getppid() ritorna il parent PID del processo chiamante; nessun 
errore.

`uid_t getuid(void);`

La funzione getuid() ritorna il real user ID del processo chiamante; nessun 
errore.

`uid_t geteuid(void);`

La funzione geteuid() ritorna l'effective user ID del processo chiamante; 
nessun errore.

`gid_g getgid(void);`

La funzione getgid() ritorna il real group ID del processo chiamante; nessun 
errore.

`gid_t getegid(void);`

La funzione getegid(void) ritorna l'effective real group ID del processo 
chiamante; nessun errore.

Ciascuna di esse pertarno ritorna il numero identificativo richiesto.

> Nota: Le due funzioni getpid() e getppid() servono per acquisire il PID del 
> current process e il PID del parent process, ossia il PPID, questo perche' 
> tutti i processi conservano, oltre al proprio PID anche il PID del genitore.

## Accesso control

Un sistema unix-like e' basato su fondamenti di sicurezza imprescindibili,
anzitutto vi e' una netta differenziazione tra il superuser (root o 
amministratore) che gode del pieno controllo del sistema e gli utenti che 
inevitabilmente hanno diverse restrizioni, vi e' inoltre il concetto di "utente"
e di "gruppo".

Il sistema associa un identificatore univoco ad ogni utente e gruppo, 
lo user-ID (UID) e il group-ID (GID) rispettivamente, essi servono al kernel per
identificare uno specifico utente o un gruppo di utenti, e grazie ad essi 
verificare se godono delle autorizzazioni necessarie per eseguire i compiti 
richiesti.

Poiche' tutte le operazioni del sistema sono eseguite da uno o piu' processi,
risulta ovvio che per poter fornire un controllo su tali operazioni e' 
necessario essere a conoscenza dell'utente che ha lanciato il programma, ragion
per cui anche un processo deve avere i propri UID e GID.

I sistemi unix-like forniscono i seguenti gruppi di identificatori:

- Real      , real user-ID (RUID) / real group-ID (RGID)
              Sono impostati al login al valore dell'utente e del gruppo con cui
	      si accede al sistema. Solitamente non vengono cambiati, potrebbe
	      farlo tuttavia solo un processo che gode dei privilegi di 
	      superuser. 
	      Identificano l'utente e il gruppo a cui il processo appartiene.

- Effective , effective user-ID (EUID) / effective group-ID (EGID)
              Ai due si aggiunge anche l'effective GID di altri eventuali gruppi
	      di appartenenza.
	      Sono utilizzati nelle verifiche dei permessi del processo e per il
	      controllo d'accesso ai file, in pratica identificano l'utente e
	      il gruppo usati per decidere se un processo possa o meno accedere
	      ad una risorsa.

              Nota: solitamente real ed effective sono identici, tranne nel caso
	      in cui il programma in esecuzione avesse i bit 'suid' o 'sgid' 
	      impostati, in tal caso gli effective saranno impostati al nome 
	      dell'utente e del gruppo proprietari del file. Questo e' il caso 
	      in cui un programma puo' essere eseguito da un utente con 
	      privilegi di superuser (o altri). Puo' rappresentare un serio 
	      problema di sicurezza.
              
- Saved     , saved user-ID / saved group-ID 
              Solo se _POSIX_SAVED_IDS e' impostato.
	      Sono copie dell'effective User-ID ed effettive group-ID del 
	      processo padre - impostati da una delle funzioni exec all'avvio
	      del processo - cosi che sia possibile ripristinarli.

I sistemi con kernel Linux dispongono anche dell'identificatore filesystem, una
estensione di sicurezza NFS.

> `man 7 credentials`

## setuid(), setgid()

Quando un programma necessita di privilegi addizionali oppure ottenere l'accesso
a specifiche risorse per le quali non si hanno i dovuti privilegi, si devono 
modificare l'user-ID (UID) e il group-ID (GID); naturalmente questa e' la strada
da seguire anche qualora i privilegi dovessero essere ridotti.

> Attenzione; si assume che la costante _POSIX_SAVED_IDS sia settata, altrimenti
> i riferimenti a saved UID non saranno disponibili, per verificarlo e' possibile
> invocare la funzione sysconf() con l'argomento _SC_SAVED_IDS a run-time oppure a
> compile-time con _POSIX_SAVED_IDS.

Le applicazioni dovrebbero essere sviluppate seguendo il modello del 
"least privilege", ossia il principio del privilegio minimo; in informatica e 
in altri campi, il principio del privilegio minimo richiede che in un 
particolare livello di astrazione di un ambiente di calcolo ogni modulo 
computazionale (un processo, un programma o un utente a seconda del livello di 
astrazione considerato) abbia visibilità delle sole risorse necessarie al suo 
funzionamento. Lo scopo dell'applicazione del principio e' quello di concedere 
solo il minimo insieme di privilegi possibile in ogni istante, in modo da 
migliorare la protezione del sistema.

La funzione setuid() consente di modificare il real-UID e l'effective-UID, vi
sono regole ben precise a riguardo:

1 Se il processo gode dei privilegi di super-user, la funzione setuid() setta
  il real UID, l'effective UID e il saved UID a 'uid';

2 Se il processo non gode dei privilegi di super-user, e 'uid' e' uguale o al
  real-UID o al saved-UID, la funzione setuid() imposta solo l'effective-UID
  a 'uid';
  
3 Se nessuna delle condizioni sopra citate e' vera, 'errno' e' impostata
  a EPERM, e la funzione setuid() ritorna -1.

Le regole per Group-ID sono le medesime di User-ID

## Setup Effective User-ID and Effective Group-ID; setuid(), setgid()

`int setuid(uid_t uid);`

La funzione `setuid()` setta l'effective user-ID del processo chiamante a `uid`.
Ritorna 0 in caso di successo, -1 in caso di errore.
            
`int setgid(gid_t gid);`

La funzione `setgid()` setta l'effective group-ID del processo chiamante a `gid`.
Ritorna 0 in caso di successo, -1 in caso di errore.

## setreid() setregid()

PROTOTYPE : int setreuid(uid_t ruid, uid_t euid);
            int setregid(uid_t rgid, gid_t egid);
SEMANTICS : La funzione setreuid() imposta il real user-ID e l'effective user-ID
            a 'ruid' e 'euid' rispettivamente;
	    la funzione setregid() imposta il real group-ID e l'effective group-
	    ID a 'rgid' e 'egid' rispettivamente;
RETURNS   : 0 in caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
Impostando ciascun parametro a -1, i valori non saranno modificati.


## seteuid() setegid()
PROTOTYPE : int seteuid(uid_t uid);
            int setegid(uid_t gid);
SEMANTICS : La funzione seteuid() setta l'effective user-ID a 'uid';
            la funzione setegid() setta l'effective group-ID a 'gid'.
RETURNS   : 0 in caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
Le funzioni sopra citate sono simili alle funzioni setuid() e setgid(), l'unica
e sostanziale differenza e' che tali funzioni vanno a modificare solo
l'effective user-ID e l'effective group-ID.
