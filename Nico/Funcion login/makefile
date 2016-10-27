CC = gcc
CFLAGS = -g -c
LDFLAGS = -g -lm
OBJS = main.c funcion.c
ejecutable : $(OBJS)
	$(CC) $(LDLAGS) $(OBJS) -o $@ -Wall
clean:
	rm -f ./*.o
	rm -r ejecutable
new : clean ejecutable
svn:
	svn add *.c
	svn add *.h
	svn add Makefile
	svn add Doxygen
	svn ci -m "Commit de una nueva versión"
