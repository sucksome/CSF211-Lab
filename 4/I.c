#include <stdio.h>

int isGCD(int n, int A[n], int num){
    int count = 0;
    for (int i = 0; i < n; i++){
        if (A[i]%num!=0 && count == 0){
            count++;
        }
        else if (A[i]%num!=0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    scanf("%d",&n);
    int A[n], max = 0;
    for (int i = 0; i < n; i++){
        scanf("%d",&A[i]);
        if (A[i]>max)
            max = A[i];
    }
    int maxgcd = 0;
    for (int i = 1; i < max; i++){
        if(isGCD(n,A,i) && i > maxgcd)
            maxgcd = i;
    }
    printf("%d\n",maxgcd);
    return 0;
}
