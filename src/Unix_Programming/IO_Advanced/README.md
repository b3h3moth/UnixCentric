## pread(), pwrite()

Le system call `pread()` e `pwrite()` combinano gli effetti di una chiamata a
`lseek()`, `read()` - o `write()` - in una singola system call, tutto cio'
fornisce un miglioramento nelle performance.

 ```ssize_t pread(int fd, void *buf, size_t count, off_t offset);```

La funzione `pread()` legge `count` byte dal file descriptor `fd` all'offset 
`offset` (dall'inizio del file) nel buffer a partire da `buf`.

 ```ssize_t pwrite(int fd, const void *buf, size_t count, off_t offset);```

La funzione `pwrite()` scrive `count` byte dal buffer a partire da `buf` nel 
file descriptor `fd` all'offset `offset`.

In entrambi i casi l'offset del file non viene modificato. In caso di successo 
ritornano il numero di byte letti o scritti. `0` indica che nessun byte e' stato
scritto dalla `pwrite()`, mentre `EOF` che la `pread()` ha raggiunto la fine del
file. In caso di errore ciascuna di esse ritorna `-1`.

> **Nota**: Non sono standard C, per cui e' necessario informare il compilatore
di aggiungere delle funzioni extra POSIX per far si che non vengano inviati
messaggi di warning in fase di compilazione.

La compilazione sara' la seguente:
    
 ```$ gcc -Wall -pedantic -std=c11 -D_XOPEN_SOURCE=500 file.c```


## readv(), writev(), Scatter/Gather I/O or Vectored I/O

Lo **scatter-gather I/O** e' un metodo di input output per gestire con una
singola system call la lettura e la scrittura di mulipli buffer - un vettore di
buffer - da un unico stream. 

Le system call deputate a tale scopo sono `readv()` per la lettura e `writev()` 
per la scrittura.

```ssize_t readv(int fd, const struct iovec *iov, int iovcnt);```

La funzione `readv()` legge i buffer `iovcnt` dal file associato al file 
descriptor `fd` nei buffer descritti da `iov` (__scatter input__).

```ssize_t writev(int fd, const struct iovec *iov, int iovcnt);```

La funzione `writev()` scrive i buffer `iovcnt` descritti da `iov` nel file 
associato al file descriptor `fd` (__gather output__).

`iov` e' un puntatore alla struttura `iovec` definita in `sys/uio.h`:
```
struct iovec {
  void   *iov_base;   // Indirizzo di partenza
  size_t *iov_len;    // Numero di byte da trasfeerire
}
```

> I trafserimenti eseguiti da entrambe le system call sono atomici.
