#include <iostream>
#include <vector>
#include <queue>

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

int bfs( grafo &g, int inicio, int fim ){
	int u, v; // u - vertice q estou processando no momemento, v - vizinhos de u
	queue<int> q;
	q.push(inicio);
	
	for( int i = 0; i < g.nVertices; i++ ){
		g.vis[i] = 0;
		g.dist[i] = -1;
	}
	
	g.dist[inicio] = 0;
	g.vis[inicio] = 1;
	g.pai[inicio] = -1;
	
	while(!q.empty()){
		u = q.front();
		q.pop();
	//	cout << u << endl;
		for( int i = 0; i < g.adj[u].size(); i++ ){
			v = g.adj[u][i].destino;
			if( !g.vis[v] ){
				q.push(v);
				g.vis[v] = 1;
				g.dist[v] = g.dist[u] + 1;
				g.pai[v] = u;
			} 
		}
	}
	
	u = fim;
	cout << "Caminho:";
	while( u != -1 ){
		cout << " " << u;
		u = g.pai[u];
	}
	cout << endl;
	return g.dist[fim];
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
	//exibeGrafo(g);
	cout << "Menor Caminho: " << bfs( g, 4, 0 ) << endl;
	
	return 0;
}

/*
8
8
0 3 
0 5 
1 2 
1 3 
2 3 
2 4 
4 5 
6 7
*/