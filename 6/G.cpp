#include <iostream>
#include <stack>

using namespace std;

void printSpread(int n, int A[]){
	stack<int> decIndices;
	decIndices.push(0);

	int oof[n+2];
	oof[0] = 10000000;
	for (int i = 1; i <= n; i++){
		oof[i] = A[i-1];
	}
	oof[n+1] = 10000000;

	for (int i = 1; i <= n; i++){
		while ( oof[decIndices.top()] <= oof[i] ){
			decIndices.pop();
		}
		cout << i-decIndices.top() << " ";
		decIndices.push(i);
	}
	cout << "\n";
}

int main(){
	int n;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	printSpread(n,A);
	return 0;
}
