## Convenience functions - or convenience wrapper or convenience queries

The `sqlite3_exec()` interface is a __convenience wrapper__ that carries out all four
of the above steps with a single function call. A callback function passed into 
`sqlite3_exec()` is used to process each row of the result set.

[An Introduction to the SQLite C/C++ interface](https://www.sqlite.org/cintro.html)

> Convenience functions can be used to prepare, step, and finalize SQL statement
in one call.

These functions are not faster, doesn't support the use of bound parameters, so
you're forced to use string manipulation to build SQL commands. They are 
acceptable for DDL commands (Data Definition Language) but for any type of DML 
command (Data Manipulation Language) is strongly reccomended using the prepared 
statements.

> sqlite3_exec() should only be used  for one time use queries.
