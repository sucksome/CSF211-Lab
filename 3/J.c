#include <stdio.h>

int numOfPlanks(int n, int A[n], int size){
  int r = 0;
  for(int i = 0; i < n; i++){
    int e = A[i];
    while(e-size>=0){
      r++;
      e-=size;
    }
  }
  return r;
}

int main(){
  int n,k;
  scanf("%d %d",&n,&k);
  int A[n];
  int max = 1;
  for(int i = 0; i < n; i++){
    scanf("%d",&A[i]);
    if(A[i]>max){
      max = A[i];
    }
  }
  int l = 1, r = max;
  if(l==r){
    if(n>=k)
      printf("1\n");
    else
      printf("0\n");
    return 0;
  }
  int size = 0;
  while(l<r){
    if(r-l==1){
      if(numOfPlanks(n,A,r)>=k && r>size)
        size = r;
      else if (numOfPlanks(n,A,l)>=k && l>size)
        size = l;
      break;
    }
    int g = numOfPlanks(n,A,(l+r)/2);
    if(g>k){
      l = (l+r)/2;
    }
    else if(g<k){
      r = (l+r)/2;
    }
    else{
      size = (l+r)/2;
      l = (l+r)/2;
    }
  }
  printf("%d\n",size);
}
