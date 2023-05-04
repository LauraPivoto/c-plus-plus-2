#include <iostream>
#include <list>
#include<climits>

using namespace std;

struct no
{
	int v; // vertice de destino da aresta
	int peso; // peso da aresta
};

void prim(list<no>adj[], int nVertices, int start){
	
	list<no>::iterator p; // iterador para varrer a lista de adjacências
	bool intree[100];
	int parent[100];
	int distance[100];
	int v, u;
	int peso, destino, weight;
	int dist;
	
	for(u = 0; u <= nVertices; u++){
		intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
	}
    distance[start] = 0;
    v = start;
    while(intree[v] == false){
		intree[v] = true;
        for(p = adj[v].begin(); p != adj[v].end();p++){
			destino = p->v;
            weight = p->peso;
            if(distance[destino] > weight && intree[destino]==false){
				 distance[destino] = weight;
                parent[destino] = v;
			}
		}
        v = 0;
        dist = INT_MAX;
        for(u = 0 ; u <= nVertices; u++){
			
            if(intree[u]==false && dist>distance[u]){
				dist = distance[u];
                v = u;
			}
		}
	}
       
}

//Função que implementa  o recurso de largura 
/*
void bfs(list<no>adj[], int nVertices, int s)
{
	int state[100];
    int p[100];
    list<int> Q;
    int u,v; // vars aux para mostrar os vértices
    list<no>::iterator q; // iterador para varrer a lista de adjacências
    
	
	for(u=0; u<nVertices; u++)
	{
		if (u!= s)
		{
			state[u]= -1;//undiscovered
			p[u]=-1;	
		}
		
	}
	state[s]=0;//discovered
	p[s]=-1;
	Q.push_back(s);
	
	while (!Q.empty())
	{
		u=Q.front();
		Q.pop_front();
		cout<<u<<endl;
		for(q = adj[u].begin(); q != adj[u].end(); q++ )
		{
			v=q->v;
			cout<<u<<" "<<v<<endl;
			if (state[v]==-1)
			{
				state[v]=0;//discovered
				p[v]=u;
				Q.push_back(v);
			}
		}
		state[u]=1;//processed
		
	}
	
} */

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

int main()
{
	list<no> adj[10]; // lista de adjacências
	int nVertices; // numero de vértices do grafo
	int u, v; // vértices de origem e destino de uma aresta
	int p; // peso da aresta
	list<no>::iterator q; // iterador para varrer a lista de adjacências
	int orientado=0; //0: Não orientado, 1: orientado
	int s;//estado 
	int start;
	
	// Lendo numero de vertices do grafo
	cin >> nVertices;
	
	
	cin >> orientado;

	//Lendo o vértice inicial
	cin >> start; 

	// Lendo aresta e mandando para a função
	cin >> u >> v >> p;
	while (u != -1 && v != -1 && p != -1)
	{
		cria_aresta(adj, u, v, p, orientado);
		cin >> u >> v >> p;
	}
	
	//bfs(adj,nVertices,s);
	
	//int G = nVertices;
	//int start = s;
	
	prim(adj, nVertices, start);
	
	return 0;
}
