// Storing possible 'val's in a queue and removing (jump over) them if deemed unfit later in the traversal
#include <stdio.h>

void printNonRep(int n, int A[]){
	int F[n], jump[n], indQ[n], queue[n]; //indQ maps the indices to that number's position in queue
	for (int i = 0; i < n; i++){
		F[i] = 0;
		jump[i] = 1;
	}
	int index = 0, size = 0, val = -1;
	for (int i = 0; i < n; i++){
		if (A[i] == val){
			if (index + jump[index] >= size){
				val = -1;
			}
			else{
				index+=jump[index];
				val = queue[index];
			}
		}
		else{
			if (F[A[i]] == 0){
				F[A[i]]++;
				queue[size] = A[i];
				indQ[A[i]] = size;
				size++;
				if (val == -1){
					val = A[i];
				}
			}
			else if (F[A[i]] == 1){
				jump[indQ[A[i]]-1]+=1+jump[indQ[A[i]]];
				F[A[i]]++;
			}
		}
		printf("%d ",val);
	}
	printf("\n");
}

int main(){
	int n;
	scanf("%d",&n);
	int A[n];
	for (int i = 0; i < n; i++)
		scanf("%d",A+i);
	printNonRep(n,A);
	return 0;
}
