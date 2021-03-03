# compilateur
CC = gcc

# options
CFLAGS = -Wall -Wextra -g
# -Wdeclaration-after-statement -Werror=vla
# LDFLAGS = -lm

# liste des fichiers objets
SRC = main.c file.c
OBJETS = $(SRC:%.c=%.o)

prog : $(OBJETS)
	$(CC) $(OBJETS) $(LDFLAGS) -o prog

main.o: main.c file.h file.c
	$(CC) -c main.c $(CFLAGS)

file.o: file.h file.c
	$(CC) -c file.c $(CFLAGS)

clean:
	rm -f $(OBJETS)
