## How To compile OpenSSL library

On Debian GNU/Linux and its derivatives you need to install 'libssl-dev'
package, then compile:

``$ gcc   file.c -std=c11 (c99) -Wall -pedantic -lcrypto -o prog_name
$ clang file.c -std=c11 (c99) -Wall -pedantic -lcrypto -o prog_name``
