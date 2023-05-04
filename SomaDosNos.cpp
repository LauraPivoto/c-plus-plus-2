#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> estoque; //ponteiro para lista
	list<int> lista2; //ponteiro para lista
	list<int>::iterator p; //iterador para varrer a lista

	int tamanho;
	int x;
	cin >> tamanho;
	int i = 1;
	int y;

	while(i <= tamanho)
	{
		cin >> x;
		if(x == 1)
		{
			cin >> y;
			estoque.push_front(y);
		}
		else
		{
			estoque.pop_front();
			lista2.push_front(y);
		}
		i++;
	}

	cout << "Estoque: ";
	for(p = estoque.begin(); p != estoque.end(); p++)
	{
		cout << *p << " ";
	}
	
	cout << "Venda: ";
	for(p = estoque.begin(); p != estoque.end(); p++)
	{
		cout << *p << " ";
	}

	return 0;
}
