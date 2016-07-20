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

### c11 - The language

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

### Bibliography

The best books to learn and improve own skills and knowledge about C language 
programming and secure coding.

#### c89
  * **The C Programming Language: ANSI C Version**; *Brian W.Kernighan* (`2nd, 1988, Prentice Hall`)
  * **The Standard C Library**; *Phillip James Plauger* (`1992, Prentice Hall`)
  * **Expert C Programming: Deep C Secrets**; *Peter Van Der Linden* (`1994, Prentice Hall`)
  * **C Interfaces and Implementations: Techniques for Creating Reusable Software**; *David R.Hanson* (`1996, Addison Wesley`)
  * **Pointers on C**; *Kenneth Reek* (`1997, Pearson`)
  * **A book on C: Programming in C**; *Al Kelley*, *Ira Pohl* (`4th, 1998, Addison Wesley`)

#### c99
  * **The Practice of Programming**; *Brian W.Kernighan*, *Rob Pike* (`1999, Addison Wesley`)
  * **C Programming: A modern Approach**; *Kim N.King* (`2nd, 2008, W. W. Norton & Company`)
  * **Secure coding in C and C++**; *Robert C.Seacord* (`2nd, 2013, Addison Wesley`)

#### c11
  * **21st Century C: C Tips from the New School**; *Ben Klemens* (`2nd, 2014, O'Reilly`)
  * **The CERT C Coding Standard: 98 Rules for Developing Safe, Reliable, and Secure Systems**; *Robert C.Seacord* (`2014, Addison Wesley`)

<hr />

<address>`*Luca Suriano a.k.a. Behemoth*: <behemoth _at_ autistici _dot_ org>`</address>

<url>`https://keybase.io/behemoth`</url>
