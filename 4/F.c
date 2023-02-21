#include <stdio.h>

void sortVotes(int n, int F[n], int I[n]){
    if (n == 1)
        return;
    sortVotes(n/2,F,I);
    sortVotes(n-n/2,F+n/2,I+n/2);
    int LF[n/2 + 1], RF[n-n/2 + 1], LI[n/2], RI[n-n/2];
    for (int i = 0; i < n/2; i++){
        LF[i] = F[i];
        LI[i] = I[i];
    }
    LF[n/2] = -1;
    for (int i = 0; i < n-n/2; i++){
        RF[i] = F[i+n/2];
        RI[i] = I[i+n/2];
    }
    RF[n-n/2] = -1;
    int l = 0, r = 0;
    for (int k = 0; k < n; k++){
        if (LF[l] >= RF[r]){
            I[k] = LI[l];
            F[k] = LF[l];
            l++;
        }
        else {
            I[k] = RI[r];
            F[k] = RF[r];
            r++;
        }
    }
}

int main(){
    int n, k;
    scanf("%d %d",&n,&k);
    int A[n], F[n+1], I[n+1];
    for (int i = 0; i < n; i++){
        scanf("%d",&A[i]);
        F[i] = 0;
        I[i] = i;
    }
    F[n]=0; I[n] = n;
    for (int i = 0; i < n; i++){
        F[A[i]]++;
    }
    sortVotes(n+1,F,I);
    for (int i = 0; i < k; i++){
        printf("%d ",I[i]);
    }
    printf("\n");
    return 0;
}
