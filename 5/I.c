#include <stdio.h>

int numOfKool(int n, int k, int A[]){
	int numOfOdd = 0, count = 0;
	int oddPrefix[n+1];
	for (int i = 0; i < n; i++){
		oddPrefix[i] = 0;
	}
	for (int i = 0; i < n; i++){
		oddPrefix[numOfOdd]++;
		if(A[i]%2){
			numOfOdd++;
		}
		if (numOfOdd >= k){
			count += oddPrefix[numOfOdd - k];
		}
	}
	return count;
}

int main(){
	int n, k;
	scanf("%d %d",&n,&k);
	int A[n];
	for (int i = 0; i < n; i++){
		scanf("%d",&A[i]);
	}
	printf("%d\n",numOfKool(n,k,A));
	return 0;
}
