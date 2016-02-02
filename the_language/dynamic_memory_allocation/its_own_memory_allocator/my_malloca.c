#ifndef MY_ALLOCA
#define MY_ALLOCA

#include <unistd.h> // sbrk()

/* my malloc (a)
utilizza la syscall sbrk() per la manipolazione dello heap; sbrk(0) ritorna un
puntatore a 'break', ovvero in cima allo heap, sbrk(n) incrementa lo heap di
'n' byte e ritorna un puntatore al nuovo indirizzo. */

void *malloca(size_t size) {


