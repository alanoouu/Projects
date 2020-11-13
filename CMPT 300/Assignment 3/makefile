run: simulation

simulation: list.o simulation.o
	gcc -o run list.o simulation.o

list.o: list.h
	gcc -c

simulation.o: simulation.c 
	gcc -c simulation.c

clean: 
	rm simulation.o
