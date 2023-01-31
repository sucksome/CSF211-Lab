#include <stdio.h>

int checkrows(int i, int j, int p, int q, int m, int n, int a[m][n], int b[p][q]){
    int r = 0;
    for(int ii = i; ii < i+p; ii++){
        for(int jj = j; jj< j+q; jj++){
            if( a[ii][jj] != b[ii-i][jj-j] ){
                r++;
                break;
            }
        }
    }
    return r;
}

int main(){
    int m,n,p,q;

    scanf("%d %d",&m,&n);getchar();
    int A[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&A[i][j]);
            getchar();
        }
    }

    scanf("%d %d",&p,&q);
    int B[p][q];
    for(int i = 0; i < p; i++){
        for(int j = 0; j < q; j++){
            scanf("%d",&B[i][j]);
            getchar();
        }
    }

    int counter = 0;
    for(int i = 0; i < m-p+1; i++){
        for(int j = 0; j < n-q+1; j++){
            int cr,cc;
            cr = checkrows(i,j,p,q,m,n,A,B);
            cc = checkrows(j,i,q,p,m,n,A,B);
            if(cr==0){
                if(cc==0){
                    i = m;
                    counter = 2;
                    printf("YES\n"); 
                    break;
                }
                else{
                    counter = 1;
                }
            }
            else if (cr < p || cc < q){
                counter = 1;
            }
        }
    }

    if(counter==0){
        printf("NO\n");
    }
    else if (counter == 1){
        printf("PARTIAL\n");
    }
    
    return 0;
}