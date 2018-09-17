We would like to create a shared link library containing the object code of the 
sum() and mul() functions written inside mymath.c source file, which can be 
called from different C programs.

1. Compile Position Independent Code (PIC) mymath.o:
  ~~~
  gcc -c -fPIC mymath.c
  ~~~

2. Create shared link library libmymath.a from mymath.o:
  ~~~
  gcc -shared -o libmymath.so mymath.o
  ~~~

3. Static compile main.c with mylib.a as link library. 
Note that -L speciﬁes the "current directory" library path, 
-l speciﬁes the library, without prefix 'lib' and suffix 'a':
  ```gcc -static main.c -L. –lmylib```

4. Now the executable is ready to be executed:
  ```./a.out```
