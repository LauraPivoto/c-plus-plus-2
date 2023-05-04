#include <iostream>

using namespace std;
//Criação do struct
struct dado
{
	int k;
	int status; // 0 - vazio, 1 - ocupado, 2 - removido
};
//Resultado do mod
int hash1(int k, int i, int m)
{
	int mod = (k + i) % m;
	return mod;
}
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
	int j = 0;
	do
	{
		j = hash1(k, i, m);
		if ((t[j].k == k))
		{
			return j;
		}
		i = i + 1;
	}
	while (t[j].status!=0 && i<m);
	return -1;
}

int hash_remove(dado t[], int m, int k){
	int j = hash_search(t,m,k);
    if(j != -1){
       t[j].status = 2;
       t[j].k = -1;
       return 0; // consegui remover
	}else
       return -1; // k nao esta na tabela
	
}

int main()
{
	dado t[20];
	int k, m;
	int i = 0; //tentativa
	int j;

	cin >> m;

	for(i = 0 ; i < m ; i++)
	{
		t[i].k = -1;
		t[i].status = 0;
	}

	cin >> k;

	while(k != 0)
	{
		hash_insert(t, m, k);
		cin >> k;
	}

	cin >> k;
	int p = hash_remove(t,  m, k);

	for(i = 0 ; i < m ; i++)
	{
		cout << t[i].k << " ";
	}

	return 0;
}
