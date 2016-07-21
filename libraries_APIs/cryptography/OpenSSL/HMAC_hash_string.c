#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/hmac.h>

enum { LEN = 20 };

// The program's purpose is how to hash a string through OpenSSL hash function.

int main(void) {
    // The Key to hash
    char key[] = "A1B2C3B4C5";
    // The string to hash
    char data[] = "OpenSSL Hash function";
    unsigned char *dgst = NULL;
    char mdstr[LEN] = {0};

    // sha hash engine
    dgst = HMAC(EVP_sha(), key, strlen(key), (unsigned char *)data, \
                strlen(data), NULL, NULL);

    for (int i=0; i<LEN; i++)
        sprintf(&mdstr[i*2], "%02x", (unsigned int)dgst[i]);

    printf("HMAC digest is: %s\n", mdstr);

    return(EXIT_SUCCESS);
}
