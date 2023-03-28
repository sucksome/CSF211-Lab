#include <iostream>
#include <queue>

using namespace std;

int maxSatis(int n, int k, int *inpArr){
	priority_queue<int> maxHeap;
	for (int i = 0; i < n; i++)
		maxHeap.push(inpArr[i]);
	
	int r = 0, top;
	for (int i = 0; i < k; i++){
		top = maxHeap.top();
		maxHeap.pop();
		maxHeap.push(top/2);
		r += top - top/2;
	}
	return r;
}

int main(){
	int n, k;
	cin >> n >> k;
	int inpArr[n];
	for (int i = 0; i < n; i++)
		cin >> inpArr[i];
	cout << maxSatis(n,k,inpArr) << endl;
	return 0;
}
