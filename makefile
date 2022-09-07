GCC= gcc
CFLAGS = -Wall -Werror 
INCLUDES =

all: BatailleNavale

BatailleNavale: main.c IHM.o CORE.o IA.o
	$(GCC) $(CFLAGS) main.c IHM.o CORE.o  IA.o -o BatailleNavale  $(INCLUDES)

IHM.o:	IHM.c	IHM.h 
	$(GCC) $(CFLAGS) -c IHM.c $(INCLUDES)
	
CORE.o:	CORE.c	CORE.h
	$(GCC) $(CFLAGS) -c CORE.c $(INCLUDES)

IA.o:	IA.c	IA.h
	$(GCC) $(CFLAGS) -c IA.c $(INCLUDES)


	
clean:
	rm -f main
	rm -f *.o
