### Prepared Statement life cycle

> Once a database connection is established, we can start to execute SQL commands,
this is done preparing and stepping through statements. The database connection
and prepared statements objects are controlled by a set of routine:

* `sqlite3_open()`        
* `sqlite3_prepare()`     1st step
* `sqlite3_step()`        2nd step
* `sqlite3_column()`      3rd step
* `sqlite3_finalize()`    4th step
* `sqlite3_close()`       

> The `sqlite3_exec()` interface is a convenience wrapper that carries out all four
of the above steps with a single function call. A callback function passed into 
`sqlite3_exec()` is used to process each row of the result set.

[An Introduction to the SQLite C/C++ interface][https://www.sqlite.org/cintro.html]

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
