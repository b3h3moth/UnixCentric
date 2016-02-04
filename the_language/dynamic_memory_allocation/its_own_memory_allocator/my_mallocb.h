#ifndef MY_ALLOCB
#define MY_ALLOCB

struct memory_block {
    int free;
    size_t size;
};

// Prototipi
void init_alloc(void);
void free_mem(void *first_byte);

#endif
