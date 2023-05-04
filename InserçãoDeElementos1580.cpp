#include <iostream>

using namespace std;

struct dado
{
	int k;
	int status;
};

int hash1(int k, int i, int m)
{
	int mod = (k + i) % m;
	return mod;
}

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

int hash_search(dado t[], int m, int k)
{
	int i = 0;
	int j =0;
	do
	{
		j = hash1(k, i, m);
		if (t[j].k = k){
			return j;
		}
		i = i + 1;
	}
	while ((t[j].status!=0) && i < m);
	return -1;
}

int main()
{
	dado t[50];
	int k, m;
	int i = 0; //tentativa
	int j =0;

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
	int p = hash_search(t,  m, k);
	
	if(p == 0){
		cout << "Chave" << k << "nao encontrada" << endl;
	}else{
		cout << "Chave encontrada na posicao" << p << endl;
	}


}
