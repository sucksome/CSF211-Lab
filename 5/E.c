#include <stdio.h>

int max(int a, int b){
	return (a>b)?a:b;
}

int maxDyn(int n, int k, int A[n]){
	int maxx = 0, l = 0, cZero = 0;
	for (int i = 0; i < n; i++){
		if (A[i] == 0)
			cZero++;
		if (cZero > k){
			if (A[l] == 0)
				cZero--;
			l++;
		}
		maxx = max(maxx,i-l+1);
	}
	return maxx;
}

int main(){
	int n, k;
	scanf("%d %d",&n,&k);
	int A[n];
	for (int i = 0; i < n; i++){
		scanf("%d",&A[i]);
	}
	printf("%d\n",maxDyn(n,k,A));
	return 0;
}
