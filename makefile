# compilateur
CC = gcc

# options
CFLAGS = -Wall -Wextra -g
# -Wdeclaration-after-statement -Werror=vla
# LDFLAGS = -lm

# liste des fichiers objets
SRC = main.c matrice.c liste.c fonction.c
OBJETS = $(SRC:%.c=%.o)

prog : $(OBJETS)
	$(CC) $(OBJETS) $(LDFLAGS) -o prog

main.o: main.c matrice.c matrice.h liste.h liste.c
	$(CC) -c main.c $(CFLAGS)

matrice.o: matrice.h matrice.c
	$(CC) -c matrice.c $(CFLAGS)

liste.o : liste.h liste.c
	$(CC) -c liste.c $(CFLAGS)

fonction.o : fonction.h fonction.c
	$(CC) -c fonction.c $(CFLAGS)

clean:
	rm -f $(OBJETS)
