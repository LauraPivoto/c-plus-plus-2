#include <iostream> //entrada e saida

using namespace std; //Facilitar entrada e saída de dados



struct dado
{
	int k;
	int status; //0: vazio, 1: ocupado, 2: removido
};



//método da divisão, função auxiliar para o calculo da posição em que a chave k vai se inserida na tabela
int h1(int k, int m)
{
	int res;//recebe o resultado



	res = k % m; //faz o calculo
	if (res < 0)
	{
		return res + m;
	}
	else
	{
		return res;
	}

}


//faz o caulculo para o double hashing
int h2(int k, int m)
{
	int res;//recebe o resultado

	res = 1 + (k % (m - 1)); //faz o calculo

	if (res < 0)
	{
		return res + m;
	}
	else
	{
		return res;
	}

}

//faz a double hashing
int hash1(int k, int i, int m)
{
	int res1;
	int res2;
	int res3;

//faz o método da divisão
	res1 = h1(k, m);

//faz o double hashing
	res2 = h2(k, m);

//calcula o resultado final do double hashing
	res3 = (res1 + (i * res2)) % m;

	return res3;

}

//Insere os elementos na tabela hash
int hash_insert(dado T[], int m, int k)
{
	int i = 0;//contador
	int j;//contador

	do
	{
		j = hash1(k, i, m);
		if (T[j].status != 1)
		{
			T[j].k = k;
			T[j].status = 1;
			return j; //posição que k foi inserida em T
		}
		else
		{
			i++;
		}
	}
	while(i != m);
	return -1;
}

//função que faz a pesquisa
int hash_search(dado T[], int m, int k)
{
	int i, j; //contador
	i = 0;
	do
	{
		j = hash1(k, i, m);
		if (T[j].k == k)
		{
			return j;
		}
		i = i + 1;
	}
	while (T[j].status != 0 && i < m);
	return -1;

}

//função que faz a remoção
int hash_remove(dado T[], int m, int k)
{
	int j; //recebe a posição do elemento
	j = hash_search(T, m, k);
	if(j != -1)
	{
		T[j].status = 2;
		T[j].k = -1;
		return 0; // consegui remover
	}
	else
		return -1; // k nao esta na tabela

}


int main()
{
	dado T[50]; //tabela hash
	int m;//tabela
	int op; //opcao da pessoa
	int valor; //valor da chave
	int k; //chave para ser procurada e removida
	int res; //recebe a posição da chave
	int cont; //auxiliar

	//entrando com o tamanho da tabela
	cin >> m;

	//inicializar a tabela
	for(cont = 0; cont < m; cont++)
	{
		T[cont].k = -1;
		T[cont].status = 0;
	}

	cin >> op;
	while(op != 5)
	{
		if (op == 1)
		{
			cin >> valor;
			hash_insert(T, m, valor);
		}
		//opção 2
		 if (op == 2)
		{
			cin >> k; //valor para ser pesquisado
			res = hash_search(T, m, k);
			//mostando o resultado da 2
			cout << res << endl;
		}
		//opção 3
		if(op == 3)
		{
			cin >> k;
			hash_remove(T, m, k);
		}
		//opção 4
		 if (op == 4)
		{
			for(cont = 0; cont < m - 1; cont++)
			{
				cout << T[cont].k << " ";
			}
			cout << T[cont].k << endl;
		}

		cin >> op;
	}



	return 0;
}