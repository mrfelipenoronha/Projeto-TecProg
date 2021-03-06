# Listing projects files. ONLY UPDATE HERE while changing stuff.
OBJECTS = parser.o scanner.o hashTable.o ListaValores.o game.o acoes.o 
HEADERS = hashTable.h Estruturas.h ListaValores.h game.h acoes.h
EXES = testador game

# Setting default compiler and flags
LOADLIBES= -lfl -lreadline
CC = gcc
CFLAGS = -Wall -g

# Compile file to test and verify the code.
testador: parser.o scanner.o testador3000.o ListaValores.o hashTable.o 
	$(CC) $(CFLAGS) testador3000.o ListaValores.o hashTable.o -o testador $(LOADLIBES)

# Compile the game itself.
game: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o game $(LOADLIBES)

parser.c : parser.y

scanner.o: scanner.l parser.c

# Compiles all objects files on demand.
%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< $(LOADLIBES)

%.c: %.y
	bison $<
	mv $*.tab.c $*.c

.PHONY: clean

# Phony clean target. Run after pushing to github.
clean:
	@rm -f all $(OBJECTS) $(EXES) testador3000.o parser.tab.h parser.c

# Use like this on terminal: make testador or make clean