#include <stdio.h>

typedef long long ll;

ll pos(ll n){
	ll count = 1;
	ll r = 0;
	ll left = 1;
	ll right = n;
	ll start = 1;
	ll step = 1;
	for (ll i = n; i > 1; i/=2){
		step = 2*step;
		if (count%2){
			r = start + step/2;
			start = (right-start)%step==0?right-step/2:right;
			left = r;
		}	
		else {
			r = start - step/2;
			start = (start-left)%step==0?left+step/2:left;
			right = r;
		}
		count++;
	}
	return r;
}

int main(){
	ll n;
	scanf("%lld",&n);
	printf("%lld\n",pos(n));
	return 0;
}
