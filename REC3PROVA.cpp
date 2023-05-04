#include <iostream> //Ajudar na entrada e saída de dados
#include <math.h> //biblioteca para cálculos matemáticos

using namespace std;

int elevar(int k, int n){
	
	if(n==0){
		return 1;
	}else{
		return k*pow(k,n-1);
	}
}

int main(){
	int k; //Base para o cálculo
	int n; //potência para o cálculo
	
	cin >> k >> n; //entrada com as variáveis
	
	cout << elevar(k,n); //cálculo
	
	return 0;
}