CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O2 -Iheaders $(shell pkg-config --cflags MLV)
LDFLAGS = $(shell pkg-config --libs MLV)

TARGET = Tetris-like
SRCS = src/main.c src/game.c src/graphics.c src/input.c src/piece.c src/save.c src/plateau.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(TARGET)

clear: clean
