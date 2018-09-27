## LKM Loadable Kernel Module - Kernel Linux

Compile	modules
```
$ make
```

Insert a module into the Linux Kernel
```
$ sudo insmod <modulo.ko>
```

Add modules from the linux Kernel
```
$ sudo modprobe <modulo>
```

Open Kernel log
```
$ dmesg (made with KERN_ALERT)
$ cat /var/log/messages (made with KERN_INFO)
```

Show information about a Linux Kernel module
```
$ modinfo <module.ko>
```

Show active modules
```
$ cat /proc/modules
$ lsmod (as the previous command but formatted)
```

Show available modules 
```
$ sudo modprobe -l (*.ko)
```

remove module
```
$ sudo rmmod <module.ko | module>
```
