We would like to create a link library containing the object code of the pow() 
function, which can be called from different C programs.

We produce the file object pow.o:
1) gcc -c pow.c 

Create static link library from pow.o:
2) ar rcs libmylib.a pow.o

Static compile-link main.c with mylib.a as link library. Note that -L speciﬁes 
the "current directory" library path, and -l speciﬁes the library, without 
prefix 'lib' and suffix 'a':
3) gcc -static main.c -L. –lmylib

Now executable is ready to be executed:
4) ./a.out
