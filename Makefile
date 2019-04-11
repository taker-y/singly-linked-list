PROGRAM = main
OBJS = main.o list.o file_reader.o
SRCS = $(OBJS:%.o=%.c)
CC = gcc
CFLASG =
LDFLAGS =

$(PROGRAM):$(OBJS)
	$(CC) $(CFLGAS) $(LDFLAGS) -o $(PROGRAM) $(OBJS) $(LDLIBS)

clean:
	rm $(OBJS) main
