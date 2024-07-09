CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = sort

all: $(TARGET)

$(TARGET): $(TARGET).o
$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o

$(TARGET).o: $(TARGET).c
$(CC) $(CFLAGS) -c $(TARGET).c

clean:
rm -f $(TARGET) $(TARGET).o

valgrind: $(TARGET)
valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)