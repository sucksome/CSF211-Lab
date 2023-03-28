#include <iostream>

using namespace std;

int isLeaf(int i, int n){
	return (2*i > n);
}

int left(int i){
	return 2*i;
}

int right(int i){
	return 2*i +1;
}

void gstify(int n, int &sum, int *treeArr, int index){\
	if (treeArr[index] == -1)
		return;
	if (isLeaf(index,n)){
		sum -= treeArr[index];
		treeArr[index] += sum;
		return;
	}
	gstify(n,sum,treeArr,left(index));
	sum -= treeArr[index];
	treeArr[index] +=sum;
	gstify(n,sum,treeArr,right(index));
	return;
}

int main(){
	int n;
	cin >> n;
	int treeArr[n+1], sum = 0;
	for (int i = 1; i <= n; i++){
		cin >> treeArr[i];
		if (treeArr[i] != -1)
			sum += treeArr[i];
	}
	
	gstify(n,sum,treeArr,1);

	for (int i = 1; i <= n; i++)
		cout << treeArr[i] << " ";
	cout << endl;
	return 0;
}
