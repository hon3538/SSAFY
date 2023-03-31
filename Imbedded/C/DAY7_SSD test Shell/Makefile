all: main.o write.o read.o
    gcc -o ssd main.o write.o read.o
    rm *.o
main.o : main.c header.h
    gcc -c main.c
write.o: write.c header.h
    gcc -c write.c
read.o: read.c header.h
    gcc -c read.c



create : createSSD.o
    touch nand.txt
    gcc -o create createSSD.o
    rm createSSD.o
createSSD.o :
    gcc -c createSSD.c 
clear:
    rm nand.txt
