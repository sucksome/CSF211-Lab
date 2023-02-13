#include <stdio.h>

int main(){
  int n,k;
  scanf("%d %d",&n,&k);
  int A[n];
  for(int i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }
  int l = 0, r = n-1;
  if(A[l]>k){
    printf("Not Possible\n");
    return 0;
  }
  while(l<r){
    if(r-l == 1){
      if(A[r]<=k)
        printf("%d\n",A[r]);
      else
        printf("%d\n",A[l]);
      break;
    }
    if(A[(l+r)/2]>k){
      r = (l+r)/2;
    }
    else if (A[(l+r)/2]<k){
      l = (l+r)/2;
    }
    else{
      printf("%d\n",k);
      break;
    }
  }
  return 0;
}
