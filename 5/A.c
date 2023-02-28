#include <stdio.h>
#include <string.h>
#define MAX_SIZE 7000

int printSeq(int n, int index, int left, int right, char print[]){
	static int i;
	static char smol[15];
	if (index == n-1){
		smol[index] = ')';
		smol[index+1] = '\n';
		strcat(print,smol);
		i++;
		return i;
	}
	if (left > 0){
		smol[index] = '(';
		printSeq(n,index+1,left-1,right,print);
	}
	if (left < right){
		smol[index] = ')';
		printSeq(n,index+1,left,right-1,print);
	}
	return i;
}

int main(){
	int n;
	scanf("%d",&n);
	static char print[MAX_SIZE];
	int num = printSeq(n,0,n/2,n/2,print);
	printf("%d\n%s",num,print);
	return 0;
}
