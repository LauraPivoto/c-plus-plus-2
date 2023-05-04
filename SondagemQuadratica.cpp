#include <iostream>
#include <math.h>

using namespace std;

int h1(int k, int m)
{
	int mod = k % m;
		return mod;
}

int h2(int k, int m){
	int mod = (1 + k)%(m-1);
	return mod;
}

int hash(int k, int m, int i){
	int mod = (h1(k,m)+ i*h2(k,m))%m;
	return mod;
}


int main()
{
	int k, m;
	int i = 0; //tentativa

	cin >> k >> m;

	while(i < m)
	{
		if(i == m - 1)
		{
			int resultado = hash(k, m, i);
			cout << resultado;
			i++;
		}
		else
		{
			int resultado = hash(k,m, i);
			cout << resultado << " " ;
			i++;
		}
	}

	return 0;
}
