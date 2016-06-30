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

## Convenience functions

The `sqlite3_exec()` interface is a __convenience wrapper__ that carries out all four
of the above steps with a single function call. A callback function passed into 
`sqlite3_exec()` is used to process each row of the result set.

[An Introduction to the SQLite C/C++ interface](https://www.sqlite.org/cintro.html)

> Convenience functions can be used to prepare, step, and finalize SQL statement
in one call

These functions are not faster, doesn't support the use of bound parameters, so
you're forced to use string manipulation to build SQL commands. They are 
acceptable for DDL commands (Data Definition Language) but for any type of DML 
command (Data Manipulation Language) is strongly reccomended using the prepared 
statements.

## rowid

SQLite automatically create an implicit column named 'rowid' and automatically
assigns an integer value whenever you insert a new row. When a table with an
'INTEGER PRIMARY KEY' column is created, this column will points to the
'rowid'.

Get the last rowid added with `sqlite3_last_insert_rowid()` function.

## The SQLite API C functions covered

Opening a new database connection:

* `sqlite3_open()`
* `sqlite3_open_v2()`

Bound parameters

* `sqlite3_bind_text()`
* `sqlite3_bind_parameter_index()`
* `sqlite3_bind_parameter_count()`
* `sqlite3_bind_parameter_name()`

One-step query execution interface:

* `sqlite3_exec()`

Closing a database connection:

* `sqlite3_close()`
* `sqlite3_close_v2()`

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

There are only two books that tell about API C.

* **The Definitive Guide to SQLite**; *Grant Allen*, *Mike Owens* (`2nd, 2010, Apress`)
* **Using SQLite**; *Jay A. Kreibich* (`2010, O'Reilly`)

## Get SQLite library

[Download](https://sqlite.org/download.html) source code from main site.
