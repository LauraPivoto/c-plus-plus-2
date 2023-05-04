#include<iostream>
#include<list>

using namespace std;
int main()
{
	list<int> estoque; // ponteiro para a fila
	list<int> venda;
	int N, x; // var aux para leitura dos dados
	int y;

	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> y;
		if(y == 1)
		{
			cin >> x;
			estoque.push_back(x);
		}
		else if(y == 2)
		{
			int p = *estoque.begin();
			venda.push_front(p);
			estoque.pop_front();
		}
	}

	cout << "Estoque: ";	
	while(!estoque.empty())
	{
		x = *estoque.begin();
		cout << x << " ";
		estoque.pop_front();
		cout << endl;
	}
	
	cout << "Venda: " << " ";
	while(!venda.empty())
	{
		x = *venda.begin();
		cout << x << " ";
		venda.pop_front();
	} 
	return 0;
}
