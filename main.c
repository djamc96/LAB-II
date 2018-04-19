#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "parser.h"
#include "busca_grafo.h"

/*
 *	Anderson Madeira da Cruz 
 * 	1701570240
 * 	Laboratorio de programação II
 * */
 
int main(){
	//Variaveis
	char cam[200];
	Grafo *g;
	int x = 0, sel;
	/******************************************************/
	printf("Digite o caminho e o nome do arquivo\n");
	scanf("%s",cam);
	g = gerar_grafo(cam);
	while(x == 0){
		printf("**********Grafo**********\n");
		printf("1 - imprimir grafo\n");
		printf("2 - DFS - Busca em profundidade\n");
		printf("3 - BFS - Busca em largura\n");
		printf("4 - Sair\n");
		printf("*************************\n");
		while(x == 0){
			scanf("%d",&sel);
			if(sel > 0 && sel < 5)	break;
			printf("Valor incorreto\nDigite novamente\n");
		}
		switch(sel){
			case 1:
				imprime_grafo(g);
				break;
			case 2:
				printf("Digite o nodo que deseja iniciar a DFS\n");
				scanf("%d",&sel);
				imprime_busca( busca_DFS( g, sel), g->tam);
				break;
			case 3:
				printf("Digite o nodo que deseja iniciar a BFS\n");
				scanf("%d",&sel);
				imprime_busca( busca_BFS( g, sel), g->tam);
				break;
			case 4:
				elimina_grafo(g);
				exit(1);
				break;
		}
	}
	return 0;
}
