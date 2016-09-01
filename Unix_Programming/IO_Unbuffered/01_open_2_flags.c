#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

/* Costanti relative ai bit di permesso sui file
------------------------------------------------
S_ISUID | 04000 |
S_ISGID | 02000 |
S_ISVTX | 01000 |
--------+-------+
S_IRUSR |  0400 |
S_IWUSR |  0200 |
S_IXUSR |  0100 |
--------+-------+
S_IRGRP |   040 |
S_IWGRP |   020 |
S_IXGRP |   010 |
--------+-------+
S_IROTH |    04 |
S_IWOTH |    02 |
S_IXOTH |    01 |
--------+-------+
S_IRWXU |  0700 |
S_IRWXG |    70 |
S_IRWXO |    07 |

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

    /* Permessi sono stati impostati in ottale a 0755 */
    file_perms = S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((input_fd = open(argv[1], file_flags, file_perms)) < 0) {
        fprintf(stderr, "Err. opening %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((close(input_fd)) < 0) {
        fprintf(stderr, "Err. close(%s)\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}
