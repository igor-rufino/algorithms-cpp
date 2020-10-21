#include <iostream>
#include <algorithm>

using namespace std;

struct item{
	int peso, valor;
};

/*
1 - se "a" vem antes de "b" na ordenação
0 - caso contrario
*/
bool cmp( item a, item b ){
	if( a.valor > b.valor ) return 1;
	if( b.valor > a.valor ) return 0;
	if( a.peso < b.peso ) return 1;
	return 0;
}

int main(){
	
	int n, cap, resp, capAt;
	item vetor[100000];
	
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
	
	sort( vetor, vetor+n, cmp );
	
	resp = 0;
	capAt = cap;
	for( int i = 0; i < n; i++ ){
		if( capAt >= vetor[i].peso ){
			resp += vetor[i].valor;
			capAt -= vetor[i].peso;
		}
	}
	
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





