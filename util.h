typedef struct lista{
	int val;
	struct lista *prox;
}Lista;

Lista *criar_lista(int v, Lista *p);
/**/
typedef struct descritorPilha{
	int quant;
	Lista *topo;
}Pilha;

Pilha *criar_pilha();

void insere_pilha(Pilha *p, int v);

int retira_pilha(Pilha *p);

/**/
typedef struct fila{
	int quant;
	Lista *ini;
	Lista *fim;
}Fila;

Fila *criar_fila();

void insere_fila(Fila *f,int v);

int retira_fila(Fila *f);

void elimina_fila(Fila *f);
