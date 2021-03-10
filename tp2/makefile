# compilateur
CC = gcc

# options
CFLAGS = -Wall -Wextra -g
# -Wdeclaration-after-statement -Werror=vla
# LDFLAGS = -lm

# liste des fichiers objets
SRC = main.c file.c pile.c fonction.c
OBJETS = $(SRC:%.c=%.o)

prog : $(OBJETS)
	$(CC) $(OBJETS) $(LDFLAGS) -o prog

main.o: main.c file.h file.c pile.h pile.c fonction.h fonction.c
	$(CC) -c main.c $(CFLAGS)

file.o: file.h file.c
	$(CC) -c file.c $(CFLAGS)

pile.o: pile.h pile.c
	$(CC) -c pile.c $(CFLAGS)

fonction.o: fonction.h fonction.c pile.c pile.h
	$(CC) -c fonction.c $(CFLAGS)

clean:
	rm -f $(OBJETS)
