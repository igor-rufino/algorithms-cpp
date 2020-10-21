#include <iostream>

using namespace std;

int main(){
	
	int n, m;
	int v1[100], v2[100];
	int pd[101][101], caminho[101][101];
	int a, b, c; // a = 0; b = 1; c = 2
	int i, j;
	
	cout << "Tamanho de V1" << endl;
	cin >> n;
	
	cout << "V1" << endl;
	for( int i = 0; i < n; i++ ){
		cin >> v1[i];
	}
	
	cout << "Tamanho de V2" << endl;
	cin >> m;
	
	cout << "V2" << endl;
	for( int i = 0; i < m; i++ ){
		cin >> v2[i];
	}
	
	for( int i = 0; i <= n; i++ ){
		pd[m][i] = 0;
	}
	
	for( int i = 0; i <= m; i++ ){
		pd[i][n] = 0;
	}
	
	for( int j = m-1; j >= 0; j-- ){
		for( int i = n-1; i >= 0; i-- ){
			a = pd[j][i+1];
			b = pd[j+1][i];
			if( v1[i] == v2[j] ){
				c = pd[j+1][i+1] + 1;
			}
			else{
				c = -1;
			}
						
			if( a > b && a > c ){
				pd[j][i] = a;
				caminho[j][i] = 0;
			}
			else if( b > c ){
				pd[j][i] = b;
				caminho[j][i] = 1;
			}
			else{
				pd[j][i] = c;
				caminho[j][i] = 2;
			}
		}
	}
	cout << "Valores" << endl;
	for( int j = 0; j <= m; j++ ){
		for( int i = 0; i <= n; i++ ){
			cout << pd[j][i] << " ";
		}
		cout << endl;
	}
	cout << "Caminhos" << endl;
	for( int j = 0; j <= m; j++ ){
		for( int i = 0; i <= n; i++ ){
			cout << caminho[j][i] << " ";
		}
		cout << endl;
	}
	
	cout << "LCS tem tam: " << pd[0][0] << endl;
	//*
	i = 0;
	j = 0;
	while( i < n && j < m ){//*/
	//for( int i = 0, j = 0; i < n && j < m; ){
		if( caminho[j][i] == 0 ){
			i++;
		}
		else if( caminho[j][i] == 1 ){
			j++;
		}
		else{
			cout << v1[i] << " ";
			i++;
			j++;
		}
	}
	
	return 0;
}

/*
7
9 7 3 4 1 8 9
5
3 1 4 7 9
*/


