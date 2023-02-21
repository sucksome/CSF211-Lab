#include <stdio.h>

void countSort(int n, int A[n], int dig){
    int F[10], div = 1;
    for (int i = 0; i < 10; i++){
        F[i] = 0;
    }
    for (int i = 0; i < dig-1; i++){
        div*=10;
    }
    for (int i = 0; i < n; i++){
        F[ (A[i]/div)%10 ]++;
    }
    for (int i = 1; i < 10; i++){
        F[i]+=F[i-1];
    }
    int FF[10];
    for (int i = 1; i < 10; i++){
        FF[i] = F[i-1];
    }
    FF[0] = 0;
    int sorted[n];
    for (int i = 0; i < n; i++){
        int val = (A[i]/div)%10;
        sorted[FF[val]] = A[i];
        FF[val]++;
    }
    for (int i = 0; i < n; i++){
        A[i] = sorted[i];
    }
}

void radixSort(int n, int A[n], int digits){
    for (int i = 1; i <= digits; i++){
        countSort(n,A,i);
        for (int j = 0; j < n; j++){
            printf("%d ",A[j]);
        }
        printf("\n");
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int A[n], max = 0;
    for (int i = 0; i < n; i++){
        scanf("%d",&A[i]);
        if (A[i] > max)
            max = A[i];
    }
    int digits = 1;
    while (max/10 > 0){
        digits++;
        max/=10;
    }
    radixSort(n,A,digits);
    return 0;
}
