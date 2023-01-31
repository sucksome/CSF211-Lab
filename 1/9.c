#include <stdio.h>

int main(){
    int n,k;
    scanf("%d",&k);
    scanf("%d",&n);
    n--;
    int A[n], mid = (k+1)/2, tempvar;
    for(int i = 0; i < n; i++){
        scanf("%d",&tempvar);
        if(tempvar!=mid){
            A[i]=tempvar;
        }
        else{
            i--;
            continue;
        }
        getchar();
    }
    int size = 0, temp;
    for(int i = 0; i < n-1; i++){
        if(A[i]>mid && A[i+1]<mid && size == 0){
            temp = A[i];
            A[i]=A[i+1];
            A[i+1]=temp;
        }
        else if (A[i]>mid && A[i+1]>mid){
            size++;
        }
        else if (A[i]>mid && A[i+1]<mid && size>0){
            int ii = i;
            temp=A[i+1];
            for(int k = 0; k < size+1; k++){
                A[ii+1]=A[ii];
                ii--;
            }
            A[ii+1]=temp;
        }
    }
    int a = 1;
    for(int i = 0; i < n; i++){
        if(A[i]<mid){
            printf("%d ",A[i]);
        }
        else{
            if(a){
                printf("%d %d ",mid,A[i]);
                a=0;
            }
            else{
                printf("%d ",A[i]);
            }
        }
    }
    printf("\n");
    return 0;
}