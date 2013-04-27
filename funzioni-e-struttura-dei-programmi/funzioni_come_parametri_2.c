#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int somma(int a, int b);
int moltiplica(int (*somma)(int x, int y), int a, int b);

int main(int argc, char *argv[]) {
    int n = moltiplica(somma, 1, 10);
    
    printf("%d\n", n); 
    
    return(EXIT_SUCCESS);
}


int somma(int a, int b)
{
    return a+b;
}

int moltiplica(int (*somma)(int x, int y), int a, int b)
{ 
    int temp;
    temp = (*somma)(a,b);

    /* 
    temp = (somma)(a,b);
    */
    
    return temp * temp;
    /*
    return (somma)(a,b) * (somma)(a,b);
    */
}
