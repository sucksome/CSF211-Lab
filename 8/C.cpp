#include <iostream>
#include <map>
#include <vector>

using namespace std;

int calcI(int a, int i, int x){
	return a - (x*i);
}

int calcJ(int a, int j, int y){
	return a - (y*j);
}

int numPairs(int n, int x, int y, vector<int> A){
	int ret = 0;
	map<int,int> temp;
	temp[calcI(A[0],0,x)]++;
	
	int val;
	for (int i = 1; i < n; i++){
		val = calcJ(A[i],i,y);
		ret += temp[val];
		val = calcI(A[i],i,x);
		temp[val]++;
	}
	return ret;
}

int main(){
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	int x, y;
	cin >> x >> y;

	cout << numPairs(n,x,y,A) << endl;
	return 0;
}
