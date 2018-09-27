#obj-m += basic_module.o 
#obj-m += parametri.o
#obj-m += intercept_sc.o 
#obj-m += intercept_sc_param.o 
obj-m += nascondere_file.o

KERNELVERSION = $(shell uname -r)

all:
	$(MAKE) -C /lib/modules/$(KERNELVERSION)/build M=$(PWD) modules
clean:
	$(MAKE) -C /lib/modules/$(KERNELVERSION)/build M=$(PWD) clean
