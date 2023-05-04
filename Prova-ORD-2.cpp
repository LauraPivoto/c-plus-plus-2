#include <iostream>
#include <math.h>

using namespace std;

void quickSort(int vetor[], int tamanho, int i, int j)
{
	int trab, esq, dir, pivo;
	esq = i;
	dir = j;
	pivo = vetor[(int)round((esq + dir) / 2.0)];
	do
	{
		while (vetor[esq] < pivo)
			esq++;
		while (vetor[dir] > pivo)
			dir--;
		if (esq <= dir)
		{
			trab = vetor[esq];
			vetor[esq] = vetor[dir];
			vetor[dir] = trab;
			esq++;
			dir--;
		}
	}
	while (esq <= dir);
	
	
	if (dir - i >= 0)
		quickSort(vetor, tamanho, i, dir);
	if (j - esq >= 0)
		quickSort(vetor, tamanho, esq, j);

}

int main()
{

	int vetor[100];
	int i = 0, j;
	int tamanho = 0;
	
	cin >> vetor[i];
	while(vetor[i] != -1)
	{
		tamanho++;
		i++;
		cin >> vetor[i];
	}

	i = 0;
	j = tamanho - 1;

	quickSort(vetor, tamanho, i, j);
	
	for(i=0; i<tamanho;i++){
		cout << vetor[i] << " ";
	}

	return 0;
}
