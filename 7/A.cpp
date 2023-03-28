#include <iostream>

using namespace std;

int parent(int i){
	return i/2;
}

int left(int i){
	return 2*i;
}

int right(int i){
	return 1+2*i;
}

void maxheapify(int *A, int n, int i){
	int l = left(i);
	int r = right(i);
	int largest;
	if (l < n && A[l] > A[i])
		largest = l;
	else
		largest = i;
	if (r < n && A[r] > A[largest])
		largest = r;
	if (largest != i){
		int temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		maxheapify(A,n,largest);
	}
}

void buildmaxheap(int *A, int n){
	for (int i = n/2; i >= 0; i--)
		maxheapify(A,n,i);
}

int minMoney(int *A, int n, int m){
	buildmaxheap(A,n);
	for (int j = 1; j <= m; j++){
		A[0]/=2;
		maxheapify(A,n,0);
	}
	int money = 0;
	for (int k = 0; k < n; k++){
		money+=A[k];
	}
	return money;
}

int main(){
	int n, m;
	cin >> n >> m;
	int A[n];
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	cout << minMoney(A,n,m) << endl;
	return 0;
}
