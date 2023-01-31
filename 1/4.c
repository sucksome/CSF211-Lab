#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);getchar();
    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&A[i]);getchar();
    }
    int size = 0, temp;
    for(int i = 0; i < n-1; i++){
        if(A[i]>0 && A[i+1]<0 && size == 0){
            temp = A[i];
            A[i]=A[i+1];
            A[i+1]=temp;
        }
        else if (A[i]>0 && A[i+1]>0){
            size++;
        }
        else if (A[i]>0 && A[i+1]<0 && size>0){
            int ii = i;
            temp=A[i+1];
            for(int k = 0; k < size+1; k++){
                A[ii+1]=A[ii];
                ii--;
            }
            A[ii+1]=temp;
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    return 0;
}