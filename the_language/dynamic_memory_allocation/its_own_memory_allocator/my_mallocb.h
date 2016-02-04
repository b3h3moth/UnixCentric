#ifndef MY_ALLOCB
#define MY_ALLOCB

struct mem_block {
    int free;
    size_t size;
};

// Prototipi
void init_alloc(void);

#endif
