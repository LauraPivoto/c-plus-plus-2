#include <iostream>
#include <list>

using namespace std;

int soma(list<int> lista){
	
	list<int>::iterator p; //iterador para varrer a lista
	int soma = 0;
	for(p = lista.begin(); p != lista.end(); p++)
	{
		soma = soma + *p;
	}
	
	return soma;
}

int main()
{
	list<int> lista; //ponteiro para lista
	list<int>::iterator p; //iterador para varrer a lista

	int x;
	cin >> x;
	while(x != 0){
		lista.push_front(x);
		cin >> x;
	}

	cout << soma(lista);
	
	return 0;
}
