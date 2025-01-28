CC = g++
CFLAGS = -Wall
SRC = src/main.cpp src/shopping.cpp
OBJ = main.o shopping.o
BIN = supermarket


all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) -o $(BIN) $(SRC)

clean:
	rm -f $(BIN)
