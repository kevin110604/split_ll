
EXEC = main
SRC = main.c cirll.c
OBJ = main.o cirll.o

CC = gcc
CFLAGS = -std=c99

all: $(EXEC)


$(EXEC): $(OBJ) 
	@echo building binary...
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	@echo building object...
	$(CC) $(CFLAGS) -o $@ -c $<

test: $(EXEC)
	@echo running tests...
	@./$(EXEC)

clean:
	@echo cleaning...
	@rm $(OBJ)
	@rm $(EXEC)
