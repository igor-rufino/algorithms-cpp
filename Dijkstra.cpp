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
	int pai[100];	
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

void dijkstra( grafo g, int ini, int fim ){
	int at, p, custo;
	int caminho[g.nVertices], tam = 0;	
	for( int i = 0; i < g.nVertices; i++ ){
		g.dist[i] = INT_MAX;
		g.vis[i] = 0;
	}
	
	at = ini;
	g.dist[at] = 0;
	g.pai[at] = -1;
	
	for( int j = 1; j < g.nVertices; j++ ){
		g.vis[at] = 1;
		
		for( int i = 0; i < g.adj[at].size(); i++ ){
			p = g.adj[at][i].destino;
			custo = g.adj[at][i].custo;
			
			if( g.dist[p] > g.dist[at] + custo && !g.vis[p] ){
				g.dist[p] = g.dist[at] + custo;
				g.pai[p] = at;
			}
		}
		custo = INT_MAX;
		for( int i = 0; i < g.nVertices; i++ ){
			if( g.dist[i] < custo && !g.vis[i] ){
				custo = g.dist[i];
				at = i;
			}
		}
	}
	if( g.dist[fim] == INT_MAX ){
		cout << "Nao existe caminho" << endl;
	}
	else{
	   	cout << "Resp: " << g.dist[fim] << endl;
	   	at = fim;
	   	while( at != -1 ){
		   	caminho[tam] = at;
		   	tam++;
			at = g.pai[at];	   
		}
		
		for( int i = tam-1; i >= 0; i-- ){
			cout << caminho[i] << " - ";
		}
	}
}

int main(){
	
	int u, v, c, ini, fim;
	grafo g;
	
	cout << "Numero de vertices: " << endl;
	cin >> g.nVertices;
	cout << "Numero de arestas: " << endl;
	cin >> g.nArestas;
	
	for( int i = 0; i < g.nArestas; i++ ){
		cin >> u >> v >> c;
		adicionaAresta(g, u, v, c);
	}
	cout << "Inicio e fim" << endl;
	cin >> ini >> fim;
	
	dijkstra(g, ini, fim);
	
	return 0;
}

/*
8
10
0 1 6
0 4 11
0 5 1
1 2 5
1 4 2
2 3 7
2 4 4
2 5 2
3 5 4
6 7 1

*/