#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "parser.h"
#include "busca_grafo.h"



int *busca_DFS(Grafo *g, int n){
	int x = 0;
	Pilha *p = criar_pilha();
	Aresta *a;
	int i, add_p[g->tam], pos_vis = 1;
	int *v = (int*) malloc(g->tam * sizeof(int));
	for(i = 0; i < g->tam; i++){
		v[i] = add_p[i] = 0;
	}
	Nodo *ini = busca_nodo(n,g);
	while(x==0){
		a = ini->adj;
		v[ini->chave] = pos_vis;
		pos_vis++;
		while(a != NULL){
			if(add_p[a->chave_adj] == 0){
				insere_pilha(p, a->chave_adj);
				add_p[a->chave_adj] = 1;
			}
			a = a->prox;
		}
		if(p->quant == 0)	break;
		ini = busca_nodo(retira_pilha(p),g);
	}
	elimina_pilha(p);
	return v;
}

int *busca_BFS(Grafo *g, int n){
	Fila *f = criar_fila();
	Aresta *a;
	int i, add_p[g->tam], pos_vis = 1, x = 0;
	int *v = (int*) malloc(g->tam * sizeof(int));
	for(i = 0; i < g->tam; i++){
		v[i] = add_p[i] = 0;
	}
	Nodo *ini = busca_nodo(n,g);
	while(x==0){
		a = ini->adj;
		v[ini->chave] = pos_vis;
		pos_vis++;
		while(a != NULL){
			if(add_p[a->chave_adj] == 0){
				insere_fila(f, a->chave_adj);
				add_p[a->chave_adj] = 1;
			}
			a = a->prox;
		}
		if(f->quant == 0)	break;
		ini = busca_nodo(retira_fila(f),g);
	}
	elimina_fila(f);
	return v;
}

void imprime_busca(int *v, int tam){
	int i;
	printf("A solução da busca e: ");
	for(i = 0; i < tam; i++){
		printf("%d	",v[i]);
	}
	printf("\n");
}
