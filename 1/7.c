#include <stdio.h>
#include <string.h>

int main(){
    char arr[1000], word[1000];
    scanf("%[^\n]s",arr);getchar();
    scanf("%s",word);
    int len = strlen(arr), len2 = strlen(word);
    int arrindex[len];
    for(int i = 0; i < len; i++){
        arrindex[i]=0;
        for(int j = 0; j < len2; j++){
            if(arr[i]==word[j]){
                arrindex[i]=1;
            }
        }
    }
    int size = 1100, index = -1;
    for(int i = 0; i < len; i++){
        if(arrindex[i]==1){
            int lol[len2];
            int size2 = 1100,complete;
            for(int r = 0; r < len2; r++){
                lol[r]=0;
            }
            for(int ii = i+1; ii < len; ii++){
                complete = 1;
                if(arrindex[ii]==1){
                    for(int g = 0; g < len2; g++){
                        if(arr[ii]==word[g] && lol[g]==0){
                            lol[g]=1;
                        }
                    }
                }
                for(int k = 0; k < len2; k++){
                    if(lol[k]!=1){
                        complete=0;
                    }
                }
                if(complete){
                    size2 = ii-i+1;
                    break;
                }
            }
            if(size2<=size){
                size=size2;
                index=i;
            }
        }
    }
    if(size!=1100){
        printf("%d %d\n",index,index+size-1);
        for(int i = index; i<index+size; i++){
            printf("%c",arr[i]);
        }
        printf("\n");
    }
    else{
        printf("NO WINDOW\n");
    }
    return 0;
}