CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
TARGET = herms
SRCS = main.c resource.c search.c sort.c merge.c analysis.c fileio.c menu.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
