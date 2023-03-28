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

int numFree (int n, int *inArr, int x, int index){
	int r = 0;
	if (inArr[index] == -1 || x < 0 || index > n){
		return 0;
	}
	r += numFree(n,inArr,x-inArr[index],left(index));

	if (inArr[index]==x && (2*index > n))
		return 1;
	
	r += numFree(n,inArr,x-inArr[index],right(index));
	return r;
}

int main(){
	int n, x;
	cin >> n >> x;
	int inArr[n+1];
	for (int i = 1; i <= n; i++)
		cin >> inArr[i];
	cout << numFree(n,inArr,x,1) << endl;
	return 0;
}
