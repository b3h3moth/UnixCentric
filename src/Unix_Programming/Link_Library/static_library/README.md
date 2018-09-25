## Static Library

We would like to create a link library containing the object code of the sum()
and mul() functions written inside mymath.c source file, which can be called 
from different C programs.

> GNU/Linux systems, by convention, expect that the name of a static library has 
> the prefix `lib` and file extension `.a`.

1. We produce the file object mymath.o:
  ```$ gcc -c mymath.c```

2. Create static link library from mymath.o:
  ```$ ar rcs libmylib.a mymath.o```

3. Static compile main.c with mylib.a as link library. 
Note that -L speciﬁes the "current directory" library path, 
-l speciﬁes the library, without prefix 'lib' and suffix 'a':
  ```$ gcc -static main.c -L. –lmylib```

4. Now executable is ready to be executed:
  ```$ ./a.out```

### Display contents of the archive

```
$ ar -t libmylib.a
mymath.o
```

### Converting static library to dynamic library

```
$ ar -x libmylib.a
```

The full collection of the object files is extracted from static library, now
we can build [dynamic library](../dynamic_library/).
