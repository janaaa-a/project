
# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Target executable name
TARGET = game

# Source files (.c files)
SOURCES = main.c board.c move.c validation.c saveload.c undoredo.c

# Header files (.h files)
HEADERS = board.h move.h validation.h saveload.h undoredo.h

# Object files (automatically generated from sources)
OBJECTS = $(SOURCES:.c=.o)

# Default rule - compiles the program
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files into object files
# This rule makes object files depend on headers too
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)