## pread(), pwrite()

Le system call `pread()` e `pwrite()` combinano gli effetti di una chiamata a
`lseek()`, `read()` - o `write()` - in una singola system call.

> ```ssize_t pread(int fd, void *buf, size_t count, off_t offset);```

pread() legge `count` byte dal file descriptor `fd` all'offset `offset` 
(dall'inizio del file) nel buffer a partire da `buf`.

> ```ssize_t pwrite(int fd, const void *buf, size_t count, off_t offset);```

pwrite() scrive `count` byte dal buffer a partire da `buf` nel file descriptor 
`fd` all'offset `offset`.

In entrambi i casi l'offset del file non viene modificato.

In caso di successo ritornano il numero di byte letto o scritti, 0 indica
che nessun byte e' stato scritto dalla `pwrite()` oppure EOF dalla pread(). In
caso di errore -1.
