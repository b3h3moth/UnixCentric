### How to compile SQLite3 library

First of all install the SQLite library.

- on Debian GNU/Linux and its derivatives:
`# apt-get install libsqlite3-dev libsqlite3-doc`

The proper header to include is `#include <sqlite3.h>`

$ gcc -stc=c11 -lsqlite3 -Wall -pedantic file.c -o prog
$ clang -stc=c11 -lsqlite3 -Wall -pedantic file.c -o prog

### Get SQLite library

[Download][https://sqlite.org/download.html] source code from main site.
