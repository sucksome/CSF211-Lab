#include <stdio.h>

int bitXOR(int a, int b, int A[], int B[]){
	int operands[a+b], i, result = 0;
	for (i = 0; i < a; i++){
		operands[i] = A[i];
	}
	for(i=a; i < a+b; i++){
		operands[i] = B[i-a];
	}
	for (i = 0; i < a+b; i++){
		result^=operands[i];
	}
	return result;
}

int main(){
	int a, b;
	scanf("%d",&a);
	int A[a];
	for (int i = 0; i < a; i++)
		scanf("%d",&A[i]);
	scanf("%d",&b);
	int B[b];
	for (int i = 0; i < b; i++)
		scanf("%d",&B[i]);
	printf("%d\n",bitXOR(a,b,A,B));
	return 0;
}
