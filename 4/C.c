#include <stdio.h>

int numZero(int n, int A[n], int B[n]){
    int max = 0;
    for (int j = 0; j < n; j++){
        int num = 0, e = A[j];
        while (e/5 > 0){
            num+=e/5;
            e/=5;
        }
        B[j] = num;
        if (num > max)
            max = num;
    }
    return max;
}

int numPairs(int n, int A[n], int B[n], int max){
    int r = 0;
    for (int k = 0; k <= max; k++){
        int c = 0;
        for (int kk = 0; kk < n; kk++){
            if (B[kk]==k)
                c++;
        }
        int val = (c*(c-1))/2;
        if (val > 0)
            r+=val;
    }
    return r;
}

int removeDup(int n, int A[n], int m, int F[m]){
    for (int i = 0; i <= m; i++){
        F[i] = 0;
    }
    for (int i = 0; i < n ; i++){
        F[A[i]]++;
    }
    int c = 0;
    for (int i = 0; i <=m ; i++){
        if(F[i] > 0){
            A[c] = i;
            c++;
        }
    }
    return c;
}

int main(){
    int n;
    scanf("%d",&n);
    int A[n], m = 0;
    for (int i = 0; i < n; i++){
        scanf("%d",&A[i]);
        if (A[i]>m)
            m = A[i];
    }
    int F[m+1];
    n = removeDup(n,A,m,F);
    int B[n];
    int max = numZero(n,A,B);
    printf("%d\n",numPairs(n,A,B,max));
    return 0;
}
