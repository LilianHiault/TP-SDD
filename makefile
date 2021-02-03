# compilateur
CC = gcc

# options
CFLAGS = -Wall -Wextra -g
# -Wdeclaration-after-statement -Werror=vla
# LDFLAGS = -lm

# liste des fichiers objets
SRC = main.c matrice.c
OBJETS = $(SRC:%.c=%.o)

prog : $(OBJETS)
	$(CC) $(OBJETS) $(LDFLAGS) -o prog

main.o: main.c matrice.c matrice.h
	$(CC) -c main.c $(CFLAGS)

matrice.o: matrice.h matrice.c
	$(CC) -c matrice.c $(CFLAGS)

clean:
	rm -f $(OBJETS)
