# Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = caesar_cipher
SRC = main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
