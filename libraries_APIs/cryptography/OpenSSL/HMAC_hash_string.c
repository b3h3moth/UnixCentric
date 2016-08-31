#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/hmac.h>

enum { LEN = 20 };

/* The program's purpose is how to hash a string through OpenSSL hash function
by using sha() or sha1() hash engine. */

int main(void) {
    // The Key to hash
    char key[] = "A1B2C3B4C5";
    // The string to hash
    char data[] = "OpenSSL Hash function";
    unsigned char *dgst = NULL;
    char mdstr[LEN] = {0};

    /* You may use many hash engines:
    EVP_sha()
    EVP_sha1()
    EVP_sha224()
    EVP_sha256()
    EVP_sha384()
    EVP_sha512()
    In this case it is sha. */
    dgst = HMAC(EVP_sha(), key, strlen(key), (unsigned char *)data, \
                strlen(data), NULL, NULL);

    for (int i=0; i<LEN; i++)
        sprintf(&mdstr[i*2], "%02x", (unsigned int)dgst[i]);

    printf("HMAC digest is: %s\n", mdstr);

    return(EXIT_SUCCESS);
}
