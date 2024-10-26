CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O2 $(shell pkg-config --cflags MLV)
LDFLAGS = $(shell pkg-config --libs-only-other --libs-only-L MLV) $(shell pkg-config --libs-only-l MLV)

TARGET = tetris
SRCS = main.c game.c graphics.c input.c tetromino.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean