#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

/*
 *	Anderson Madeira da Cruz 
 * 	1701570240
 * 	Laboratorio de programação II
 * */
 

Grafo *cria_grafo(){
	Grafo *g = (Grafo*) malloc(sizeof (Grafo));
	g->tam = 0;
	g->ListaNodos = NULL;
	return g;
}

Nodo *cria_nodo(int c, Nodo *p){
	Nodo *n = (Nodo*) malloc(sizeof (Nodo));
	n->chave = c;
	n->adj = NULL;
	n->prox = p;
	return n;
}

Aresta *cria_aresta(int ca, int p){
	Aresta *a = (Aresta*) malloc(sizeof (Aresta));
	a->chave_adj = ca;
	a->peso = p;
	a->prox = NULL;
	return a; 
}

Grafo *gerar_grafo(char cam[200]){
	//Variaveis
	FILE *arq;
	int x = 0, sel, num_nodos, i, pos, c_nodo, c_adj, peso;
	Grafo *g = cria_grafo();
	Nodo *n = NULL;
	Aresta *a;
	char linha[255], letra;
	/***********************************************/
	while(x == 0){
		if((arq = fopen(cam,"r")) != NULL)	break;									
		printf("Erro na leitura do arquivo ou não encontrado\n");
		printf("1-Deseja encerar o programa\n");
		printf("2-Deseja trocar o caminho\n");
		while(x == 0){
			scanf("%d",&sel);
			if(sel == 1)	{exit(1);	free(g);}
			else{
				if(sel == 2){
					printf("Digite o novo caminho do arquivo\n");
					scanf("%s",cam);
					break;
				}
				else 	printf("Valor incorreto\nDigite novamente\n");
			}
		}														
	}
	fscanf(arq,"%d\n", &num_nodos);
	for(i = num_nodos; i > 0; i--){
		n = cria_nodo(i, n);
	}
	g->ListaNodos = n;
	
	while(x == 0){									
		pos = 0;														
		while((letra = fgetc(arq)) != '\n' && letra != EOF){							
			linha[pos] = letra;											
			pos++;														
		}
		
		if(letra == EOF)	break;
		
		linha[pos] = '\0';																	
		c_nodo = atoi(strtok(linha,";"));							
		c_adj = atoi(strtok('\0',";"));								
		peso = atoi(strtok('\0',"\0"));
		
		n = busca_nodo(c_nodo, g);
		a = n->adj;
		
		if(a == NULL){
			n->adj = cria_aresta(c_adj, peso);
		}
		else{
			while(a->prox != NULL){
				a = a->prox;
			}
			a->prox = cria_aresta(c_adj, peso);
		}														
	}
	return g;
}

Nodo *busca_nodo(int c, Grafo *g){
	Nodo *n = g->ListaNodos;
	while(n->chave != c && n != NULL){
		n = n->prox;
	}
	if(n == NULL){
		printf("Nodo nao encontrado verifique seu arquivo texto\n");
		exit(1);
	}
	return(n);
}

void imprime_grafo(Grafo *g){
	Nodo *n = g->ListaNodos;
	Aresta *a = NULL;
	while(n != NULL){
		printf("%d->	",n->chave);
		a = n->adj;
		while(a != NULL){
			printf("%d-%d->	",a->chave_adj,a->peso);
			a = a->prox;
		}
		n = n->prox;
		printf("\n");
	}
}

void elimina_grafo(Grafo *g){
	Nodo *aux_n;
	Aresta *aux, *a;
	while(g->ListaNodos != NULL){
		aux_n = g->ListaNodos;
		g->ListaNodos = aux_n->prox;
		a = aux_n->adj;
		while(a != NULL){
			aux = a;
			a = a->prox;
			free(aux);
		}
		free(aux_n);
	}
	free(g);
}
