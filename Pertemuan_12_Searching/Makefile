CC = gcc
CFLAGS = -Wall -Wextra

build: $(TARGET)

$(TARGET): src\$(TARGET).c
	$(CC) src\$(TARGET).c $(CFLAGS) -o bin\$(TARGET)

run: 
	bin\./$(TARGET)

clean:
	del $(TARGET).exe
