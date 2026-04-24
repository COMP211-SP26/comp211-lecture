CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c src/Parser.c src/Scanner.c src/Node.c src/Exec.c
OBJ = $(SRC:.c=.o)

TARGET = myshell

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)