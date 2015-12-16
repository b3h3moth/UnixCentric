First of all is necessary to install the cups library package, on Debian 
GNU/Linux and Debian-based systems it is: ``libcups-dev``.

``# apt get install libcups-dev``

Compile the source:

``$   gcc -std=c11 -Wall -pedantic -lcups main.c``
``$ clang -std=c11 -Wall -pedantic -lcups main.c``
