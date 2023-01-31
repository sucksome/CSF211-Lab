#include <stdio.h>
#include <string.h>

int main(){
    char S[1000];
    scanf("%s",S);
    int len = strlen(S);
    char A[len+1];
    int si[len];
    scanf("%s",A);
    int f, index;
    for(int i = 0; i < len; i++){
        si[i]=0;
    }
    for(int i = 0; i < len; i++){
        f = 0;
        for(int j = 0; j < len; j++){
            if(S[i]==A[j] && si[j]==0){
                f = 1;
                index = j;
            }
        }
        if(f){
            si[index]=i+1;
        }
        else{
            printf("NOT POSSIBLE\n");
            return 0;
        }
    }
    printf("POSSIBLE\n");
    for(int i = 0; i < len; i++){
        printf("%d ",si[i]);
    }
    printf("\n");
    return 0;
}