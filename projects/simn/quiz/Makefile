CC      = gcc
CFLAGS  = -g
RM      = rm -f


default: all

all: run

testme: testme.c
	$(CC) $(CFLAGS) -o testme testme.c

run: testme
	./testme

clean veryclean:
	$(RM) testme