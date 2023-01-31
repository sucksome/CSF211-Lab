#include <stdio.h>

int check(int num, int n, int s, int A[n], int B[n]){
    if (num > 1 && s > 0){
        for(int i = 0; i < n; i++){
            int temp = A[i];
            A[i] = 0;
            if(check(num-1,n,s-temp,A,B)){
                B[i]=1;
                A[i]=temp;
                return 1;
            }
            A[i]=temp;
        }
        return 0;
    }
    else if(num == 1 && s>0){
        for(int i = 0; i < n; i++){
            if(A[i]==s){
                B[i]=1;
                return 1;
            }
        }
        return 0;
    }
    else{
        return 0;
    }
}

int main(){
    int n,s;
    scanf("%d",&n);getchar();
    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);getchar();
    }
    scanf("%d",&s);
    int f = 0;
    for(int i = 1; i < n+1; i++){ // i is the number of elements in final answer
        int B[n];
        for(int k = 0; k < n; k++){
            B[k]=0;
        }
        if(check(i,n,s,A,B)){
            f = 1;
            printf("POSSIBLE\n");
            for(int j = 0; j < n; j++){
                if(B[j]==1){
                    printf("%d ",j);
                }
            }
            printf("\n");
            break;
        }
    }
    if(f==0){
        printf("NOT POSSIBLE\n");
    }
    return 0;
}