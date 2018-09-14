We would like to create a link library containing the object code of the pow() 
function, which can be called from different C programs.

We produce the file object mymath.o:
1) gcc -c mymath.c 

Create static link library from mymath.o:
2) ar rcs libmylib.a mymath.o

Static compile main.c with mylib.a as link library. 
Note that -L speciﬁes the "current directory" library path, 
-l speciﬁes the library, without prefix 'lib' and suffix 'a':
3) gcc -static main.c -L. –lmylib

Now executable is ready to be executed:
4) ./a.out
