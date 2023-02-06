#include <stdio.h>

struct country{
    char name[21];
    int gold, silver, bronze;
};

typedef struct country country;

void swap(country *i, country *j){
    country temp = *i;
    *i = *j;
    *j = temp;
}

int main(){
    int n;
    scanf("%d",&n);
    country A[n];
    for(int i = 0; i < n; i++){
        country c;
        scanf("%s %d %d %d",c.name,&c.gold,&c.silver,&c.bronze);
        A[i] = c;
    }
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(A[j].gold < A[j+1].gold){
                swap(&A[j],&A[j+1]);
            }
            else if(A[j].gold == A[j+1].gold){
                if(A[j].silver < A[j+1].silver){
                    swap(&A[j],&A[j+1]);
                }
                else if(A[j].silver == A[j+1].silver){
                    if(A[j].bronze < A[j+1].bronze){
                        swap(&A[j],&A[j+1]);
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%s\n",A[i].name);
    }
    return 0;
}
