#include <stdio.h>

int numOfSubs(int n, int k, int A[]){
	int preSumArr[n], count = 0;
	for (int i = 0; i < n; i++){
		preSumArr[i] = A[i];
	}
	for (int i = 1; i < n; i++){
		preSumArr[i]+=preSumArr[i-1];
	}
	int mod[n];
	for (int i = 0; i < n; i++){
		mod[i] = preSumArr[i] % k;
	}
	int F[k];
	for (int i = 0; i < k; i++){
		F[i] = 0;
	}
	for (int i = 0; i < n; i++){
		F[mod[i]]++;
	}
	count += ((F[0]*(F[0]-1))/2 + F[0]);
	for (int i = 1; i < k; i++){
		if (F[i] >= 2){
			count+= (F[i]*(F[i]-1))/2;
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
	printf("%d\n",numOfSubs(n,k,A));
	return 0;
}
