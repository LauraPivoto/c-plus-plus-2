#include <iostream>
using namespace std;

int main()
{
	int *v = NULL; //armazena dados
	int N; //tamanho desejado
	int *p;
	int *q;
	int i;
	float soma = 0;
	int maior = -9999;

	cin >> N;

//Alocar mem�ria
	v = new int [N]; //inicialmente aponta para o primeiro endere�o do vetor

	p = v;
	for(i = 0; i < N; i++)
	{
		cin >> *p;
		if(*p > maior){
			maior = *p;
		}
		p++;
	}

	cout << maior;

	delete [] v; //liberar mem�ria usada pelo vetor
	return 0;
}
