# Articles

* [The C Programming Language](#headAR1)
  - [Memory Management](#headAR1a)
  - [Structures and Unions](#headAR1b)
* [Unix Programming](#headAR2)
* [Kernel and Device Drivers](#headAR3)
* [Compiling and Linking](#headAR4)
* [Unix stuff](#headAR5)

---

## <a name="headAR1"></a>The C Programming Language

* [Undefined Behavior in 2017](https://blog.regehr.org/archives/1520) `07/04/2017 - Pascal Cuoq, John Regehr`
* [Yes C is unsafe, but…](https://daniel.haxx.se/blog/2017/03/30/yes-c-is-unsafe-but/) `03/30/2017, Daniel Stenberg`
* [curl is C](https://daniel.haxx.se/blog/2017/03/27/curl-is-c/) `03/27/2017, Daniel Stenberg`
* [A critique of "How to C in 2016"](https://github.com/Keith-S-Thompson/how-to-c-response) `1/15/2016, Keith Thompson`
* [How to C in 2016](https://matt.sh/howto-c) `2016, Matt Stancliff`
* [Write a Shell in C](https://brennan.io/2015/01/16/write-a-shell-in-c/) `1/16/2015, Stephen Brennan`
* [Guide to Advanced Programming in C](http://pfacka.binaryparadise.com/articles/guide-to-advanced-programming-in-C.html) `01/06/2014 - Peter Facka`
* What Every C Programmer Should Know About Undefined Behavior
    - [part 1](http://blog.llvm.org/2011/05/what-every-c-programmer-should-know.html) `05/13/2011 - Chris Lattner`
    - [part 2](http://blog.llvm.org/2011/05/what-every-c-programmer-should-know_14.html) `05/14/2011 - Chris Lattner`
    - [part 3](http://blog.llvm.org/2011/05/what-every-c-programmer-should-know_21.html) `05/21/2011 - Chris Lattner`

### <a name="headAR1a"></a>Memory Management

* [Write a simple memory allocator](https://arjunsreedharan.org/post/148675821737/write-a-simple-memory-allocator) `08/09/2016 - Arjun Sreedharan`
* [What a C programmer should know about memory](http://marek.vavrusa.com/memory/) `2/20/2015, Marek Vavrusa`
* [A quick tutorial on implementing and debugging malloc, free, calloc, and realloc](https://danluu.com/malloc-tutorial/) `Dec 2014, Dan Luu`
* [Memory management in C programs](http://nethack4.org/blog/memory.html) `03/16/2014, Alex Smith`
* ![pdf doc](./img/pdf_doc.png?raw=true) [A Malloc Tutorial*](http://www.inf.udec.cl/~leo/Malloc_tutorial.pdf) `2/16/2009, Marwan Burelle`
* [Anatomy of a Program in Memory](https://manybutfinite.com/post/anatomy-of-a-program-in-memory/) `01/27/2009 - Gustavo Duarte`
* What every programmer should know about memory
  - [part 1](https://lwn.net/Articles/250967/) `09/27/2007 - Ulrich Drepper`
  - [part 2, CPU Caches](https://lwn.net/Articles/252125/) `10/01/2007 - Ulrich Drepper`
  - [part 3, Virtual memory](https://lwn.net/Articles/253361/) `10/09/2007 - Ulrich Drepper`
  - [part 4, NUMA support](https://lwn.net/Articles/254445/) `10/17/2007 - Ulrich Drepper`
  - [part 5, What programmers can do - cache optimization](https://lwn.net/Articles/255364/) `10/23/2007 - Ulrich Drepper`
  - [part 6, More things programmers can do](https://lwn.net/Articles/256433/) `10/31/2007 - Ulrich Drepper`
  - [part 7, Memory performance tools](https://lwn.net/Articles/257209/) `11/07/2007 - Ulrich Drepper`
  - [part 8, Future technologies](https://lwn.net/Articles/258154/) `11/14/2007 - Ulrich Drepper`
  - [part 9, Appendices and bibliography](https://lwn.net/Articles/258188/) `11/14/2007 - Ulrich Drepper`
* [Inside memory management](https://www.ibm.com/developerworks/linux/library/l-memory/) `11/16/2004 - Jonathan Bartlett`

### <a name="headAR1b"></a>Structures and Unions

* [The Lost Art of C Structure Packing](https://www.catb.org/esr/structure-packing/) `last update: 06/01/2017 - Eric S.Raymond`

## <a name="headAR2"></a>Unix Programming

* [The real power of Linux executables](https://ownyourbits.com/2018/05/23/the-real-power-of-linux-executables/) `05/23/2018 -  nachoparker`
* [How is GNU `yes` so fast?](https://www.reddit.com/r/unix/comments/6gxduc/how_is_gnu_yes_so_fast/) `06/13/2017, reddit unix`
* Writing a Linux Debugger
  - [part 1, Setup](https://blog.tartanllama.xyz/writing-a-linux-debugger-setup/) `03/21/2017 - Simon Brand`
  - [part 2, Breakpoints](https://blog.tartanllama.xyz/writing-a-linux-debugger-breakpoints/) `03/24/2017 - Simon Brand`
  - [part 3, Registers and memory](https://blog.tartanllama.xyz/writing-a-linux-debugger-registers/) `02/31/2017 - Simon Brand`
  - [part 4, Elves and dwarves](https://blog.tartanllama.xyz/writing-a-linux-debugger-elf-dwarf/) `04/05/2017 - Simon Brand`
  - [part 5, Source and signals](https://blog.tartanllama.xyz/writing-a-linux-debugger-source-signal/) `04/24/2017 - Simon Brand`
  - [part 6, Source-level stepping](https://blog.tartanllama.xyz/writing-a-linux-debugger-dwarf-step/) `05/06/2017 - Simon Brand`
  - [part 7, Source-level breakpoints](https://blog.tartanllama.xyz/writing-a-linux-debugger-source-break/) `06/19/2017 - Simon Brand`
  - [part 8, Stack unwinding](https://blog.tartanllama.xyz/writing-a-linux-debugger-unwinding/) `06/24/2017 - Simon Brand`
  - [part 9, Handling variables](https://blog.tartanllama.xyz/writing-a-linux-debugger-variables/) `07/26/2017 - Simon Brand`
  - [part 10, Advanced topics](https://blog.tartanllama.xyz/writing-a-linux-debugger-advanced-topics/) `08/01/2017 - Simon Brand`
* [UNIX Syscalls](https://john-millikin.com/unix-syscalls) `2017 - John Millikin`
* Anatomy of a system call 
  - [part 1](https://lwn.net/Articles/604287/) `07/09/2014 - David Drysdale`
  - [part 2](https://lwn.net/Articles/604515/) `07/16/2014 - David Drysdale`

## <a name="headAR3"></a>Kernel hacking

* Linux Device Drivers (series)
  - [part 1, Introduction](https://embetronicx.com/tutorials/linux/device-drivers/linux-device-driver-part-1-introduction/) `2018 - embetronicx`
  - [part 2, First Device Driver](https://embetronicx.com/tutorials/linux/device-drivers/linux-device-driver-tutorial-part-2-first-device-driver/) `2018 - embetronicx`
  - [part 3, Module Parameter](https://embetronicx.com/tutorials/linux/device-drivers/linux-device-driver-tutorial-part-3-passing-arguments-to-device-driver/) `2018 - embetronicx`
  - [part 4, Character Device Driver](https://embetronicx.com/tutorials/linux/device-drivers/character-device-driver-major-number-and-minor-number/) `2018 - embetronicx`
  - [part 5, Device File Creation](https://embetronicx.com/tutorials/linux/device-drivers/device-file-creation-for-character-drivers/) `2018 - embetronicx`
  - [part 6, Cdev structure and File Operations](https://embetronicx.com/tutorials/linux/device-drivers/cdev-structure-and-file-operations-of-character-drivers/) `2018 - embetronicx`
  - [part 7, Linux Device Driver Tutorial Programming](https://embetronicx.com/tutorials/linux/device-drivers/linux-device-driver-tutorial-programming/) `2018 - embetronicx`

## <a name="headAR4"></a>Compiling and linking

* [Creating a shared and static library with the gnu compiler (gcc)](https://renenyffenegger.ch/notes/development/languages/C-C-plus-plus/GCC/create-libraries/index) `01/27/2018 - Rene Nyffenegger`
* [Linux Internals ~ Dynamic Linking Wizardry](https://0x00sec.org/t/linux-internals-dynamic-linking-wizardry/1082) `09/15/2016 - _py (0x00sec.org)`
* [Position Independent Code and x86-64 libraries](https://www.technovelty.org/c/position-independent-code-and-x86-64-libraries.html) `01/05/2013 - Ian Wienand`
* [Beginner's Guide to Linkers](http://www.lurklurk.org/linkers/linkers.html) `2010 - David Drysdale`
* [Static, Shared Dynamic and Loadable Linux Libraries](http://www.yolinux.com/TUTORIALS/LibraryArchives-StaticAndDynamic.html) `YoLinux`

## <a name="headAR5"></a>Unix stuff

* [Back To The Future: Unix Wildcards Gone Wild](https://www.exploit-db.com/papers/33930/) `last updated 06/25/2014 - Leon Juranic`
