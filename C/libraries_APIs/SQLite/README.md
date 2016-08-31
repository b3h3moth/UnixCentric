# SQLite 

> SQLite wants to replace fopen() not Oracle.

## Prepared Statement life cycle

Once a database connection is established, we can start to execute SQL commands,
this is done __preparing and stepping through statements__. The database 
connection and prepared statement objects are controlled by a set of routine:

* `sqlite3_open()`        
* `sqlite3_prepare()`     1st step
* `sqlite3_step()`        2nd step
* `sqlite3_column()`      3rd step
* `sqlite3_finalize()`    4th step
* `sqlite3_close()`       

## rowid (alias of row identificator)

SQLite automatically create an implicit column named 'rowid' and automatically
assigns an integer value whenever you insert a new row. When a table with an
'INTEGER PRIMARY KEY' column is created, this column will points to the
'rowid'.

Get the last rowid added with `sqlite3_last_insert_rowid()` function.


## The SQLite core C APIs

Opening a new database connection:

* `sqlite3_open()`
* `sqlite3_open_v2()`

Bound parameters

* `sqlite3_bind_text()`
* `sqlite3_bind_blob()`
* `sqlite3_bind_parameter_index()`
* `sqlite3_bind_parameter_count()`
* `sqlite3_bind_parameter_name()`

One-step query execution interface:

* `sqlite3_exec()`

Closing a database connection:

* `sqlite3_close()`
* `sqlite3_close_v2()`

Working with BLOB data type:

* `sqlite3_blob_open()`
* `sqlite3_blob_read()`
* `sqlite3_blob_write()`
* `sqlite3_blob_close()`


## How to compile SQLite3 library

First of all install the SQLite library.

- on ``Debian GNU/Linux`` and its derivatives:
`# apt-get install libsqlite3-dev libsqlite3-doc`

The proper header to include is `#include <sqlite3.h>`

```
$ gcc -stc=c11 -lsqlite3 -Wall -pedantic file.c -o prog
$ clang -stc=c11 -lsqlite3 -Wall -pedantic file.c -o prog
```

## Bibliography

There are few books that cover the SQLite C API from beginning to end:

* **The Definitive Guide to SQLite**; *Grant Allen*, *Mike Owens* (`2nd, 2010, Apress`)
* **Using SQLite**; *Jay A. Kreibich* (`2010, O'Reilly`)


## How to get the library

[download](https://sqlite.org/download.html) source code from main site.
