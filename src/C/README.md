## Standard C11 (iso9899:2011) Language Programming

The repository purpose is to talk about C11 (Standard ISO)

### bitwise Hacks

From bitwise operators to the binary representation. A journey among the bits.

* bit operators;
* shifting;
* extract, clear and setup a bit;
* extract, clear and setup a bitfield;
* bit hacks.

### interfaces

How to build robust interfaces.

### Libraries and API's

A lot of libraries for every day use; graphics, cryptography, serialization, 
database, I/O and so on.

Full tutorial:

* cairo library (2D graphics)
* SDL, Simple DirectMedia Library (2D graphics)
* SQLite C API Library (RDMS)

### Representing information

How computer really works:

* addressing 
* Byte ordering (Big-endian, Little-endian)
* integer representation
  * char, short, int, long (signed and unsigned);
  * casting and information loss
  * integer arithmetic

* floating point (Standard IEEE 754 single and double precision)
  * float, double
  * (to do, at the moment is empty)

### c11 - Syntax, Tips and Tricks

A lot of articles focused on c11 standard, the core of the language is also
treated,

#### How to compile programs

The programs will be compiled with two standard:

- `iso9899:1999`, ``-std=c99``

- `iso9899:2011`, ``-std=c11`` (experimental and incomplete from GCC 4.7)

Architecture for testing code:

- `PPC 32 bit` (big endian)
- `x86 32 bit` (little endian)
- `x86 64 bit` (little endian)

Each program can be compiled both gcc and clang:

$ ``gcc   main.c -o main``

$ ``clang main.c -o main``

Or with more detail:

$ ``gcc   -o main main.c -g -Wall -pedantic -std=c99`` | oppure ``-std=c11``

$ ``clang -o main main.c -g -Wall -pedantic -std=c99`` | oppure ``-std=c11``

Note: `-ansi` option equals `-std=c90`
      `-std=c90` option equals `-std=c89`

<address>`*Luca Suriano a.k.a. Behemoth*: <behemoth _at_ autistici _dot_ org>`</address>
