#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct item{
	int peso, valor;
};
	

int main(){
	
	int n, cap, pd[101][101], a, b, capAt;
	int caminho[100][101], t;
	item vetor[100], mochila[100];

	cout << "Quantidade de itens" << endl;
	cin >> n;
	
	cout << "Capacidade total" << endl;
	cin >> cap;
	
	for( int i = 0; i < n; i++ ){
		//*
		cout << "Peso e valor do item ";
		cout << i << endl;
		cin >> vetor[i].peso;
		cin >> vetor[i].valor;
		//*/vetor[i].peso = vetor[i].valor = 1;
	}
	
	for( int i = 0; i <= cap; i++ ){
		pd[n][i] = 0;
	}
	
	for( int i = n-1; i >= 0; i-- ){
		for( int j = 0; j <= cap; j++ ){
			a = pd[i+1][j];
			b = -1;
			if( vetor[i].peso <= j ){
				b = pd[i+1][j-vetor[i].peso];
				b += vetor[i].valor;
			}
			if( a > b ){
				pd[i][j] = a;
				caminho[i][j] = 0;
			}
			else{
				pd[i][j] = b;
				caminho[i][j] = 1;
			}
		}
	}
	//*
	for( int i = 0; i <= n; i++ ){
		for( int j = 0; j <= cap; j++ ){
			printf("%2d ", pd[i][j] );
		}
		cout << endl;
	}
	cout << "---------" << endl;
	for( int i = 0; i <= n; i++ ){
		for( int j = 0; j <= cap; j++ ){
			printf("%2d ", caminho[i][j] );
		}
		cout << endl;
	}
	//*/
	cout << "Resp.: " << pd[0][cap] << endl;
	
	capAt = cap;
	t = 0;
	for( int i = 0; i < n; i++ ){
		if( caminho[i][capAt] == 1 ){
			mochila[t] = vetor[i];
			t++;
			capAt = capAt - vetor[i].peso;
		}
	}
	
	cout << "Total de itens: " << t << endl;
	cout << "Peso Final: " << cap - capAt << endl;
	for( int i = 0; i < t; i++ ){
		cout << mochila[i].peso << " -- ";
		cout << mochila[i].valor << endl;
	}
	
	return 0;
}

/*
4
10
7 42
3 12
4 40
5 25
*/




