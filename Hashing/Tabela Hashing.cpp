#include <iostream>
#include <string.h>

using namespace std;

struct aluno
{
	char nome[100];
	char email[100];
	int key;
	int status; // 1 = utilizado, 0 = não utilizado
};

#define m 100

int h(int n){
	return n%m;
}

int h2(int n){
	return 1 + n%(m-1);
}

int H(int k, int i){
	//sondagem linear:
	//return (1 * i + h(k))%m;
	
	//sondagem quadratica
	//return (3*i*i+1*i+h(k))%m;
	
	//double hash
	return (h2(k) * i + h(k))%m;
}

int chave(char *s){
	int soma = 0;
	while(*s != '\0'){
		soma = soma + (int)*s;
		s++;
	}
	return soma;
}

void cadastrar (aluno *tabela){
	aluno tmp;
	int i, p, k;
	
	cout << "Encontre o email" << endl;
	cin >> tmp.email;
	cout << "Entre com o nome" << endl;
	cin >> tmp.nome;
	tmp.key = chave(tmp.email);
	cout << "Chave: " << tmp.key << endl;
	
	for(i = 0; i < m; i++){
		p = H(tmp.key, i);
		if(tabela[p].status == 0){
			tabela[p] = tmp;
			tabela[p].status = 1;
			break;
		}
	}
	cout << "Salvou em: " << p << endl;
	if(i == m){
		cout << "tabela cheia" << endl;
	}
}

void buscar(aluno *tabela){
	char email[100];
	int k, p;
	int achou = -1;
	
	cout << "Entre com o e-mail:" << endl;
	cin >> email;
	k = chave(email);
	
	for(int i = 0; i < m; i++){
		p = H(k, i);
		if(tabela[p].status == 0) break;
		if(tabela[p].key == k && strcmp(tabela[p].email, email) == 0){
			achou = p;
		}
	}
	if(achou == -1) cout << "Nao encontrado" << endl;
	else cout << "Encontrado na posicao " << achou << endl;
}

int main(){
	aluno tabela[m];
	int op;
	
	for(int i = 0; i<m; i++){
		tabela[i].status = 0;
	}
	
	do{
		cout << "1 - Cadastrar" << endl;
		cout << "2 - Pesquisar" << endl;
		cout << "3 - Sair" << endl;
		cin >> op;
		
		switch(op){
		case 1:
			cadastrar(tabela);
			break;
		case 2:
			buscar(tabela);
		} 	
	}while(op != 3);
	
	return 0;
}








