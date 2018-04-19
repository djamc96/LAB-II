#include <stdio.h>
#include <stdlib.h>
#include "util.h"

Lista *criar_lista(int v,Lista *p){
	Lista *l = (Lista*) malloc(sizeof (Lista));
	if(l == NULL){
		printf("Não foi possivel criar a lista\n");
		return NULL;
	}
	l->val = v;
	l->prox = p;
	return l;
}

/***************************************************************************/

Pilha *criar_pilha(){
	Pilha *pi;
	pi = (Pilha*) malloc(sizeof(Pilha));
	if(pi == NULL){
		printf("Não foi possivel criar a pilha\n");
		return NULL;
	}
	pi->quant = 0;
	pi->topo = NULL;
	return pi;
}

void insere_pilha(Pilha *p,int v){
	p->topo = criar_lista(v,p->topo);
	p->quant++;
}

int retira_pilha(Pilha *p){
	int val;
	Lista *aux;
	if(p->quant != 0){
		aux = p->topo;
		p->topo = aux->prox;
		p->quant--;
		val = aux->val;
		free(aux);
		return val;
	}
	else	{	printf("pilha vazia\n");	return 0;}
}

void elimina_pilha(Pilha *p){
	Lista *aux = p->topo, *aux2;
	while(aux != NULL){
		aux2 = aux->prox;
		free(aux);
		aux = aux2;
	}
	free(p);
}

/*****************************************************************/

Fila *criar_fila(){
	Fila *f = (Fila*) malloc(sizeof(Fila));
	if(f == NULL){
		printf("Não foi possivel criar a fila\n");
		return NULL;
	}
	f->fim = f->ini = NULL;
	f->quant = 0;
	return f;
}

void insere_fila(Fila *f,int v){
	if(f == NULL) 	return;
	Lista *aux = criar_lista(v,NULL);
	if(f->quant == 0){
		f->ini = f->fim = aux;
	}
	else{
		f->fim->prox = aux;
		f->fim = aux;
	}
	f->quant++;
}

int retira_fila(Fila *f){
	int v;
	Lista *aux = f->ini;
	if(f->quant == 0){
		printf("Fila Vazia\n");
		return 0;
	}
	f->ini = aux->prox;
	v = aux->val;
	if(f->ini == NULL) f->fim = NULL;
	free(aux);
	return v;
}

void elimina_fila(Fila *f){
	Lista *l = f->ini;
	Lista *aux;
	while(l != NULL){
		aux = l->prox;
		free(l);
		l = aux;
	}
	free(f);
}
