obj-m += tcp/server.o
obj-m += tcp/client.o
obj-m += udp/server.o
obj-m += udp/client.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD  := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
