#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct noh{
	int info;
	struct noh* esq;
	struct noh* dir;
};
typedef struct noh arvore;

arvore* arv_cria(int c, arvore* sae, arvore* sad){
	arvore* p = (arvore*)malloc(sizeof(arvore));
	if(p==NULL) exit(1);
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;
}

arvore* arv_criavazia(void){
	return NULL;
}

int arv_vazia(arvore* a){
	return a == NULL;
}

arvore* arv_libera(arvore* a){
	if(!arv_vazia(a)){
		arv_libera(a->esq);
		arv_libera(a->dir);
		free(a);
	}
	return NULL;
}

int arv_pertence(arvore* a, int c){
	if(arv_vazia(a)) return 0;
	else{
		return a->info || arv_pertence(a->esq, c) || arv_pertence(a->dir,c);
	}
}

void arv_imprime_ordem(arvore* a){
	if(!arv_vazia(a)){
		arv_imprime_ordem(a->esq);
		cout << a->info << " ";
		arv_imprime_ordem(a->dir);
	}
}

void arv_imprime_pos(arvore* a){
	if(!arv_vazia(a)){
		arv_imprime_pos(a->esq);
		arv_imprime_pos(a->dir);
		cout << a->info << " ";
	}
}

void arv_imprime_pre(arvore* a){
	if(!arv_vazia(a)){
		cout << a->info << " ";
		arv_imprime_pre(a->esq);
		arv_imprime_pre(a->dir);
	}
}

int main()
{
	int op, val;
	bool alo;
	
	arvore* d1 = arv_cria(5, arv_criavazia(), arv_criavazia());
	arvore* d2 = arv_cria(11, arv_criavazia(), arv_criavazia());
	arvore* d3 = arv_cria(4, arv_criavazia(), arv_criavazia());
	
	arvore* c1 = arv_cria(2, arv_criavazia(), arv_criavazia());
	arvore* c2 = arv_cria(6, d1, d2);
	arvore* c3 = arv_cria(9, d3, arv_criavazia());
	
	arvore* b1 = arv_cria(7, c1, c2);
	arvore* b2 = arv_cria(5, arv_criavazia(), c3);
	
	arvore* a1 = arv_cria(2, b1, b2);
	
	do{
		cout << endl << "1 - IMPRIMIR EM ORDEM" << endl;
		cout << "2 - IMPRIMIR EM POS-ORDEM" << endl;
		cout << "3 - IMPRIMIR EM PRE-ORDEM" << endl;
		cout << "4 - VERIFICAR ELEMENTO" << endl;
		cout << "5 - SAIR" << endl;		
		cin >> op;
		
		switch(op)
		{
		case 1:
			arv_imprime_ordem(a1);
			cout << endl;
			break;
		case 2:
			arv_imprime_pos(a1);
			cout << endl;
			break;
		case 3:
			arv_imprime_pre(a1);
			cout << endl;
			break;
		case 4:
			cout << "Elemento a ser verificado: ";
			cin >> val;
			cout << endl;
			alo = arv_pertence(a1, val);
			if(alo){
				cout << "O elemento pertence a arvore" << endl;
			}
			else{
				cout << "O elemento nao pertence a arvore" << endl;
			}
			break;
		default:
			break;
		}
		
	}while(op != 5);
	
	return 0;
}














