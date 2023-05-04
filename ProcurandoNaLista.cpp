#include <iostream>
#include <list>

using namespace std;//Facilitar entrada e sa�da de dados

//Funl��o para procurar
bool encontrar(list<float> lista, int x)
{
	list<float>::iterator p; //interador para varrer a lista
	int tem = 0; //auxiliar para a verifica��o

	//Fazendo a verifica��o
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

	//Mandando para fun��o
	res = encontrar (lista, y);

	//Mostrando se h� o elemento
	if (res == true)
		cout << "Encontrado" << endl;
	else
		cout << "Nao encontrado" << endl;

	return 0;
}