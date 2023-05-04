#include <iostream>

using namespace std;

struct dado{
	int k;
	int status;	
};

int hash1(int k, int i, int m)
{
	int mod = (k + i) % m;
	return mod;
}

int hash_insert(dado T[], int m, int k)
{
	int i = 0;
	do
	{
		int j = hash1(k, i, m);
		if (T[j].status != 1)
		{
			T[j].k = k;
			T[j].status = 1;
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

int main()
{
	dado T[20];
	int k, m;
	int i = 0; //tentativa
	
	for(i=0 ; i < m ; i++){
		T[i].k = -1;
	}

	cin >> m >> k;
	
	while(k != 0){
		hash_insert(T, m, k);
		i++;
		cin >> k;
		
	}
	
	for(i=0 ; i < m ; i++){
		cout << T[i].k << " ";
	}

	return 0;
}
