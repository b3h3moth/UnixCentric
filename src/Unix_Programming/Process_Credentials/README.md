# Process Credentials

* [Process Identification](#headPC1)
* [Access control](#headPC2)
* [Setup Effective User-ID and Effective Group-ID; setuid(), setgid()](#headPC3)
* [Setup Real User-ID and Real Group-ID; setreuid(), setregid()](#headPC4)
* [Retrieving supplementary Group IDs](#headPC5)

---

## <a name="headPC1"></a>Process Identification

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

## <a name="headPC2"></a>Access control

Un sistema UNIX o UNIX-like e' basato su fondamenti di sicurezza 
imprescindibili, anzitutto vi e' una netta differenziazione tra il __superuser__
(o __root__) che gode del pieno controllo del sistema e gli utenti che 
inevitabilmente hanno diverse restrizioni, vi e' inoltre il concetto di 
"__utente__" e di "__gruppo__".

Il sistema associa un identificatore univoco ad ogni utente e gruppo, 
lo __user-ID__ (__UID__) e il __group-ID__ (__GID__) rispettivamente, che 
servono al kernel per identificare uno specifico utente o un gruppo, e grazie 
ad essi verificare se godono delle autorizzazioni necessarie per eseguire i 
compiti richiesti.

Poiche' tutte le operazioni del sistema sono eseguite da uno o piu' processi,
risulta ovvio che per poter fornire un controllo su tali operazioni e' 
necessario essere a conoscenza dell'utente che ha lanciato il programma, ragion
per cui anche un processo deve avere i propri __UID__ e __GID__.

I sistemi unix-like forniscono i seguenti gruppi di identificatori:

* __Real User-ID__ (__RUID__), __Real Group-ID__ (__RGID__)
Sono impostati al login al valore dell'utente e del gruppo con cui si accede al 
sistema. Solitamente non vengono cambiati, potrebbe farlo tuttavia solo un 
processo che gode dei privilegi di superuser. 
Identificano l'utente e il gruppo a cui il processo appartiene, in pratica cio'
che siamo all'interno di un sistema.

* __Effective User-ID__ (__EUID__), __Effective Group-ID__ (__EGID__)
Sono utilizzati nelle verifiche dei permessi del processo e per il controllo 
d'accesso ai file, in pratica identificano l'utente e il gruppo usati per 
decidere se un processo possa o meno accedere ad una risorsa.

> Solitamente __Real__ ed __Effective__ sono identici, tranne nel caso in cui 
> il programma in esecuzione avesse i bit '__suid__' o '__sgid__' impostati, in 
> tal caso gli effective saranno impostati al nome dell'utente e del gruppo 
> proprietari del file. Questo e' il caso in cui un programma puo' essere 
> eseguito da un utente con privilegi di __superuser__ (o altri), che tuttavia 
> potrebbe rappresentare un serio problema di sicurezza qualora non fosse
> utilizzato con accortezza.
              
Ai due si aggiunge anche l'effective GID di altri eventuali gruppi di 
appartenenza.

* __Saved User-ID__, __Saved Group-ID__
Solo se _POSIX_SAVED_IDS e' impostato.
Sono copie dell'Effective User-ID ed Effettive Group-ID del processo padre - 
impostati da una delle funzioni exec all'avvio del processo - cosi che possano
essere ripristinati.

I sistemi con kernel Linux dispongono anche dell'identificatore filesystem, una
estensione di sicurezza NFS.

> `man 7 credentials`

## <a name="headPC3"></a>Setup Effective User-ID and Effective Group-ID; setuid(), setgid()

Quando un programma necessita di privilegi addizionali oppure ottenere l'accesso
a specifiche risorse per le quali non si hanno i dovuti privilegi, si devono 
modificare l'user-ID (UID) e il group-ID (GID); naturalmente questa e' la strada
da seguire anche qualora i privilegi dovessero essere ridotti.

> Si assume che la costante ___POSIX_SAVED_IDS__ sia settata, altrimenti
> i riferimenti a __Saved UID__ non saranno disponibili; per verificarlo e' 
> possibile invocare la funzione `sysconf()` con l'argomento ___SC_SAVED_IDS__ 
> a _run-time_ oppure a _compile-time_ con l'argomento ___POSIX_SAVED_IDS__.

Le applicazioni dovrebbero essere sviluppate seguendo il modello del 
"__least privilege__", ossia _il principio del privilegio minimo_; 
in informatica e in altri campi, il principio del privilegio minimo richiede 
che in un particolare livello di astrazione di un ambiente di calcolo ogni modulo 
computazionale - un processo, un programma o un utente a seconda del livello di 
astrazione considerato - abbia visibilità delle sole risorse necessarie al suo 
funzionamento. Lo scopo dell'applicazione del principio e' quello di concedere 
solo il minimo insieme di privilegi possibile in ogni istante, in modo da 
migliorare la protezione del sistema.

La funzione `setuid()` consente di modificare il __Real-UID__ e 
__l'Effective-UID__, e vi sono regole ben precise a riguardo:

1. Se il processo gode dei privilegi di __super-user__, la funzione `setuid()` 
imposta il __Real UID__, l'__Effective-UID__ e il __Saved-UID__ a '__uid__';

2. Se il processo non gode dei privilegi di __superuser__, e '__uid__' e' uguale 
o al __Real-UID__ o al __Saved-UID__, la funzione `setuid()` imposta solo 
l'__Effective-UID__ a '__uid__';
  
3. Se nessuna delle condizioni sopra citate e' vera, '__errno__' e' impostata
a __EPERM__, e la funzione `setuid()` ritorna -1.

Le regole per i gruppi sono concettualmente identiche, la sola eccezione e' che
naturalmente si lavora sui gruppi.

```int setuid(uid_t uid);```

La funzione `setuid()` setta l'effective user-ID del processo chiamante a `uid`.
Ritorna 0 in caso di successo, -1 in caso di errore.
            
```int setgid(gid_t gid);```

La funzione `setgid()` setta l'effective group-ID del processo chiamante a `gid`.
Ritorna 0 in caso di successo, -1 in caso di errore.

> Per la modifica dell'effetive user-ID possono essere utilizzate anche le
> funzioni `seteuid()` e `setegid()`.

## <a name="headPC4"></a>Setup Real User-ID and Real Group-ID; setreuid(), setregid()

```int setreuid(uid_t ruid, uid_t euid);```

La funzione `setreuid()` setta il real user-ID e l'effective user-ID del 
processo chiamante a `ruid` e '`euid'` rispettivamente. Ritorna 0 in caso di 
successo, -1 in caso di errore.

```int setregid(uid_t rgid, gid_t egid);```

La funzione `setregid()` setta il real group-ID e l'effective group-ID del
processo chiamante a `rgid'` e `egid` rispettivamente. Ritorna 0 in caso di 
successo, -1 in caso di errore.

Impostando ciascun parametro a -1, i valori non saranno modificati.

## <a name="headPC5"></a>Retrieving supplementary Group IDs

```int getgroups(int size, gid_t list[]);```

La funzione `getgroups()` ritorna l'insieme di gruppi supplementari ai quali il
processo chiamante appartiene.

```int setgroups(size_t size, const gid_t *list);```

La funzione `setgroups()` rimpiazza l'insieme di gruppi supplementari ai quali 
il processo chiamante appartiene, con i gruppi forniti da ```*list```.

> Il numero massimo di gruppi supplementari a disposizione e' possibile 
> ottenerlo da ```/proc/sys/kernel/ngroups_max``
