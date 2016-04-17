#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { OFFSET = 3, MAX_BUF = 50 };

int main(void) {
    char string1[MAX_BUF] = "Take a walk on the wild side";
    char string2[MAX_BUF] = "Rastaman vibration positive";
    char buf[MAX_BUF];

    // Testing memset()
    printf("%16s %s\n", "memset() Before:", string1);
    memset(string1 + OFFSET, 'X', 10);
    printf("%16s %s\n", "memset() After:",string1);

    // Testing memcpy(), no overlap
    strcpy(buf, string2);
    printf("%16s %s\n", "Default string:", buf);
    memcpy(buf + 2, buf + 12, 10);
    printf("%16s %s (%s)\n", "memcpy() After:", buf, "No overlap");

    // Testing memcpy(), with overlap
    memcpy(buf, buf + 5, 10);
    printf("%16s %s (%s)\n", "memcpy() After:", buf, "with overlap");

    return(EXIT_SUCCESS);
}
