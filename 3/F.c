#include <stdio.h>

int binS(int n, int A[n]){
  int r = 0;
  if(n==1 || A[0]==A[n-1]){
    return 1;
  }
  if(n == 2){
    return 2;
  }
  if(A[n/2]==A[n-1]){
    r += binS(1+n/2,A);
  }
  else if (A[n/2]==A[0]){
    r += binS(n-n/2,A+n/2);
  }
  else{
    if(A[n/2]==A[n/2-1]){r--;}
    r += binS(n/2,A);
    r += binS(n- n/2,A+n/2);
  }
  return r;
}

int main(){
  int n;
  scanf("%d",&n);
  int A[n];
  for (int i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }
  printf("%d\n",binS(n,A));
  return 0;
}
