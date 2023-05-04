#include <iostream>
#include <list>
using namespace std;

void maiorMenor(list<int> lista, int &menor, int &maior){
	
	list<int>::iterator p; //iterador para varrer a lista
	
	for(p = lista.begin(); p != lista.end(); p++)
	{
		if(*p < menor){
			menor = *p;
		}
	}
	
	for(p = lista.begin(); p != lista.end(); p++)
	{
		if(*p > maior){
			maior = *p;
		}
	}
}

int main()
{
	list<int> lista; //ponteiro para lista
	list<int>::iterator p; //iterador para varrer a lista
	int maior = -99999;
	int menor = 10000000;
	
	int x;
	cin >> x;
	while(x != 0){
		lista.push_front(x);
		cin >> x;
	}
	
	maiorMenor(lista, menor, maior);
	
	cout << "menor: " << menor << endl;
	cout << "maior: " << maior << endl; 
	
}
