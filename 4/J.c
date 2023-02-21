#include <stdio.h>

// Correct later: num of chocos limited so take care when median > mean

int numOfOp(int n, int A[n], int med){
    int ops = 0;
    for (int i = 0; i < n; i++){
        if (A[i]>med)
            ops+=A[i]-med;
        else
            ops+=med-A[i];
    }
    return ops;
}

void mergeSort(int n, int A[n]){
    if (n == 1)
        return;
    mergeSort(n/2,A);
    mergeSort(n-n/2,A+n/2);
    int L[n/2+1], R[n-n/2+1];
    for (int i = 0; i < n/2; i++){
        L[i] = A[i];
    }
    L[n/2] = __INT_MAX__;
    for (int i = 0; i < n-n/2; i++){
        R[i] = A[i+n/2];
    }
    R[n-n/2] = __INT_MAX__;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++){
        if (L[l] <= R[r]){
            A[i] = L[l];
            l++;
        }
        else{
            A[i] = R[r];
            r++;
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    for (int i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    mergeSort(n,A);
    if (n%2 == 0){
    	int m1 = A[n/2];
    	int m2 = A[n/2 - 1];
    	int n1 = numOfOp(n,A,m1);
    	int n2 = numOfOp(n,A,m2);
    	if (n1 < n2)
    		printf("%d\n",n1);
    	else
    		printf("%d\n",n2);
    }
    else{
    	int mid = A[n/2];
    	printf("%d\n",numOfOp(n,A,mid));
    }
    return 0;
}
