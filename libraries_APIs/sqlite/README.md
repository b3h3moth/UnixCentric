### SQLite API C functions covered

Either open or create database.

* sqlite3_open();
* sqlite3_open_v2();

Execute query

* sqlite3_exec();
* sqlite3_exec_v2();

Close database connection

* sqlite3_close();
* sqlite3_close_v2();

### How to compile SQLite3 library

First of all install the SQLite library.

- on Debian GNU/Linux and its derivatives:
`# apt-get install libsqlite3-dev libsqlite3-doc`

The proper header to include is `#include <sqlite3.h>`

$ gcc -stc=c11 -lsqlite3 -Wall -pedantic file.c -o prog
$ clang -stc=c11 -lsqlite3 -Wall -pedantic file.c -o prog

### Get SQLite library

[Download][https://sqlite.org/download.html] source code from main site.
