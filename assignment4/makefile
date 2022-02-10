




.PHONY: clean

CFLAGS = -Wall -Wextra

venting: venting.o list.o list-adders.o
	gcc -o venting venting.o list.o list-adders.o

list.o: list.c list.h
	gcc $(CFLAGS) -c list.c

list-adders.o: list-adders.c list.h
	gcc $(CFLAGS) -c listadders.c


venting.o: vents.c vents.h
	gcc $(CFLAGS) -o venting.o -c vents.c






clean:
	rm -f *.o venting
