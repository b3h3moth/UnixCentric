We would like to create a link library containing the object code of the sum()
and mul() functions written inside mymath.c source file, which can be called 
from different C programs.

* We produce the file object mymath.o:
`

    gcc -c mymath.c `

* Create static link library from mymath.o:
`

    ar rcs libmylib.a mymath.o`

* Static compile main.c with mylib.a as link library. 
Note that -L speciﬁes the "current directory" library path, 
-l speciﬁes the library, without prefix 'lib' and suffix 'a':
`gcc -static main.c -L. –lmylib`

* Now executable is ready to be executed:
`./a.out`
