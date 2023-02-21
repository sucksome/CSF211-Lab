#include <stdio.h>

void sortSlots(int n, int A[2*n]){
    if(n == 1)
        return;
    int s1 = n/2, s2 = n-n/2;
    sortSlots(s1,A);
    sortSlots(s2,A+2*s1);
    int L[2*s1+1],R[2*s2+1];
    int a, b;
    for (a = 0; a < 2*s1; a++){
        L[a] = A[a];
    }
    L[a] = __INT_MAX__;
    for (b = 0; b < 2*s2; b++){
        R[b] = A[2*s1+b];
    }
    R[b] = __INT_MAX__;
    a = 0; b = 0;
    for (int k = 0; k < n; k++){
        if(L[a] <= R[b]){
            A[2*k] = L[a];
            A[2*k+1] = L[a+1];
            a+=2;
        }
        else{
            A[2*k] = R[b];
            A[2*k+1] = R[b+1];
            b+=2;
        }
    }
}

int mergeSlots(int n, int A[n]){
    int r = 0;
    for (int i = 0; i < 2*n-1; i++){
        if(A[i+1] <= A[i]){
            A[i] = A[i+1] = -1;
            r++;
            i++;
        }
    }
    return n-r;
}

int main(){
    int n;
    scanf("%d",&n);
    int A[2*n];
    for (int i = 0; i < 2*n; i++)
        scanf("%d",&A[i]);
    sortSlots(n,A);
    int k = mergeSlots(n,A);
    printf("%d\n",k);
    int index = 0;
    for (int i = 0; i < k; i++){
        if(A[index]==-1){
            while(A[index]==-1)
                index++;
        }
        printf("%d ",A[index]);
        if(A[index+1]==-1){
            while(A[index+1]==-1)
                index++;
        }
        printf("%d\n",A[index+1]);
        index+=2;
    }
    return 0;
}