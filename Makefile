CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJS = main.o fs.o shell.o mm.o proc.o history.o utils.o
MiniOS: $(OBJS)
	$(CC) $(CFLAGS) -o MiniOS $(OBJS)

main.o: main.c fs.h shell.h mm.h proc.h
	$(CC) $(CFLAGS) -c main.c

fs.o: fs.c fs.h
	$(CC) $(CFLAGS) -c fs.c

shell.o: shell.c shell.h fs.h
	$(CC) $(CFLAGS) -c shell.c

mm.o: mm.c mm.h
	$(CC) $(CFLAGS) -c mm.c

proc.o: proc.c proc.h
	$(CC) $(CFLAGS) -c proc.c

clean:
	rm -f *.o MiniOS

history.o: history.c history.h
	$(CC) $(CFLAGS) -c history.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c