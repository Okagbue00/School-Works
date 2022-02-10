# OKAGBUE ONYEKA FRANCIS
 # CMPT 214
 # Student No: 11279373 */




# Is to declare the target clean to be a phony rule
.PHONY: clean

# a variable that's going hold the compiler option string
#CFLAGS-- c COMPILER options to use
CFLAGS =-Wall -Wextra

# rule to build the executable program from my object files
venting: venting.o list.o list-adders.o
	gcc -o venting venting.o list.o list-adders.o

# rule to build my object files
list.o: list.c list.h
	gcc $(CFLAGS) -c list.c

list-adders.o: list-adders.c list.h
	gcc $(CFLAGS) -c listadders.c


venting.o: vents.c vents.h
	gcc $(CFLAGS) -o venting.o -c vents.c





# to remove all build targets
clean:
	rm -f *.o venting
