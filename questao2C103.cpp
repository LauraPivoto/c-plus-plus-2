//Conjunto de arestas que mantém o grafo conexo e a soma dos pesos é mínima
#include <iostream>
#include <list>
#include <climits>

using namespace std;

struct no
{
	int v; 
	float peso; // peso da aresta
};

//Função para criar as arestas
void cria_aresta(list<no>adj[], int u, int v, int p, int orientado)
{
	no aux; // var aux para inserir as arestas na lista de adjacências

	aux.v = v;
	aux.peso = p;
	adj[u].push_back(aux);
	if (orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}

}

void prim(list<no>adj[], int ncomp, int start)
{

	list<no>::iterator q; // iterador para varrer a lista de adjacências
	bool intree[100];
	int parent[100]; 
	float distance[100];
	int v, u;
	float peso;
	int destino;
	float weight;
	int dist;
	float soma = 0;

	for(u = 0; u <= ncomp; u++)
	{
		intree[u] = false;
		distance[u] = INT_MAX;
		parent[u] = -1; // sem pai
	}

	distance[start] = 0;
	v = start;

	while(intree[v] == false)
	{
		intree[v] = true;

		for(q = adj[v].begin(); q != adj[v].end(); q++)
		{ 
			destino = q-> v; 
			weight = q-> peso;
			if(distance[destino] > weight && intree[destino] == false)
			{
				distance[destino] = weight; 
				parent[destino] = v; 
			}
		}

		v = 0; 
		dist = INT_MAX;
		for(u = 0 ; u < ncomp; u++)
		{

			if(intree[u] == false && dist > distance[u])
			{
				dist = distance[u];
				v = u;
			}
		}
	}
	cout << "Ligacoes: "<< endl;
	for(u = 1; u < ncomp; u++)
	{
		cout << parent[u] << " " << u << endl;
		soma = soma + distance[u];
	}
	cout << "Custo Total: " << soma << " m " << endl;
}

int main()
{
	list<no> adj[10]; // lista de adjacências
	int ncomp; // numero de vértices do grafo
	int u, v; // vértices de origem e destino de uma aresta
	float p; // comprimento de cabo
	list<no>::iterator q; // iterador para varrer a lista de adjacências
	int orientado = 1; //0: Não orientado, 1: orientado
	int start;

	// Lendo numero de pcs do grafo
	cin >> ncomp;

	//Lendo o vértice inicial
	cin >> start;

	// Lendo aresta e mandando para a função
	cin >> u >> v >> p;
	while (u != -1 && v != -1 && p != -1)
	{
		cria_aresta(adj, u, v, p, orientado);
		cin >> u >> v >> p;
	}

	prim(adj, ncomp, start);

	return 0;
}