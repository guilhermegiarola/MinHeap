#include <iostream>
#include <math.h>
<<<<<<< HEAD
#include <stdlib.h>
#include <time.h>

using namespace std;

void constructHeap(int v[], int TAM){
	for (int i = 0; i < TAM; i++){
		v[i] = (rand() % TAM);
	}
}

void worstCase(int v[], int TAM){
	for (int i = 0; i < TAM; i++)
		v[i] = TAM - 1 - i;
}

=======
#define TAM 7

using namespace std;

>>>>>>> upstream/master
void heapify(int v[], int pos, int size){
	
	//If there are subroot->left and subroot->right:
	if(pos*2+2 <= size){										//O(1)
		//If the subroot->left is smaller than subroot->right and the position is smaller than the size of the heap:
<<<<<<< HEAD
		if(v[pos*2+1] < v[pos*2+2] and pos*2+1 <= size){		//O(1)
=======
		if(v[pos*2+1] < v[pos*2+2] and pos*2+1 <= size){		//O(1)	
>>>>>>> upstream/master
			if(v[pos*2+1] < v[pos]){							//O(1)
				int aux = v[pos*2+1];							//O(1)
				v[pos*2+1] = v[pos];							//O(1)
				v[pos] = aux;									//O(1)
			}
			
		heapify(v, pos*2+1, size);								//(O(height)
		return;
		}
	
<<<<<<< HEAD
		//If the subroot->right is smaller than subroot->left and the position is smaller than the size of the heap:
=======
		//If the subroot->right is smaller than subroot->left and is smaller than the size of the heap:
>>>>>>> upstream/master
		else if(v[pos*2+1] >= v[pos*2+2] and pos*2+2 <= size){	//O(1)
			if(v[pos*2+2] < v[pos]){							//O(1)
				int aux = v[pos*2+2];							//O(1)
				v[pos*2+2] = v[pos];							//O(1)
				v[pos] = aux;									//O(1)
			}
			
			heapify(v, pos*2+2, size);							//O(height)
			return;
		}
	}
}

/*

	The algorithm "heapify" above works for every node above the "leaves of the heap".
	So, we have:
	
	For the first level of numbers above, we have (n/2) * height (h) iterations.
	For the second level, we have (n/4) * (h+1) iterations, and so on.
	Therefore, we have:
	
	(n/2)*0 + (n/4)*1 + (n/8)*2 + (n/16)*3... + 1*h. (h being log n)
	
	We know that (1/2) + (1/4) + (1/8) +... = sum(1/2^n) from i = 1 to infinity.
	
	.: So, the results of sum(i/2^n) is equal to 1 (MONTEIRO, Martha). (https://www.ime.usp.br/~martha/somas-infinitas.pdf)
	
	Using Taylor's series, we can solve the following equation: https://stackoverflow.com/questions/9755721/how-can-building-a-heap-be-on-time-complexity
	
	.: Therefore, we have that the complexity is equal to n.
	

*/

//Evaluates and tests if the vector is a heap, actually.
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

	
	for (int TAM = 100; TAM < pow(10, 5); TAM = TAM + 500){
		int v[TAM];
		worstCase(v, TAM);
		time_t antes = clock();
		for (int i = (TAM-1)/2; i >= 0; i--){
			heapify(v, i, TAM);
		}
		time_t depois = clock();
		cout << depois - antes << ", " << TAM << endl;
	}
=======
int * insert(int v[], int i){
	int element;
	cin >> element;
	v[i] = element;
	heapify(v, i, TAM);
	return v;
}

int main(){
	
	int v[TAM];
	
	//Input of the elements of the heap.	
	for(int i = TAM-1; i >= 0; i--){
		insert(v, i);
	}
	
	//Printing the heapified heap (LOL).
	for(int i = 0; i < TAM; i++)
		cout << v[i] << " ";
	cout << endl;
>>>>>>> upstream/master
}
