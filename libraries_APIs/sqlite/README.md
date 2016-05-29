### Prepared statements life cycle

Once a database connection is established, we can start to execute SQL commands,
this is done preparing and stepping through statements. The database connection
and prepared statements objects are controlled by a set of routine:

* sqlite3_open()
* sqlite3_prepare()
* sqlite3_step()
* sqlite3_column()
* sqlite3_finalize()
* sqlite3_close()

### SQLite API C functions covered

Opening a new database connection:

* sqlite3_open();
* sqlite3_open_v2();

One-step query execution interface:

* sqlite3_exec();

Closing a database connection:

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
