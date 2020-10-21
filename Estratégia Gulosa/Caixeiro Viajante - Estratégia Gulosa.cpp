#include<iostream>

using namespace std;

int main(){
	
	int n;
	int custo[400][400]; 
	int vis[400];
	int at;
	int resp = 0;
	int menor;
	int prox;
	int inicial;
	
 	cout << "N de cidades" << endl;
 	cin >> n;
	
	for( int i = 0; i < n; i++ ){
		custo[i][i] = 0;
		vis[i] = 0;
		for( int j = i+1; j < n; j++ ){
			cout << "Custo de " << i << " para " << j << endl;
			cin >> custo[i][j];
			custo[j][i] = custo[i][j];
		}
	}
	
	cout << "Cidade inicial:" << endl;
	cin >> inicial;
	
	at = inicial;
	vis[at] = 1;
	
	for( int i = 0; i < n-1; i++ ){
		menor = 9999;
		for( int j = 0; j < n; j++ ){
			if( menor > custo[at][j] && !vis[j] ){
				menor = custo[at][j];
				prox = j;	
			}
		}
		vis[prox] = 1;
		at = prox;
		resp = resp + menor;
	}
	resp = resp + custo[at][inicial];
	
	cout << "Resposta: " << resp << endl;
	
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










