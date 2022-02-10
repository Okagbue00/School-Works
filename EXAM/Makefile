#OKAGBUE ONYEKA FRANCIS
#CMPT 214
#Student No: 11279373

#CFLAGS-- is the C compiler option to use


#allows to use functions that are not part of the standard C library but are posix
CPPFLAGS=-D_POSIX_C_SOURCE=200809L

# A variable to hold the C Compiler
CFLAGS= -Wall -Wextra -pedantic
OBJS=encounter.o question2.o randomindex.o statsdb.o
TARGET=question2

all: $(TARGET)
#to build the executable program
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(LDLIBS) $(LOADLIBES) -o $@ $^

#rule to remove all build targets
clean:
	$(RM) $(TARGET) $(OBJS)

#Declare the target 'clean' to be a phony rule
.PHONY: all clean
