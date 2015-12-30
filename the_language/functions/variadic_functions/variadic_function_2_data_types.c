#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int iterate(const char *format, ...);

int main(void) {
    char *string = "variadic functions";
    printf("number of elements: %2d (char)\n", iterate("char", string));

    int arr[] = {10, 20, 30, 40, 50, 60, -1};
    printf("number of elements: %2d (int)\n", iterate("int", arr));

    long long vec[] = {100, 200, 300, 400, 500, 600, -1};
    printf("number of elements: %2d (long long)\n", iterate("long long", vec));

    return(EXIT_SUCCESS);
}

int iterate(const char *format, ...) {
    va_list ap;
    va_start(ap, format);

    if (strcmp(format, "char") == 0) {
        char *array = va_arg(ap, char*);

        return strlen(array);
    } else if (strcmp(format, "int") == 0) {
        int i = -1;
        int *int_array = va_arg(ap, int*);
        
        while (int_array[++i] != -1)
                    ;     
        return i;
    } else if (strcmp(format, "long long") == 0) {
        int j = -1;
        long long *llong_vector = va_arg(ap, long long*);

        while (llong_vector[++j] != -1)
                    ;

        return j;
    }

    
    return(EXIT_SUCCESS);
}
