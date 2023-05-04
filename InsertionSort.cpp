#include <iostream>

using namespace std;

void bubbleSort(int vetor[], int tamanho)
{
	int i, j; // contadores
	int trab;
	bool troca;
	int limite;
	troca = true;
	limite = tamanho - 1;
	while (troca)
	{
		troca = false;
		for (i = 0; i < limite; i++)
			if (vetor[i] > vetor[i + 1])
			{
				trab = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = trab;
				j = i;
				troca = true;
			}
		limite = j;
	}
	
	for(int i =0; i<= tamanho-1 ; i++){
		cout << vetor[i] << " " ;
	}
}

int main()
{
	int vetor[100];
	int i = 0;
	int tamanho = 0;

	cin >> vetor[i];
	while( vetor[i] != 0)
	{
		i++;
		tamanho++;
		cin >> vetor[i];
	}

	bubbleSort(vetor, tamanho);

	return 0;
}
