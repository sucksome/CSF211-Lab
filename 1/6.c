#include <stdio.h>

int isprime(int n){
    for(int i = 2; i < n; i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int A[10]={0,0,0,0,0,0,0,0,0,0};
    for(int i = a; i <= b; i++){
        if(isprime(i)){
            int ii = i;
            while(ii!=0){
                A[ii%10]++;
                ii=(ii-(ii%10))/10;
            }
        }
    }
    int max = 0, index;
    for(int i = 0; i < 10; i++){
        if(A[i]>max){
            max=A[i];
            index=i;
        }
    }
    printf("%d %d\n",index,A[index]);
    return 0;
}