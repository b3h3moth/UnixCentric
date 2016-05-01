#ifndef _ADDRESSLIST_H
#define _ADDRESSLIST_H

#define NAME_LEN    20      // Longest name
#define ADDR_LEN    80      // Longest address
#define MAIL_LEN    30      // Longest e-mail
#define MAX_ADDR    500    // Max addresses allowed

char const *lookup_addr(char const *name);
char const *lookup_mail(char const *name);

#endif
