#include <iostream>

using namespace std;

int left(int i){
	return 2*i;
}

int right(int i){
	return 2*i +1;
}

int parent(int i){
	return i/2;
}

int isLeaf(int i, int n){
	return (2*i > n);
}

int predecessor(int n, int index, int *treeArr){
	if (isLeaf(index,n) || treeArr[left(index)] == -1)
		return parent(index);
	
	index = left(index);
	while(treeArr[right(index)] != -1 && !isLeaf(index,n))
		index = right(index);
	return index;
}

int kthLargest(int n, int *treeArr, int k){
	int maxIndex;
	for (int i = 1; i <= n; i = right(i)){
		maxIndex = i;
		if (isLeaf(i,n) || treeArr[right(i)] == -1)
			break;
	}

	int kthIndex = maxIndex;
	for (int i = 0; i < k-1; i++){
		kthIndex = predecessor(n,kthIndex,treeArr);
	}
	return treeArr[kthIndex];
}

int main(){
	int n, k;
	cin >> n;
	int treeArr[n+1];
	for (int i = 1; i <= n; i++)
		cin >> treeArr[i];
	cin >> k;
	cout << kthLargest(n,treeArr,k) << endl;
	return 0;
}
