#include <stdio.h>

typedef long long ll;

int main(){
    ll n, m;
    scanf("%lld %lld",&n,&m);
    ll max = ((n-m+1)*(n-m))/2;
    ll per = (n-m)/m;
    ll rem = n-m-(per*m);
    ll min = rem * (((per+2)*(per+1))/2);
    min += (m-rem) * ((per * (per + 1))/2);
    printf("%lld %lld\n",min,max);
    return 0;
}
