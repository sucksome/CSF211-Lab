#include <stdio.h>

void print(int m, int n, int dig,int matrix[m][n]){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j]==0){
                printf("%*s",dig," ");
            }
            else if(matrix[i][j]==-1){
                for(int k = 0; k < dig; k++){
                    printf("-");
                }
            }
            else if(matrix[i][j]==-2){
                printf("%*s|",dig-1," ");
            }
            else{
                printf("%*d",dig,matrix[i][j]);
            }
        }
        printf("\n");
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int p = 2*n-1;
    int A[p][p], h = 2*n*n;
    for(int i = 0; i < p; i++){
        for(int j = 0; j < p; j++){
            A[i][j]=0;
        }
    }
    if(n%2==0){
        int i = 0, j = 0, l = 0, u = 0, r = 1, d = 0;
        while(h!=0){
            A[i][j]=h;
            h-=2;
            if(h>0){
                if(r){
                    if(j+2 < p && A[i][j+2]==0){
                        A[i][j+1]=-1;
                        j+=2;
                    }
                    else{
                        r=0;
                        d=1;
                        A[i+1][j]=-2;
                        i+=2;
                    }
                }
                else if(d){
                    if(i+2 < p && A[i+2][j]==0){
                        A[i+1][j]=-2;
                        i+=2;
                    }
                    else{
                        d=0;
                        l=1;
                        A[i][j-1]=-1;
                        j-=2;
                    }
                }
                else if(l){
                    if(j-2 >= 0 && A[i][j-2]==0){
                        A[i][j-1]=-1;
                        j-=2;
                    }
                    else{
                        l=0;
                        u=1;
                        A[i-1][j]=-2;
                        i-=2;
                    }
                }
                else if(u){
                    if(i-2 >= 0 && A[i-2][j]==0){
                        A[i-1][j]=-2;
                        i-=2;
                    }
                    else{
                        u=0;
                        r=1;
                        A[i][j+1]=-1;
                        j+=2;
                    }
                }
            }
        } 
    }
    else{
        int i = p-1, j = p-1, l = 1, u = 0, r = 0, d = 0;
        while(h!=0){
            A[i][j]=h;
            h-=2;
            if(h>0){
                if(l){
                    if(j-2 >= 0 && A[i][j-2]==0){
                        A[i][j-1]=-1;
                        j-=2;
                    }
                    else{
                        l=0;
                        u=1;
                        A[i-1][j]=-2;
                        i-=2;
                    }
                }
                else if(u){
                    if(i-2 >= 0 && A[i-2][j]==0){
                        A[i-1][j]=-2;
                        i-=2;
                    }
                    else{
                        u=0;
                        r=1;
                        A[i][j+1]=-1;
                        j+=2;
                    }
                }
                else if(r){
                    if(j+2 < p && A[i][j+2]==0){
                        A[i][j+1]=-1;
                        j+=2;
                    }
                    else{
                        r=0;
                        d=1;
                        A[i+1][j]=-2;
                        i+=2;
                    }
                }
                else if(d){
                    if(i+2 < p && A[i+2][j]==0){
                        A[i+1][j]=-2;
                        i+=2;
                    }
                    else{
                        d=0;
                        l=1;
                        A[i][j-1]=-1;
                        j-=2;
                    }
                }
                
            }
        }
    }
    int dig = 0, f = 2*n*n;
    while(f!=0){
        f/=10;
        dig++;
    }
    print(p,p,dig,A);
    return 0;
}