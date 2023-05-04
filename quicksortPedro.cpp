#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


void quickSort(int vetor[], int tamanho, int i, int j)
{
	int esq, dir, pivo;
	int trab;
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
	{
		quickSort(vetor, tamanho, i, dir);

	}
	if (j - esq >= 0)
	{
		quickSort(vetor, tamanho, esq, j);

	}
}


int main()
{
    
    int vetor[10];
	int n;
	int i;
	int x;

	cin >> x;
	i = 0 ;
	while(x != -1)
	{
		vetor[i] = x;
		i ++;
		cin >> x;
	}
	n = i;

	quickSort(vetor, n, 0,  n-1);
	
	for(i = 0; i < n; i++)
	{
		cout << vetor[i] << " ";
		
	}
  cout << endl;
	return 0;
}
