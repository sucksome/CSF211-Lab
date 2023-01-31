#include <stdio.h>
#include <string.h>

int main(){
    char S[1000];
    scanf("%[^\n]s",S);
    int len = strlen(S);
    char palindromes[len+1];
    palindromes[0]='\0';
    int index = -2;
    for(int i = 0; i < len; i++){
        if(S[i+1]==' ' || S[i+1]=='\0'){
            int ii = i, f = 1, c = 0;
            while(S[ii]!=' ' && ii>=0){
                printf("%c",S[ii]);
                if(S[ii]!=S[index+2+c]){
                    f = 0;
                }
                c++;
                ii=i-c;
            }
            printf(" ");
            if(f && index+2!=i){
                strncat(palindromes,S+index+2,i-index);
            }
            index = i;
        }
    }
    printf("\n");
    if (palindromes[0]=='\0'){
        printf("NO PALINDROMES\n");
    }
    else{
        printf("%s\n",palindromes);
    }
    return 0;
}