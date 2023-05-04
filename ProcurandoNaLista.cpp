#include <iostream>
#include <list>

using namespace std;//Facilitar entrada e saída de dados

//Funlção para procurar
bool encontrar(list<float> lista, int x)
{
	list<float>::iterator p; //interador para varrer a lista
	int tem = 0; //auxiliar para a verificação

	//Fazendo a verificação
	for(p = lista.begin(); p != lista.end(); p++)
	{
		if (*p == x)
			tem++;
	}
	if (tem > 0)
		return true;
	else
		return false;
}

int main()
{
	list<float> lista; //ponteiro para a lista
	list<float>::iterator p; //interador para varrer a lista
	int x; //elemento a ser inserido
	int y; //elemento a ser encontrado
	bool res;

	//Insetindo os elementos na lista
	while (x != 0)
	{
		cin >> x;
		lista.push_front(x);
	}

	//Entando com o elemento a ser encontrado
	cin >> y;

	//Mandando para função
	res = encontrar (lista, y);

	//Mostrando se há o elemento
	if (res == true)
		cout << "Encontrado" << endl;
	else
		cout << "Nao encontrado" << endl;

	return 0;
}