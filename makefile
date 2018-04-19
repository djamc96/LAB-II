index:
	gcc -Wall -c util.c -o util.o
	gcc -Wall -c parser.c -o parser.o 
	gcc -Wall -c busca_grafo.c util.o -o busca_grafo.o
	gcc -Wall main.c parser.o busca_grafo.o -o exec   
	./exec
