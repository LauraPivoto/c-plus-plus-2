#include <iostream>
using namespace std;

int main()
{
	int *v = NULL; //armazena dados
	int N; //tamanho desejado
	int *p;
	int *q;
	int i;
	int ok = 0;

	cin >> N;

//Alocar mem�ria
	v = new int [N]; //inicialmente aponta para o primeiro endere�o do vetor

	p = v;
	for(i = 0; i < N; i++)
	{
		cin >> *p;
		if(*p > 0 && *p%2==0){
			ok++;
		}
		p++;
	}

	cout << ok;

	delete [] v; //liberar mem�ria usada pelo vetor
	return 0;
}
