#include <iostream>
#include <vector>

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

int main(){
	
	int u, v, c;
	grafo g;
	
	cout << "Numero de vertices: " << endl;
	cin >> g.nVertices;
	cout << "Numero de arestas: " << endl;
	cin >> g.nArestas;
	
	for( int i = 0; i < g.nArestas; i++ ){
		cin >> u >> v;
		adicionaAresta(g, u, v);
	}
	exibeGrafo(g);
	
	return 0;
}

/*
6
7
0 3 
0 5 
1 2 
1 3 
2 3 
2 4 
4 5 
*/