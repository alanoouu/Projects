run: list

list:  node.o list.o main.o
	gcc -o run node.o list.o main.o

node.o:	node.c node.h
	gcc -c node.c

list.o:	list.c list.h
	gcc -c list.c

main.o:	main.c 
	gcc -c main.c

clean: 
	rm *.o
