KERNEL_HEADER=/lib/modules/$(shell uname -r)/build
CC = gcc

TARGET := app
obj-m := nobrand.o

all : driver app

driver:
    make -C $(KERNEL_HEADER) M=$(PWD) modules

app:
    $(CC) -o $@ ./app/$@.c

clean:
    make -C $(KERNEL_HEADER) M=$(PWD) clean
    rm -f *.o $(TARGET)
	

