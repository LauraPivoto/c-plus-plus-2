#include <iostream>
#include <list>
using namespace std;
struct no
{
	int v; // Vertice de destino
	int peso; // Peso da aresta
};

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado)
{
	no aux; // var aux de insercao
	aux.v = v;
	aux.peso = p;
	adj[u].push_back(aux);
	if(!orientado)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}
}

int main()
{
	list<no> adj[10]; // lista de adjacencias
	int nVertices; // No de vercices do grafo
	int u, v; // vertices de origem e destino
	int p; // peso da aresta
	no aux; // var aux de insercao
	int i; // contador
	list<no>::iterator q; // iterador p/ varrer lista adjc.
	// Ler No de vertices
	cin >> nVertices;
	bool orientado = false;

// Ler aresta e inserir no grafo
	for(i = 0; i < nVertices; i++)
	{
		cin >> u >> v >> p;
		cria_aresta(adj,u,v,p,orientado);
	}
	

// Mostrar lista de adjc. p/ cada nó
	for(i = 0; i < nVertices; i++)
		for(q = adj[i].begin(); q != adj[i].end(); q++)
			cout << i << " " << q->v << " (" << q-> peso << ")" << endl;

	return 0;
}
