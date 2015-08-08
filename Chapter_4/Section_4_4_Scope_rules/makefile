CC=gcc
CFLAG= -g -Wall -O3
OBJ=getch.o getop.o main.o stack.o
DEPS=calc.h

%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAG)

polish:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *~ *.swp *.o
