#include <stdio.h>

int validWindow(int k, int A[k]){
	int sum = 0;
	for (int i = 0; i < k; i++){
		if (A[i]>0){
			sum++;
		}
	}
	if (sum == k){
		return 1;
	}
	return 0;
}

int numOfStr(int n, int k, char A[]){
	int count = 0;
	int l = 0, r = 1; 
	int win[k];
	for (int i = 0; i < k; i++){
		win[i]=0;
	}
	win[A[0]-97]=1;
	for (int i = 1; i < n; i++){
		if (A[i]==A[l]){
			win[A[l]-97]--;
			l++;
		}
		r = i;
		win[A[r]-97]++;
		if (validWindow(k,win)){
			count+=l+1;
			while (validWindow(k,win)){
				win[A[l]-97]--;
				l++;
				count++;
			}
			count--;
			l--;
			win[A[l]-97]++;
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
