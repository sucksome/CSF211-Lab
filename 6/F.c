#include <stdio.h>

int addFront(int front, int n, int Q[], int ele){
	if (front < 1)
		front = n-1;
	else
		front--;
	Q[front] = ele;
	return front;
}

int addBack(int back, int n, int Q[], int ele){
	if (back == n-1)
		back = 0;
	else
		back++;
	Q[back] = ele;
	return back;
}

void printQ(int n, int front, int Q[]){
	for (int i = 0; i < n; i++){
		printf("%d ",Q[front]);
		if (front == n-1 ){
			front = 0;
		}
		else
			front++;
	}
	printf("\n");
}

void minLex(int n, int Q[], int A[]){
	int front = -1, back = 0;
	Q[0] = A[0];
	for (int i = 1; i < n; i++){
		if (A[i] > Q[back])
			back = addBack(back,n,Q,A[i]);
		else if (front ==  -1 || A[i] < Q[front])
			front = addFront(front,n,Q,A[i]);
		else
			back = addBack(back,n,Q,A[i]);
		if (front == -1){
			front = 0;
		}
	}
	printQ(n,front,Q);
}

int main(){
	int n;
	scanf("%d",&n);
	int A[n];
	for (int i = 0; i < n; i++){
		scanf("%d",A+i);
	}
	int doubleQ[n];
	minLex(n,doubleQ, A);
	return 0;
}
