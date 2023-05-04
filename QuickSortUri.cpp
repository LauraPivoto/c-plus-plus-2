#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

struct dados
{
	int codigo; // codigo do produto
	int quantidade; // quantidade em estoque
	float preco; // preco unitario
};

void quickSort(dados vetor[], int tamanho, int i, int j)
{
	dados trab;
	int esq, dir, pivo;
	esq = i;
	dir = j;
	pivo = vetor[(int)round((esq + dir) / 2.0)].codigo;
	do
	{
		while (vetor[esq].codigo < pivo)
			esq++;
		while (vetor[dir].codigo > pivo)
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

	dados vetor[100];
	int i = 0, j;
	int tamanho = 0;

	cin >> tamanho;

	for(i = 0; i < tamanho; i++)
	{
		cin >> vetor[i].codigo;
		cin >> vetor[i].quantidade;
		cin >> vetor[i].preco;
	}

	i = 0;
	j = tamanho - 1;

	quickSort(vetor, tamanho, i, j);

	for(i = 0; i < tamanho; i++)
	{
		cout << fixed << setprecision(2);
		cout << "Codigo: " << vetor[i].codigo << endl;
		cout << "Quantidade em estoque: " << vetor[i].quantidade << endl;
		cout << "Preco unitario: R$" << vetor[i].preco << endl;
		cout << endl;
	}

	return 0;
}
