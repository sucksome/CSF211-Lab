#include <stdio.h>

typedef long long ll;

ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll LargestCoPrime(ll a, ll b){
    ll max = 0;
    for (ll i = 1; i*i <= a; i++){
        if (a%i == 0){
            ll div = a/i;
            if (gcd(div,b) == 1 && div > max)
                max = div;
            else if (gcd(i,b) == 1 && i > max)
                max = i;
        }
    }
    return max;
}

int main(){
    ll a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld\n",LargestCoPrime(a,b));
    return 0;
}
