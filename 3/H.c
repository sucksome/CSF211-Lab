#include <stdio.h>

int main(){
  long i;
  scanf("%ld",&i);
  if(i == 0){
    printf("0\n");
    return 0;
  }
  long l = 0, r = i;
  while(l<r){
    if(r-l == 1){
      if(r*r>i)
        printf("%ld\n",l);
      else
        printf("%ld\n",r);
      break;
    }
    long g = (l+r)/2;
    long gg = g*g;
    if(gg>i){
      r = (l+r)/2;
    }
    else if(gg<i){
      l = (l+r)/2;
    }
    else{
      printf("%ld\n",g);
      break;
    }
  }
  return 0;
}
