#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

void kLargest(int n, int k, int *A, int *B){
	priority_queue<int> maxA, maxB;
	for (int i = 0; i < n; i++){
		maxA.push(A[i]);
		maxB.push(B[i]);
	}
	int smallN = sqrt(n) + 1;
	for (int cou = 0; cou < smallN; cou++){
		A[cou] = maxA.top();
		B[cou] = maxB.top();
		maxA.pop();
		maxB.pop();
	}

	priority_queue<int> maxC;
	int sum = 0;
	for (int i = 0; i < smallN; i++){
		for (int j = 0; j < smallN; j++){
			sum = A[i] + B[j];
			maxC.push(sum);
		}
	}

	for (int i = 0; i < k; i++){
		cout << maxC.top() << " ";
		maxC.pop();
	}
	cout << endl;
}

int main(){
	int n,k;
	cin >> n >> k;
	int A[n], B[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < n; i++)
		cin >> B[i];
	kLargest(n,k,A,B);
	return 0;
}
