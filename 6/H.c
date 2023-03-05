// simulates the process using a jump array to track how much to jump
#include <stdio.h>

int next(int n, int current, int jump[]){
	int next = -1;
	if (current + jump[current] >= n)
		next = jump[current] - (n-current);
	
	else
		next = current + jump[current];
	
	return next;
}

int newCycle(int n, int k, int current, int jump[]){
	int before = -1;
	for (int i = 1; i < k-1; i++)
		current = next(n,current,jump);
	
	before = current;
	if (k > 1){
		current = next(n,current,jump);
		jump[before]+=jump[current];
	}

	if (jump[before] >= n)
		jump[before]-=n;
	
	return next(n,current,jump);
}

int pos(int n, int k){
	int current = 0;
	int jump[n];
	for (int i = 0; i < n; i++)
		jump[i] = 1;
	
	for (int i = 0; i < n-1; i++)
		current = newCycle(n,k,current,jump);
	
	return current+1;
}

int main(){
	int n, k;
	scanf("%d %d",&n,&k);
	printf("%d\n",pos(n,k));
	return 0;
}
