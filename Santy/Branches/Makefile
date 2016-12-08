cc = gcc
CFLAGS = -Wall -pedantic -g
OUTPUT = exe

all: funciones main
	$(CC) $(CFLAGS) -o $(OUTPUT) *o -lm

funciones:
	$(CC) $(CFLAGS) -c -o funciones.o funciones.c -lm

main:
	$(CC) $(CFLAGS) -c -o main.o main.c

clean:
	rm -f ./*.o
	rm -r OUTPUT

test: 
	./$(OUTPUT)
