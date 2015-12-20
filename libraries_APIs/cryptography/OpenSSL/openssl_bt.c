#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

/* On Debian GNU/Linux and its derivatives install libssl-dev package, then
compile with:

$ gcc program.c -lcrypto -o prog

The program's purpose is to produce the keys.
*/


int main(int argc, char *argv[]) {
    int i;
    const EVP_CIPHER *cipher;
    const EVP_MD *dgst = NULL;
    unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];
    const char *password = "password";
    const unsigned char *salt = NULL;

    OpenSSL_add_all_algorithms();

    cipher = EVP_get_cipherbyname("aes-256-cbc");

    if(!cipher) { 
        fprintf(stderr, "Err.: No cipher\n"); 
        return(EXIT_FAILURE);
    }

    dgst = EVP_get_digestbyname("md5");
    
    if(!dgst) { 
        fprintf(stderr, "Err.: no such digest\n"); 
        return(EXIT_FAILURE);
    }

    if(!EVP_BytesToKey(cipher, dgst, salt, (unsigned char*)password, 
                       strlen(password), 1, key, iv)) {
        fprintf(stderr, "Err.: EVP_BytesToKey failed\n");
        return(EXIT_FAILURE);
    }

    printf("Key: "); 
    for(i=0; i<cipher->key_len; ++i) { 
        printf("%02x", key[i]); 
    } printf("\n");
    
    printf("IV: "); 
    for(i=0; i<cipher->iv_len; ++i) { 
        printf("%02x", iv[i]); 
    } printf("\n");

    return(EXIT_SUCCESS);
}

