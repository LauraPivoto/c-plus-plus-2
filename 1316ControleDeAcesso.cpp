#include <iostream>

using namespace std;

int binaria(int vetor[], int tamanho, int x)
{
	bool achou;
// var aux p/ busca
	int baixo, meio, alto;
// var aux
	baixo = 0;
	alto = tamanho - 1;
	achou = false;
	while ((baixo <= alto) && (achou == false))
	{
		meio = (baixo + alto) / 2;
		if (x < vetor[meio])
			alto = meio - 1;
		else if (x > vetor[meio])baixo = meio + 1;
		else achou = true;
	}
	if (achou)
		return 1;
	else
		return 0;
}

int main()
{
	int vetor[100];
	int i=0, tamanho = 0, x;
	
	cin >> vetor[i];
	while(vetor[i] != -1){
		tamanho++;
		i++;
		cin >> vetor[i];
	}
	
	cin >> x;
	
	int resultado = binaria(vetor, tamanho, x);
	
	if(resultado == 0){
		cout << "Nao possui acesso" << endl;
	}else{
		cout << "Possui acesso" << endl;
	}
}
