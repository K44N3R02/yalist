CC = clang
CFLAGS = -Wall -pedantic-errors -O0 -std=c89 -pedantic -g
TARGET = yalist
SOURCES = main.c yalist.c parser.c

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(SOURCES) -o $@

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)

test: all
	./$(TARGET) > out.txt
	diff out.txt exp.txt

.PHONY: all clean run test # Declare these as phony targets

