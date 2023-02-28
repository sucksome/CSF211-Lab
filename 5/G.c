#include <stdio.h>
#include <limits.h>

int min(int a, int b){
	return (a<b)?a:b;
}

int giveBucket(int n, int k, int A[], int iBucket, int prev, int frens[]){
	if (iBucket == n){
		int max = 0;
		for (int i = 0; i < k; i++){
			if (frens[i] > max)
				max = frens[i];
		}
		prev = min(max,prev);
		return prev;
	}
	for (int i = 0; i < k; i++){
		frens[i] += A[iBucket];
		prev = giveBucket(n,k,A,iBucket+1,prev,frens);
		frens[i] -= A[iBucket];
	}
	return prev;
}

int minUnf(int n, int k, int A[]){
	int frens[k];
	for (int i = 0; i < k; i++){
		frens[i]=0;
	}
	int prev = INT_MAX;
	return giveBucket(n,k,A,0,prev,frens);
}

int main(){
	int n, k;
	scanf("%d %d",&n,&k);
	int A[n];
	for (int i = 0; i < n; i++){
		scanf("%d",&A[i]);
	}
	printf("%d\n",minUnf(n,k,A));
	return 0;
}
