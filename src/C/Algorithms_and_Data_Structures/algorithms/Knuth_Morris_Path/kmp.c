#include <string.h>
#include <stdlib.h>
#include "kmp.h"

int kmp(char *p, char *s) {
    int m = 0;
    int i = 0;
    int t[strlen(p)];

    while (s[m+i] != '\0' && p[i] != '\0') {
        if (s[m+i] == p[i]) {
            ++i;
        } else {
            m += i - t[i];
            if (i > 0)
                i = t[i];
        }
    }

    if (p[i] == '\0')
        return m;
    else
        return m + i;
}
