#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

float raiz(float X, float X0, float e)
{
	if(fabs(pow(X0, 2) - X) <= e)
	{
		return X0;
	}
	else
	{
		X0 = (pow(X0, 2) + X) / (2 * X0);
		return raiz(X, X0, e);
	}

}

int main()
{
	float X, X0, e;

	cin >> X >> X0 >> e;

	cout << fixed << setprecision(2) << raiz(X, X0, e);

	return 0;
}
