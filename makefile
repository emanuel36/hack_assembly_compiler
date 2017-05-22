CC = gcc
INC = -I./inc

all: folder bin 

bin: main.o instruction.o file.o 
	$(CC) obj/file.o obj/instruction.o obj/main.o -o APP/hack

file.o:
	$(CC) -o file.o -c $(INC) src/file.c -o obj/file.o	

instruction.o:
	$(CC) -o instruction.o -c $(INC) src/instruction.c -o obj/instruction.o	

main.o:
	$(CC) -o main.o -c $(INC) src/main.c -o obj/main.o

folder:
	mkdir -p obj APP

clean:
	rm -rf APP obj