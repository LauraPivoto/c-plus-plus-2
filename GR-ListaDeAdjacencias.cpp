#include <iostream>
#include <list>

using namespace std;

struct no
{
	int v; //destino
	int peso; //peso da aresta
};

void bfs(list<no>adj[], int nVertices, int s)
{
	list<no> Q[100];
	int state[100];
	int p[100];
	int u, v;
	list<no>::iterator q;

	for(u = 0; u <= nVertices; u++)
	{
		if(u != s)
		{
			state[u] = -1;
			p[u] = -1;
		}
	}
	state[s] = 0;
	p[s] = -1;
	Q.push_back(s);

	while(!Q.empty())
	{
		u = Q.front();
		Q.pop_front();
		cout << u << endl;

		for(q = adj[u].begin(); q != adj[u].end(); q++)
		{
			v = q-> v;
			cout << u << v << end;
			if(state[v] == -1)
			{
				state[v] = 0;
				p[v] = u;
				Q.push_back(v);
			}
		}
		state[u] = 1;
	}
}

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado)
{
	no aux; //var aux para inserir as arestas na lista de adjacencias

	aux.v = v; //colocando na variável auxiliar
	aux.peso = p;
	adj[u].push_back(aux);
	if(orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}
}
//Grafo ponderado tem arestas com peso

int main()
{

	list<no> adj[10]; //lista de adjacencias      vetor de ponteiros
	int Nvertices; //n de vértices
	int u, v; //origem e destino da aresta
	int p; //peso da aresta
	no aux; //var aux para inserir as arestas na lista de adjacencias
	int orientado; // 0:n 1:s

	//Lendo aresta e inserindo no grafo
	cin >> Nvertices;

	cin >> orientado;

	cin >> u >> v >> p;
	while (u != -1 && v != -1 && p != -1)
	{
		cria_aresta(adj, u, v, p, orientado);
		cin >> u >> v >> p;
	}

	//mostrando a lista de adjacencias:
	list<no>::iterator q;

	for(int i = 0; i < Nvertices; i++)
	{
		for(q = adj[i].begin(); q != adj[i].end(); q++)
			cout << i << " " << q->v << " " << q-> peso << endl;
	}

	return 0;
}
