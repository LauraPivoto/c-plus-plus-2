#include <iostream>
using namespace std;

struct dado //como a tabela tem dois dados por item, é preciso ser struct
{
	int k;
	int status; //0: vazio, 1: ocupado, 2: removido
};

// INICIO DOUBLE HASH
int h1(int k, int m)
{
	int mod = k % m;
	if (mod < 0)
	{
		return mod + m;
	}
	else
	{
		return mod;
	}
}

int h2(int k, int m)
{
	int mod1 = 1 + (k % (m - 1));
	if (mod1 < 0)
	{
		return mod1 + m;
	}
	else
	{
		return mod1;
	}
}

int hash1(int k, int i, int m)
{
	int mod2 = (h1(k, m) + (i * h2(k, m))) % m;
	return mod2;
}
// FIM DOUBLE HASH

//Colocar dados em tabela
int hash_insert(dado t[], int m, int k)
{
	int i = 0;
	do
	{
		int j = hash1(k, i, m);
		if (t[j].status != 1)
		{
			t[j].k = k;
			t[j].status = 1;
			return j;
		}
		else
		{
			i = i + 1;
		}
	}
	while (i != m);

	return -1;
}

//Pesquisa de dados
int hash_search(dado t[], int m, int k)
{
	int i = 0;
	int j;
	do
	{
		j = hash1(k, i, m);
		if ((t[j].k == k))
		{
			return j;
		}
		i = i + 1;
	}
	while (t[j].status != 0 && i < m);
	return -1;
}

int hash_remove(dado t[], int m, int k)
{
	int j = hash_search(t, m, k);
	if(j != -1)
	{
		t[j].status = 2;
		t[j].k = -1;
		return 0; // consegui remover
	}
	else
		return -1; // k nao esta na tabela

}

int main()
{
	//OPÇÃO 1 = INSERIR, OPÇÃO 2 = PESQUISAR, OPÇÃO 3 = REMOVER, OPÇÃO 4 = LISTAR, OPÇÃO 5 = SAIR

	dado t[100];
	int escolha; //ESCOLHER ENTRE AS OPÇÕES
	int i; //TENTATIVA
	int j; //POSIÇÃO DA CHAVE
	int k; //CHAVE
	int m; //TAMANHO TABELA

	cin >> m;

	for(i = 0; i < m; i++)
	{
		t[i].k = -1;
		t[i].status = 0;
	}

	cin >> escolha;

	while(escolha != 5)
	{
		if(escolha == 1)
		{
			cin >> k;
			hash_insert(t, m, k);
		}
		else if(escolha == 2)
		{
			cin >> k;
			cout << hash_search(t, m, k) << endl;
		}
		else if(escolha == 3)
		{
			cin >> k;
			hash_remove(t, m, k);
		}
		else if(escolha == 4)
		{
			for(i = 0; i < m - 1; i++)
			{
				cout << t[i].k << " ";
			}
			cout << t[i].k << endl;
		}
		cin >> escolha;
	}



	return 0;
}
