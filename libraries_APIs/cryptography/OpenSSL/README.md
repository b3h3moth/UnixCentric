## Secure Sockets Layer toolkit - development files

On Debian GNU/Linux and its derivatives you need to install *libssl-dev*
package. 

This package is part of the OpenSSL project's implementation of the SSL and TLS
cryptographic protocols for secure communication over the internet. It contains
development libraries, header files, and manpages for libssl and libcrypto. 
[Description: `dpkg -s libssl-dev`]


## How To compile OpenSSL library

Linking program with -l option and appropriate library.

``$ gcc   file.c -std=c11 (c99) -Wall -pedantic -lcrypto -o prog_name``

``$ clang file.c -std=c11 (c99) -Wall -pedantic -lcrypto -o prog_name``
