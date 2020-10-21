#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int x;
int a[10000];
int na = 10000;
int b[100000];
int nb = 100000;
int c[1000000];
int nc = 1000000;

clock_t t1,t2;

void insertionSort(int v[], int n){
	t1=clock();
	
	int i, chave, j;
	
	for (j = 1; j < n; j++){
		chave = v[j];
		i = j-1;
        while (i > 0 && v[i] > chave){
			v[i+1] = v[i];
			i = i-1;
		}
		v[i+1] = chave;
	}
	
	t2=clock();
	float diff ((float)t2-(float)t1);
	float seconds = diff / CLOCKS_PER_SEC;
    cout<< "Insertion Sort: " <<seconds<<endl;
	
	// for (int i = 0; i < n; i++){
	// 	cout << v[i] << "... ";
	// }
}

void bubbleSort(int v[], int n){
	t1=clock();
	
	int temp, i, j;
	
	for(i=n-1; i>=1; i--){
		for(j=0; j<i; j++){
			if(v[j] > v[j+1]){
				temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
			}
		}
	}
	
	t2=clock();
	float diff ((float)t2-(float)t1);
	float seconds = diff / CLOCKS_PER_SEC;
    cout<< "Bubble Sort: " <<seconds<<endl;
	
	// for (int i = 0; i < n; i++){
	// 	cout << v[i] << "... ";
	// }
}

void selectionSort(int v[], int n){
	t1=clock();
	
	int min, x, i, j;
	
	for(i=0; i<=n-1; i++){
		min = i;
		for(j=i+1; j<=n; j++){
			if(v[j] < v[min]){
				min = j;
			}
		}
		x = v[min];
		v[min] = v[i];
		v[i] = x;
	}
	
	t2=clock();
	float diff ((float)t2-(float)t1);
	float seconds = diff / CLOCKS_PER_SEC;
    cout<< "Selection Sort: " <<seconds<<endl;
	
	// for (int i = 0; i < n; i++){
	// 	cout << v[i] << "... ";
	// }
}

int main(){	
	for (int i = 0; i < na; i++){
		x = rand() % na;
		a[i] = x;		
	}
	for (int j = 0; j < nb; j++){
		x = rand() % nb;
		b[j] = x;
	}
	for (int k = 0; k < nc; k++){
		x = rand() % nc;
		c[k] = x;
	}
	
	insertionSort(a, na);
	insertionSort(b, nb);
	insertionSort(c, nc);
	
	bubbleSort(a, na);
	bubbleSort(b, nb);
	bubbleSort(c, nc);
	
	selectionSort(a, na);
	selectionSort(b, nb);
	selectionSort(c, nc);
	
	return 0;
}