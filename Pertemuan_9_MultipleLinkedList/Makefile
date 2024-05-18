CC = gcc
CFLAGS = -Wall

build: $(TARGET)

$(TARGET): $(TARGET).c	# to build the program, you need the source code.
	$(CC) $(TARGET).c $(CFLAGS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	del $(TARGET).exe
