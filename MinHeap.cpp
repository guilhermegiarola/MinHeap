#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <fstream>

using namespace std;

void heapify(int v[], int pos, int size){
	
	//If there are subroot->left and subroot->right:
	
	if(pos*2+2 <= size){										
		
		//If the subroot->left is smaller than subroot->right and the position is smaller than the size of the heap:
		if(v[pos*2+1] < v[pos*2+2] and pos*2+1 <= size){		
		if(v[pos*2+1] < v[pos*2+2] and pos*2+1 <= size){		
			if(v[pos*2+1] < v[pos]){							
				int aux = v[pos*2+1];							
				v[pos*2+1] = v[pos];							
				v[pos] = aux;									
			}
			
		heapify(v, pos*2+1, size);								
		return;
		}
	
		//If the subroot->right is smaller than subroot->left and the position is smaller than the size of the heap:
		else if(v[pos*2+1] >= v[pos*2+2] and pos*2+2 <= size){	
			if(v[pos*2+2] < v[pos]){							
				int aux = v[pos*2+2];							
				v[pos*2+2] = v[pos];							
				v[pos] = aux;									
			}
			
			heapify(v, pos*2+2, size);							
			return;
			}
		}
	}
}

bool isHeap(int v[], int TAM){
	for (int i = 0; i < (TAM-1)/2; i++){
		if (v[i] > v[2*i+1]){
			cout << "Não é uma Heap!" << endl;
			return false;
		}
		else if (v[i] > v[2*i+2]){
			cout << "Não é uma Heap!" << endl;
			return false;
		}
	}
	cout << "É uma Heap!" << endl;
	return true;
}

int main(){

	ofstream f_out;
	f_out.open("dados50000.txt");

	if(!f_out.good())
		return -1;
	else cout << "Arquivo criado.";

	int TAM = 50000;
	int heap[TAM];
	
	/*for (int i = 0; i < TAM; i++){
		int element = TAM - i;
		heap[i] = element;
	}*/
	
	for (int i = 0; i < TAM; i++){
		int element = rand() % TAM;
		heap[i] = element;
	}
	
	double before = clock();
	
	for (int i = 0; i < TAM; i++){
		heapify(heap, i, TAM);
		double after = clock();
		double aux = (after - before)/((double) CLOCKS_PER_SEC);
		f_out << aux << endl;
	}

	f_out.close();
	return 0;	
}
