#include <iostream>
#include <cstring>
#include <iomanip>
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
    
    for(int c = 0; i<= tamanho ; c++){
		cout << vetor[c];
	}
}

int main()
{
	int vetor[10];
	int i, j;

	int tamanho;
	cin >> tamanho;
	
	for(int i = 0; i < tamanho; i++)
	{
		cin >> vetor[i];
	}

	/*for(int i = 1; i <= tamanho; i++)
	{
		cin >> vetor[i].codigo;
		cin >> vetor[i].quantidade;
		cin >> vetor[i].preco;
	} */

	i = 0;
	j = tamanho - 1;

	quickSort(vetor , tamanho, i, j);

	/*for( i = 1; i <= tamanho; i++)
	{
		cout << vetor[i].codigo << endl;
		cout << vetor[i].quantidade << endl;
		cout << vetor[i].preco << endl;
	} */

	return 0;
}
