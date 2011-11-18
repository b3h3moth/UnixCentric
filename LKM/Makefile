obj-m += hello_module.o

KERNELVERSION = $(shell uname -r)

all:
	$(MAKE) -C /lib/modules/$(KERNELVERSION)/build M=$(PWD) modules
clean:
	$(MAKE) -C /lib/modules/$(KERNELVERSION)/build M=$(PWD) clean
