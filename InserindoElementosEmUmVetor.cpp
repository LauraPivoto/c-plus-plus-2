#include <iostream>
using namespace std;

int main(){
int *v = NULL; //armazena dados
int N; //tamanho desejado
int *p;
int *q;
int i;

cout << "Qual o tamanho desejado para o vetor?" << endl;
cin >> N;

//Alocar mem�ria
v = new int [N]; //inicialmente aponta para o primeiro endere�o do vetor

p = v;
for(i=0; i<N;i++){
	cin >> *p;
	p++;
	}

q = v;
for(i=0; i<N;i++){
	cout << *q << " ";
	q++;
}

delete [] v; //liberar mem�ria usada pelo vetor
return 0;
}