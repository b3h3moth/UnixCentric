#include <stdio.h>
#include <stdlib.h>
#include <security/pam_appl.h>
#include <security/pam_misc.h>

/* How to compile the program:

$ gcc -std=c11 -Wall -pedantic -lpam -lpam_misc authentication.c

The program's purpose is to authenticate the logged user.
*/

int main(void) {
    pam_handle_t* pamh;
    struct pam_conv pamc;
    
    // Setup PAM conversation
    pamc.conv = &misc_conv;
    pamc.appdata_ptr = NULL;
  
    // New authentication session
    pam_start ("su", getenv("USER"), &pamc, &pamh);
  
    // User authentication
    if (pam_authenticate (pamh, 0) != PAM_SUCCESS)
        fprintf (stderr, "Ops, failed Authentication.\n");
    else
        fprintf (stderr, "Authentication is ok. Hi %s\n", getenv("USER"));
  
    // Clean up any allocated data structures
    pam_end (pamh, 0);
  
    return(EXIT_SUCCESS);
}
