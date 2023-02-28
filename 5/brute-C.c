#include <stdio.h>

int sumArr(int k, int A[k]){
	int sum = 0;
	for (int i = 0; i < k; i++){
		sum+=A[i];
	}
	return sum;
}

int numOfStr(int n, int k, char A[]){
	int count = 0;
	/*int postConsec[n];*/
	/*for (int i = 0; i < n; i++){*/
		/*postConsec[i]=1;*/
	/*}*/
	/*for (int i = n-1; i > 0; i--){*/
		/*if (A[i]==A[i-1]){*/
			/*postConsec[i-1]+=postConsec[i];*/
		/*}*/
	/*}*/
	/*for (int i = 0; i < k; i++){*/
		/*win[i]=0;*/
	/*}*/
	/*win[A[0]-97]=1;*/
	/*for (int i = 1; i < n; i++){*/
		/*if (A[i]==A[l]){*/
			/*l++;*/
		/*}*/
		/*r = i;*/
		/*win[A[r]-97] = 1;*/
		/*if (sumArr(k,win)==k){*/
			/*count+=l+1;*/
			/*count+=postConsec[l]-1;*/
		/*}*/
	/*}*/
	for (int size = k; size <=n; size++){
		for (int i = 0; i <=n-size; i++){
			int F[k];
			for (int j = 0; j < k; j++){
				F[j]=0;
			}
			for (int z = i; z < size+i; z++ ){
				F[A[z]-97] = 1;
			}
			if (sumArr(k,F)==k){
				count++;
			}
		}
	}
	return count;
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	char A[n+1];
	scanf("%s",A);
	printf("%d\n",numOfStr(n,k,A));
	return 0;
}
