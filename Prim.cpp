#include <iostream>
#include <vector>
#include <limits.h>

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
	int dist[100];	
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

void prim( grafo g ){
	int at, p, custo, resp = 0; 
	for( int i = 0; i < g.nVertices; i++ ){
		g.dist[i] = INT_MAX;
		g.vis[i] = 0;
	}
	at = 0;
	
	for( int i = 1; i < g.nVertices; i++ ){
		g.vis[at] = 1;
		for( int j = 0; j < g.adj[at].size(); j++ ){
			p = g.adj[at][j].destino;
			custo = g.adj[at][j].custo;
			if( g.dist[p] > custo ){
				g.dist[p] = custo;
			}
		}
		custo = INT_MAX;
		for( int j = 0; j < g.nVertices; j++ ){
			if( g.dist[j] < custo && !g.vis[j] ){
				custo = g.dist[j];
				at = j;
			}
		}
		resp = resp + custo;
	}
	
	cout << "Custo Final: " << resp << endl;
}

int main(){
	
	int u, v, c;
	grafo g;
	
	cout << "Numero de vertices: " << endl;
	cin >> g.nVertices;
	cout << "Numero de arestas: " << endl;
	cin >> g.nArestas;
	
	for( int i = 0; i < g.nArestas; i++ ){
		cin >> u >> v >> c;
		adicionaAresta(g, u, v, c);
	}
	
	prim(g);
	
	return 0;
}

/*
9
14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/