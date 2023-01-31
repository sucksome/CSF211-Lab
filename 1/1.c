#include <stdio.h>

void print(int m, int n, int matrix[m][n]){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    getchar();
    int temp, B[m][n], r=0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&temp);
            getchar();
            r+=temp;
            B[i][j]=r;
        }
    }

    int ri, ci , rh, ch;
    scanf("%d %d %d %d",&ri,&ci,&rh,&ch); getchar();

    print(m,n,B);

    int p=0;
    if(rh+ri<=m && ch+ci<=n){
        for(int i = ri; i < rh+ri; i++){
            for(int j = ci; j < ch+ci; j++){
                p+=B[i][j];
            }
        }
        printf("%d\n",p);
    }
    else{
        printf("NOT POSSIBLE\n");
    }

    return 0;
}
