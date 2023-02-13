#include <stdio.h>

long sum(long num, long i){
  long sum = 0;
  for(int k = 0; k < num; k++){
    i--;
    sum+=i;
  }
  return sum;
}

int main(){
  long i;
  scanf("%ld",&i);
  long total = (i*(i-1))/2;
  long half = total/2;
  long l = 1, r = i-1;
  if(i == 0){
    return 0;
  }
  if(l==r || l>r){
    printf("%ld\n",l);
    return 0;
  }
  while(l<r){
    if(r-l==1){
      if(sum(l,i)>=half)
        printf("%ld\n",l);
      else
        printf("%ld\n",r);
      break;
    }
    if(sum((l+r)/2,i)>half){
      r = (l+r)/2;
    }
    else if(sum((l+r)/2,i)<half){
      l = (l+r)/2;
    }
    else{
      printf("%ld\n",(l+r)/2);
      break;
    }
  }
  return 0;
}
