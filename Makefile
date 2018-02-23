arvore_TARGET = ./arvore
matriz_TARGET = ./matriz
 
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -O2 -g

CLEAN = rm *.o
 
.PHONY: default all clean
 
default: $(arvore_TARGET) $(matriz_TARGET)
all: default
 
arvore_OBJECTS = $(patsubst %.c, %.o, arvore.c mainA.c)
arvore_HEADERS = $(T.h arvore.h)
 
matriz_OBJECTS = $(patsubst %.c, %.o, matriz.c mainM.c)
matriz_HEADERS = $(T.h matriz.h)
 
%.o: %.c $(arvore_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
   
%.o: %.c $(matriz_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
     
.PRECIOUS: $(arvore_TARGET) $(arvore_OBJECTS) $(matriz_TARGET) $(matriz_OBJECTS)
 
$(arvore_TARGET): $(arvore_OBJECTS)
	$(CC) $(arvore_OBJECTS) -o $@
     
$(matriz_TARGET): $(matriz_OBJECTS)
	$(CC) $(matriz_OBJECTS) -o $@
     
clean:
	$(CLEAN)
