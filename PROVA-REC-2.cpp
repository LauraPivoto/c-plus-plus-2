#include <iostream>

using namespace std;

int Comb(int n,int k)
{
	
	if(k == 1)
	{
		return n;
	}
	if(k == n)
	{
		return 1;
	}else
	{
		return Comb(n - 1, k - 1) + Comb(n - 1, k);
	}
}

int main()
{
	int n, k;
	
	cin >> n >> k;
	
	cout << Comb(n,k);
	
	return 0;
}
