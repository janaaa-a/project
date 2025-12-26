CC = gcc

CFLAGS = -Wall -g

TARGET = game

SOURCES = main.c board.c move.c validation.c saveload.c undoredo.c

HEADERS = board.h move.h validation.h saveload.h undoredo.h

OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)