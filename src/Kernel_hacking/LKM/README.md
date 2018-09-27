## LKM Loadable Kernel Module - Kernel Linux

compile	modulules
$ make

carica modulo
$ sudo insmod <modulo.ko>

carica quei moduli disponibili mediante il comando modprobe -l, ossia
disponibili dopo la fase di compilazione del kernel, e marcati con <M>
$ sudo modprobe <modulo>

log kernel
$ dmesg (tipicamente realizzati con KERN_ALERT)
$ cat /var/log/messages (tipicamente realizzati con KERN_INFO)

info modulo
$ modinfo <modulo.ko>

lista moduli attivi
$ cat /proc/modules
$ lsmod (il comando precedente ma formattato)

lista di quei moduli disponibili dopo la fase di compilazione del kernel
$ sudo modprobe -l (*.ko)

rimuove modulo
$ sudo rmmod <modulo.ko | modulo>
