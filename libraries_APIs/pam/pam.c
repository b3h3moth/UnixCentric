#include <stdio.h>
#include <stdlib.h>
#include <security/pam_appl.h>
#include <security/pam_misc.h>

int main(void) {
    pam_handle_t* pamh;
    struct pam_conv pamc;
    
    // Setup PAM conversation
    pamc.conv = &misc_conv;
    pamc.appdata_ptr = NULL;
  
    // New authentication session
    pam_start ("su", getenv ("USER"), &pamc, &pamh);
  
    // User authentication
    if (pam_authenticate (pamh, 0) != PAM_SUCCESS)
        fprintf (stderr, "Authentication failed!\n");
    else
        fprintf (stderr, "Authentication OK.\n");
  
    /* All done.  */
    pam_end (pamh, 0);
  
    return(EXIT_SUCCESS);
}
