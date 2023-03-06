#include <iostream>
#include <deque>

using namespace std;

void printMax(int n, int k, int A[]){
	deque<int> indices(k);

	for (int i = 0; i < k; i++){
		if ((!indices.empty()) && A[i] >= A[indices.back()]){
			indices.pop_back();
			i--;
			continue;
		}
		indices.push_back(i);
	}

	for (int i = k; i < n; i++){
		cout << A[indices.front()] << " ";
		
		while ((!indices.empty()) && indices.front() <= i-k){
			indices.pop_front();
		}

		while ((!indices.empty()) && A[i] >= A[indices.back()]){
			indices.pop_back();
		}
		indices.push_back(i);
	}
	cout << A[indices.front()] << endl;
}

int main(){
	int n, k;
	cin >> n >> k;
	int A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	printMax(n,k,A);
	return 0;
}
