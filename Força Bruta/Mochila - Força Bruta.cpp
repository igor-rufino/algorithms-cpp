#include <iostream>
#include <algorithm>

using namespace std;

struct item{
	int peso, valor;
};

int solve( int pos, int cap, item* vetor, int n ){
	if( pos == n ){
		return 0;
	}
	int a, b = -1;
	a = solve( pos+1, cap, vetor, n );
	if( vetor[pos].peso <= cap ){
		b = solve( pos+1, cap-vetor[pos].peso, vetor, n);
		b += vetor[pos].valor;
	}	
	if( a > b ) return a;
	return b;
}

int main(){
	
	int n, cap, resp;
	item vetor[1000];
	
	cout << "Quantidade de itens" << endl;
	cin >> n;
	
	cout << "Capacidade total" << endl;
	cin >> cap;
	
	for( int i = 0; i < n; i++ ){
		cout << "Peso e valor do item ";
		cout << i << endl;
		cin >> vetor[i].peso;
		cin >> vetor[i].valor;
	}
	
	resp = solve(0, cap, vetor, n);
	
	cout << "Resp: " << resp << endl;
	
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





