#include <iostream>
#include <math.h>

using namespace std;

int potencia(int a, int n){
	if(n == 0){
		return 1;
	}else if( n > 0){
		return a*pow(a, n-1);
	}
}

int main(){
	int a, n;
	
	cin >> a >> n;
	
	int resultado = potencia(a, n);
	cout << resultado << endl;
	
	return 0;
}