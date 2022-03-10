SRC = src
BIN = bin
TARGET = main
LIBS = -lm

SOURCE = $(wildcard $(SRC)/*.c)
OBJECT = $(patsubst %, $(BIN)/%, $(notdir $(SOURCE:.c=.o))) 

$(BIN)/%.o : $(SRC)/%.c 
	mkdir -p $(@D)
	gcc -g -Wall -c $< -o $@

$(BIN)/$(TARGET) : $(OBJECT)
	gcc -o $@ $^ $(LIBS)

run :
	bin/./main

clean :
	rm -r bin
	rm -f main
