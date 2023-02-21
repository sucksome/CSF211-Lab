#include <stdio.h>

void sieve(int n, int prime[n+1], int B[n+1]){
    for (int i = 0; i < n+1; i++){
        prime[i] = 1;
    }
    for (int p = 2; p * p <= n; p++){
        if (prime[p] == 1){
            for (int i = p * p; i <= n; i+=p){
                prime[i] = 0;
            }
        }
    }
    int count = 0;
    for (int j = 2; j < n+1; j++){
        if (prime[j]){
            count++;
        }
        B[j] = count;
    }
}

int main(){
    int n, q;
    scanf("%d %d",&n,&q);
    int A[q];
    for (int i = 0; i < q; i++){
        scanf("%d",&A[i]);
    }
    int prime[n+1];
    int B[n+1];
    sieve(n,prime,B);
    for (int i = 0; i < q; i++){
        printf("%d ",B[A[i]]);
    }
    printf("\n");
    return 0;
}
