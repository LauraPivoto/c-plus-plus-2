#include <iostream> //Ajudar na entrada e sa�da de dados
#include <math.h> //biblioteca para c�lculos matem�ticos

using namespace std;

int elevar(int k, int n){
	
	if(n==0){
		return 1;
	}else{
		return k*pow(k,n-1);
	}
}

int main(){
	int k; //Base para o c�lculo
	int n; //pot�ncia para o c�lculo
	
	cin >> k >> n; //entrada com as vari�veis
	
	cout << elevar(k,n); //c�lculo
	
	return 0;
}