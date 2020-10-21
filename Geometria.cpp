#include <iostream>
#include <cmath>

using namespace std;

struct ponto{
	int x, y;	
};

typedef ponto vetor;

/*
struct vetor{
	int x, y;	
};
*/

vetor calcV( ponto A, ponto B ){
	vetor tmp;
	tmp.x = B.x - A.x;
	tmp.y = B.y - A.y;
	return tmp;
}

int escalar( vetor A, vetor B ){
	return A.x * B.x + A.y * B.y;
}

int vetorial( vetor A, vetor B ){
	return A.x*B.y - A.y*B.x;
}

/*
 1 - se o ponto C esta a esq da reta AB
 0 - se o ponto C esta na reta AB
-1 - se o ponto C esta a direita da reta AB
*/
int sentido( ponto A, ponto B, ponto C ){
	vetor AB, AC;
	int s;
	AB = calcV(A, B);
	AC = calcV(A, C);
	s = vetorial(AB, AC);
	if( s > 0 ) return 1;
	if( s < 0 ) return -1;
	return 0;
}

/*
 1 - se ta dentro
 0 - se ta na borda
-1 - se ta fora
*/
int pontoTriangulo( ponto A, ponto B, ponto C, ponto P){
	int s1, s2, s3;
	s1 = sentido(A, B, P);
	s2 = sentido(B, C, P);
	s3 = sentido(C, A, P);
	if( s1 == s2 && s2 == s3 ){
		return 1;
	}
	if( s1*s2 == -1 || s1*s3 == -1 || s2*s3 == -1 ){
		return -1;
	}
	return 0;
}

int pontoPoligono( int n, ponto *poli, ponto p ){
	
	int aux;
	
	for( int i = 1; i < n-1; i++ ){
		aux = pontoTriangulo( poli[0], poli[i], poli[i+1], p);
		if( aux != -1 ){
			return 1;
		}
	}

	return -1;
}

double areaTriangulo( ponto A, ponto B, ponto C ){
	vetor AB, AC;
	AB = calcV(A, B);
	AC = calcV(A, C);
	return abs(vetorial(AB, AC)/2.0);
}

double areaPoligono(int n, ponto *poli){
	double aux = 0;	
	for( int i = 1; i < n-1; i++ ){
		aux = aux + areaTriangulo(poli[0], poli[i], poli[i+1]);
	}
	return aux;
}

int main(){
	
	int n;
	ponto p, poli[100];
	
	cin >> n;
	for( int i = 0; i < n; i++ ){
		cin >> poli[i].x >> poli[i].y;
	}
	
	cout << areaPoligono(n, poli);
}








