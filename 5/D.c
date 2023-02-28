#include <stdio.h>

int numOfTeams(int n, int k, int t, int A[n]){
	int count = 0;
	int winSum = 0;
	int size = 0;
	for (int i = 0; i < n; i++){
		if (size==k){
			winSum+=A[i];
			winSum-=A[i-k];
			if (winSum/k >= t){
				count++;
			}
		}
		else{
			winSum+=A[i];
			size++;
			if (size==k && winSum/k >= t)
				count++;
		}
	}
	return count;
}

int main(){
	int n , k, t;
	scanf("%d %d %d",&n,&k,&t);
	int A[n];
	for (int i = 0; i < n; i++){
		scanf("%d",&A[i]);
	}
	printf("%d\n",numOfTeams(n,k,t,A));
	return 0;
}
