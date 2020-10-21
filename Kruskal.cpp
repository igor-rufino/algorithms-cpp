#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct aresta{
	int origem;
	int destino;
	int custo;	
};

struct grafo{
	int nVertices;
	int nArestas;
	vector<aresta> adj[100];
	int vis[100];	
};

void adicionaAresta( grafo &g, int origem, int destino, int custo = 1, int direcionada = 0 ){
	
	aresta tmp;
	tmp.origem = origem;
	tmp.destino = destino;
	tmp.custo = custo;
	
	g.adj[origem].push_back(tmp);
	if( !direcionada ){
		adicionaAresta( g, destino, origem, custo, 1 );
	}
}

void exibeGrafo( grafo g ){
	for( int i = 0; i < g.nVertices; i++ ){
		cout << "Vertice: " << i << ":";
		for( int j = 0; j < g.adj[i].size(); j++ ){
			aresta tmp = g.adj[i][j];
			cout << " -> (" << tmp.destino << ", " << tmp.custo << ")";
		}
		cout << endl;
	}
}

/* 
1 - se a vem antes b
0 - caso contrario
*/

bool cmp( aresta a, aresta b ){
//	if( a.custo < b.custo ) return true;
//	else return false;
	return a.custo < b.custo;
}

// findSet
int encontraPai(int *pai, int u){
	if( pai[u] != u ){
		pai[u] = encontraPai(pai, pai[u]);
	}
	return pai[u];
}

// sameSet
bool mesmaComponente( int *pai, int u, int v ){
	int pu, pv;
	pu = encontraPai(pai, u);
	pv = encontraPai(pai, v);	
	return pu == pv;
}

// unionSet
void juntaComponentes( int *pai, int u, int v ){
	int pu, pv;
	pu = encontraPai(pai, u);
	pv = encontraPai(pai, v);
	pai[pu] = pv;
}

void kruskal( aresta *arestas, int n, int m ){
	int pai[n];
	int u, v, resp = 0;
	for( int i = 0; i < n; i++ ){
		pai[i] = i;
	}
	
	for( int i = 0; i < m; i++ ){
		u = arestas[i].origem;
		v = arestas[i].destino;
		if( !mesmaComponente(pai, u, v) ){
			cout << u << " - " << v << endl;
			resp = resp + arestas[i].custo;
			juntaComponentes(pai, u, v);
		}
	}
	
	cout << "Custo Final: " << resp << endl;
}

int main(){
	
	int n, m;
	int u, v, c;
	aresta arestas[1000];
	
	cout << "Numero de vertices" << endl;
	cin >> n;
	cout << "Numero de arestas" << endl;
	cin >> m;
	
	cout << "Arestas: " << endl;
	for( int i = 0; i < m; i++ ){
		cin >> u >> v >> c;
		arestas[i].origem = u;
		arestas[i].destino = v;
		arestas[i].custo = c;
	}
	sort( arestas, arestas+m, cmp );
	
	kruskal(arestas, n, m);
	
	return 0;
}

/*
6
11
0 1 2
0 2 7
0 3 3
0 5 8
1 3 11
1 4 9
1 5 4
2 3 6
2 5 12
3 4 5
4 5 1
*/