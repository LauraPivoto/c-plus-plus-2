#include <iostream>

using namespace std;

struct dado //como a tabela tem dois dados por item, � preciso ser struct
{
	int k; //chave da tabela
	int status; //0: vazio, 1: ocupado, 2: removido
};

int hash_aux(int k, int m) //1 fun��o da sondagem quadr�tica -> divis�o
{
	int mod = k % m; //calcula o mod
	if((mod) < 0) //condi��o necess�ria
	{
		return (mod) + m;
	}
	else
	{
		return mod;
	}
}

int hash1(int k, int i, int m, int c1, int c2) //2 fun��o da sondagem quadr�tica
{
	int mod = (hash_aux(k, m) + c1 * i + c2 * i * i) % m; //calculo da sondagem
	return mod;
}

int hash_insert(dado t[], int m, int k, int c1, int c2)
{
	int i = 0; //contador
	do
	{
		int j = hash1(k, i, m, c1, c2); //calcula a posi��o da chave
		if (t[j].status != 1) //se ela j� n estiver ocupada
		{
			t[j].k = k; //a posi��o recebe uma chave
			t[j].status = 1; // e o status vira ocupado
			return j; //retorna a posi��o
		}
		else
		{
			i = i + 1; //tenta em outra posi��o
		}
	}
	while (i != m);

	return -1; //retorna posi��o vazia
}

int main()
{
	dado t[10]; //cria��o do struct
	int k; //chave a ser inserida
	int m; //tamanho da tabela
	int i = 0; // contador/tentativa
	int c1, c2; //inteiros para auxiliar na conta

	cin >> m; //entrar com o tamanho da tabela

	for(i = 0; i < m; i++) //inicializar a tabela
	{
		t[i].k = -1;
		t[i].status = 0;
	}

	cin >> c1 >> c2; //entrar com os auxiliares

	cin >> k; //escolher quais as chaves
	while(k != -1)
	{
		hash_insert( t, m, k, c1, c2); //inserir as chaves
		cin >> k;
	}

	for(i = 0; i < m; i++)
	{
		hash1(k, i, m, c1, c2); //fazer a sondagem e mostrar 
		cout << t[i].k << " ";
	}

	return 0;
}
