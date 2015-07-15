#include <stdio.h>
#include <stdlib.h>

#define CRYPTO_FIPS "/proc/sys/crypto/fips_enabled"

int main(int argc, char *argv[]) {
    FILE *fp;
    char c;
    
    if ( (fp = fopen( CRYPTO_FIPS, "r")) == NULL) {
        printf("The OS doesn't support kernel crypto module!\n");
        return(EXIT_FAILURE);
    }
    
    if (fread(&c, sizeof(c), 1, fp) <= 0){
        printf("failed to read from: %s\n", CRYPTO_FIPS);
        fclose( fp);
        return(EXIT_FAILURE);
    }
    
    printf("FIPS_MODE: %c\n", c);
    
    fclose(fp);
    
    return(EXIT_SUCCESS);
}
