#
# Makefile
#
CC=gcc
LINK_OPTIONS=-L/usr/X11R6/lib -lX11 -lm
COMP_OPTIONS=-I/usr/X11R6/include -c

#
# definition des dependances pour le programme
#
OBJ=main.o window.o pong.o
SOURCE=main.c window.c pong.c
PROG_NAME=pong

all: $(PROG_NAME)

# compilation du programme
main.o : main.c
	$(CC) main.c $(COMP_OPTIONS)

window.o : window.c window.h
	$(CC) window.c $(COMP_OPTIONS)

pong.o : pong.c pong.h
	$(CC) pong.c $(COMP_OPTIONS)


$(PROG_NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(PROG_NAME) $(LINK_OPTIONS)


