#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> pilha; // ponteiro para a fila
	int x; // var aux para leitura dos dados
	// Ler dados e inserir na fila
	
	int y;
	
	cin >> y;
	fila.push_front(y);
	cin >> y;
	fila.push_front(y);
	cin >> y;
	fila.push_front(y);
	cin >> y;
	fila.push_front(y);
	
	// Remover os dados da fila e ir mostrando
	while(!fila.empty())
	{
		x = *fila.begin();
		cout << x << " ";
		fila.pop_front();
	}
	return 0;
}
