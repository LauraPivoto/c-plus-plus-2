#include <iostream>

using namespace std;

int hash_aux(int k1, int m)
{
	int mod = k1 % m;
	if((mod) < 0)
	{
		return (mod) + m;
	}
	else
	{
		return mod;
	}

}

int hash1(int k, int i, int m)
{
	int mod = (k + i) % m;
	return mod;
}

int main()
{
	int k1, m;
	int i = 0; //tentativa

	cin >> k1 >> m;

	int k = hash_aux(k1, m);

	while(i < m)
	{
		if(i == m - 1)
		{
			int resultado = hash1(k, i, m);
			cout << resultado;
			i++;
		}
		else
		{
			int resultado = hash1(k, i, m);
			cout << resultado << " " ;
			i++;
		}
	}

	return 0;
}
