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
carica quei moduli disponibili mediante il comando modprobe -l, ossia
disponibili dopo la fase di compilazione del kernel, e marcati con <M>
```
$ sudo modprobe <modulo>
```

Open Kernel log
```
$ dmesg (tipicamente realizzati con KERN_ALERT)
$ cat /var/log/messages (tipicamente realizzati con KERN_INFO)
```

Show information about a Linux Kernel module
$ modinfo <modulo.ko>

lista moduli attivi
$ cat /proc/modules
$ lsmod (il comando precedente ma formattato)

lista di quei moduli disponibili dopo la fase di compilazione del kernel
$ sudo modprobe -l (*.ko)

rimuove modulo
$ sudo rmmod <modulo.ko | modulo>
