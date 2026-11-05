CC      = gcc
CFLAGS  = -Wall -Wextra -I./include -std=c11

BINDIR  = ./bin
TARGET  = $(BINDIR)/binary-search-tree
SOURCES = $(wildcard ./src/*.c)

all: $(TARGET)

$(TARGET): $(SOURCES) | $(BINDIR)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

$(BINDIR):
	mkdir -p $(BINDIR)

run: all
	./$(TARGET)

clean:
	rm -rf $(BINDIR)
