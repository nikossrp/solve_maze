CC = gcc
CFLAGS = -g -Wall -Werror
OBJS = main.o List.o Stack.o
EXEC = main

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC) $(OBJS)