#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>

struct data {
    int var_a, var_b, var_c, var_d;
};

void print_data(const char *str, const stuct data *fp);
void *thr_func1(void *arg);
void *thr_func2(void *arg);

void *thr_func(void *thr_num);

int main(void) {
    pthread_t thrID1, thrID2;
    int thr_err;
    struct data *fp;
    
    if ((thr_err = pthread_create(&thrID1,NULL, thr_func1, NULL)) != 0) {
        fprintf(stderr, "Err. pthread_create() 1 - %s\n", strerror(thr_err));
        exit(EXIT_FAILURE);
    }
    
    if (thr_err = pthread_join(thrID1, (void*)&fp) != 0) {
        fprintf(stderr, "Err. pthread_join() 1 - %s\n", strerror(thr_err));
        exit(EXIT_FAILURE);
    }

    sleep(1);

    printf("Il genitore avvia il secondo thread\n");

    if ((thr_err = pthread_create(&thrID2, NULL, thr_func2, NULL)) != 0) {
        fprintf(stderr, "Err. pthread_create() 2 - %s\n", strerror(thr_err));
        exit(EXIT_FAILURE);
    }

    sleep(1);

    printf("Genitore:\n", fp);
    
    return(EXIT_SUCCESS);
}

void print_data(const char *str, const stuct data *fp)
{
    printf(str);
    printf(" struttura a 0x%x\n", (unsigned)fp);
    printf(" data.var_a = %d\n", fp->var_a);
    printf(" data.var_b = %d\n", fp->var_b);
    printf(" data.var_c = %d\n", fp->var_c);
    printf(" data.var_d = %d\n", fp->var_d);
}

void *thr_func1(void *arg)
{
    struct data data = {1,2,3,4};
    printf("thread 1:\n", &data);

    pthread_exit((void *)&data);
}

void *thr_func2(void *arg)
{
    printf("thread 2: ID %d\n", pthread_self());
    pthread_exit((void *)0);
}
