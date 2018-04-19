typedef struct aresta{
	int chave_adj;
	struct aresta *prox;
	int peso;
}Aresta;

typedef struct nodo{
	int chave;
	struct nodo *prox;
	Aresta *adj;
}Nodo;

typedef struct grafo{
	Nodo *ListaNodos;
	int tam;
}Grafo;

Grafo *cria_grafo();

Nodo *cria_nodo(int c, Nodo *p);

Aresta *cria_aresta(int ca, int p);

Grafo *gerar_grafo(char cam[200]);

Nodo *busca_nodo(int c, Grafo *g);

void imprime_grafo(Grafo *g);

void elimina_grafo(Grafo *g);

