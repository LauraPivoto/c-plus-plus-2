#include<iostream>
#include<list>
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
		if(vetor[i] != vetor[i-1])
		cout << vetor[i] << " " ;
	}
}

int main()
{
	list<int> lista1; // ponteiro para a fila
	list<int> lista2;
	int x; // var aux para leitura dos dados
	int y;
	int p;

	cin >> x;
	while(x != 0)
	{
		lista1.push_back(x);
		cin >> x;
	}

	cin >> y;
	while(y != 0)
	{
		lista2.push_back(y);
		cin >> y;
	}

	int vetor[100];
	int i = 0;

	while(!lista1.empty())
	{
		p = *lista1.begin();
		vetor[i] = p;
		lista1.pop_front();
		i++;
	}

	while(!lista2.empty())
	{
		p = *lista2.begin();
		vetor[i] = p;
		lista2.pop_front();
		i++;
	}
	
	int tamanho = i;
	
	bubbleSort(vetor, tamanho);

	return 0;
}
