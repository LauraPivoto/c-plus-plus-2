#include <iostream>
#include <math.h>

using namespace std;

int Sequencial(int vet[], int tam, int x)
{
	int i; // contadores
	int existe = 0;
	int pos;

	for(i = 0; i <= tam; i++)
	{
		if(vet[i] == x)
		{
			existe++;
			pos = i;
		}

	}
	if(existe > 0 )
	{
		return pos;
	}
	else
	{
		return -1;
	}

}

int main()
{
	int vet[10];
	int tam = 0;
	int i = 0;
	int x;

	cin >> vet[i];
	while( vet[i] != -1)
	{
		tam++;
		i++;
		cin >> vet[i];
	}

	cin >> x;

	int resultado = Sequencial(vet, tam, x);
	if(resultado != -1)
	{
		cout << x << " encontrado na posicao " << resultado << endl;
	}
	else
	{
		cout << x << " nao encontrado" << endl;
	}


}
