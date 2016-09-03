## igraph

igraph a collection of network analysis tools to design directed acyclic graphs


### Package and Header library

On Debian GNU/Linux and its derivatives the package is `libigraph0`, the header to add is `<igraph/igraph.h>`


### How to compile

$ `gcc test.c -std=c11 -Wall -pedantic **-I/usr/local/igraph -L/usr/local/lib -ligraph**`

or

$ `gcc test.c -std=c11 -Wall -pedantic '**pkg-config --libs --cflags igraph**'`

or

$ `gcc test.c -std=c11 -Wall -pedantic **-ligraph**`
