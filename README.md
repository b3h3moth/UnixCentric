### bit a bit

From bitwise operators to bitwise Hacks on integer and floating point data 
types.

### Libraries and API's

There are a lot of libraries for every day use; graphics, cryptography, 
serialization, nCurses, database and so on.

### Representing information

How computer really works: integer representations, integer arithmetic,
floating point (IEEE 754 single and double precision)

### The language

A lot of articles on the C language programming, C99 and C11 standards.

#### How to compile programs

I programmi saranno tutti compilati utilizzando i seguenti standard:

- `iso9899:1999`, ``-std=c99``

- `iso9899:2011`, ``-std=c11`` (sperimentale e incompleto in GCC, dalla versione 4.7)

Saranno utilizzate diverse architetture per testare gli esempi: 

- `PPC 32 bit` (big endian)
- `x86 32 bit` (little endian)
- `x86 64 bit` (little endian)

Ciascun sorgente potra' essere compilato sia mediante il compilatore GCC sia
con il comilatore Clang (LLVM):

$ ``gcc   main.c -o main``

$ ``clang main.c -o main``

Oppure, se si vuole maggiore dettaglio:

$ ``gcc   -o main main.c -g -Wall -pedantic -std=c99`` | oppure ``-std=c11``

$ ``clang -o main main.c -g -Wall -pedantic -std=c99`` | oppure ``-std=c11``

Nota: L'opzione `-ansi` e' equivalente a `-std=c90` per il C ed a `-std=c++98` per il
      C++. Inoltre `-std=c90` e' equivalente a `-std=c89`.

<hr />

<address>`*Luca Suriano a.k.a. Behemoth*: <behemoth _at_ autistici _dot_ org>`</address>

<url>`https://keybase.io/behemoth`</url>
