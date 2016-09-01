#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

/* Costanti relative ai bit di permesso sui file
------------------------------------------------
S_ISUID | 04000 | Set User ID
S_ISGID | 02000 | Set Group ID
S_ISVTX | 01000 | Sticky bit
--------+-------+--------------
S_IRUSR |  0400 | User Read
S_IWUSR |  0200 | User Write
S_IXUSR |  0100 | User Execute
--------+-------+--------------
S_IRGRP |   040 | Group Read
S_IWGRP |   020 | Group Write
S_IXGRP |   010 | Group Execute
--------+-------+--------------
S_IROTH |    04 | Other Read
S_IWOTH |    02 | Other Write
S_IXOTH |    01 | Other Execute
--------+-------+--------------
S_IRWXU |  0700 | User  R/W/X
S_IRWXG |   070 | Group R/W/X
S_IRWXO |    07 | Other R/W/X

*/

int main(int argc, char *argv[]) {
    int input_fd, file_flags;
    mode_t file_perms;

    /* Il file sara' creato, o per lo meno dovrebbe esserlo, con i seguenti
    permessi: rw-rw-rw (00666).

    Solo uno tra O_RDWR, O_RDONLY e O_WRONLY deve essere specificato in
    flags; inoltre se O_CREAT non e' stato inserito gli eventuali permessi
    saranno ignorati, nel caso specifico 'file_perms'.  */

    file_flags = O_RDWR | O_CREAT | O_TRUNC;

    /* Permessi impostati al valore ottale 0755 */
    file_perms = S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((input_fd = open(argv[1], file_flags, file_perms)) < 0) {
        fprintf(stderr, "Err. opening %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    close(input_fd);

    return(EXIT_SUCCESS);
}
