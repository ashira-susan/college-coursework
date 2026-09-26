# BorderWatch Makefile
# Builds three separate executables from this one flat folder:
#   borderwatch  - the command center (main.c + everything it needs)
#   station      - a station simulator (station.c only)
#   response     - the IPC response process (response.c + ipc.c)

CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -pthread -lm

CENTER_SRCS = main.c server.c database.c object.c duplicate.c zones.c logger.c ipc.c

all: borderwatch station response

borderwatch: $(CENTER_SRCS)
	$(CC) $(CFLAGS) $(CENTER_SRCS) -o borderwatch $(LDFLAGS)

station: station.c
	$(CC) $(CFLAGS) station.c -o station $(LDFLAGS)

response: response.c ipc.c
	$(CC) $(CFLAGS) response.c ipc.c -o response $(LDFLAGS)

clean:
	rm -f borderwatch station response surveillance.log *.o

.PHONY: all clean
