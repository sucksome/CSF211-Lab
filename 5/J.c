#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int genRand(int num, int i, int prev){
	if (i == 0)
		return num;
	int ran = rand() % i;
	if (ran == i-1){
		return num;
	}
	return prev;
}

int main(){
	int n;
	scanf("%d",&n);
	int num, prev;
	srand(time(NULL));
	for (int i = 0; i < n; i++){
		scanf("%d",&num);
		printf("%d\n",genRand(num,i,prev));
		prev = num;
	}
	return 0;
}
