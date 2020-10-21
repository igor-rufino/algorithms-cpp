#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	
	int n;
	int custo[20][20]; 
	int resp = 9999;
	int inicial;
	int cidades[20];
	int custTmp;
	int at;
	
 	cout << "N de cidades" << endl;
 	cin >> n;
	
	for( int i = 0; i < n; i++ ){
		custo[i][i] = 0;
		for( int j = i+1; j < n; j++ ){
			cout << "Custo de " << i << " para " << j << endl;
			cin >> custo[i][j];
			custo[j][i] = custo[i][j];
		}
	}
	
	cout << "Cidade inicial:" << endl;
	cin >> inicial;

	for( int i = 0, j = 0; i < n; i++ ){
		if( i != inicial ){
			cidades[j] = i;
			j++;
		}
	}
	
	do{
		custTmp = 0;
		at = inicial;
		for( int i = 0; i < n-1; i++ ){
			custTmp = custTmp + custo[at][cidades[i]];
			at = cidades[i];
		}
		custTmp = custTmp + custo[at][inicial];
		if( resp > custTmp ){
			resp = custTmp;
		}
		
	}while( next_permutation( cidades, cidades+n-1 ) );
	
	cout << "Resp: " << resp << endl;
	
	return 0;
}

/*
4
2
8
50
3
4
7
*/

