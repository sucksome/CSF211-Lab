// a_j - a_i = yj - xi can also be written as a_j - yj = a_i -xi
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// returns a_i - xi
int calcI(int a, int i, int x){
	return a - (x*i);
}

// returns a_j - yj
int calcJ(int a, int j, int y){
	return a - (y*j);
}

int numPairs(int n, int x, int y, vector<int> A){
	int ret = 0;
	map<int,int> temp;	// < a_i - xi, num of such i>
	temp[calcI(A[0],0,x)]++;
	
	int val;
	for (int i = 1; i < n; i++){
		// calc a_j - yi and check for the equal a_i - xi in map
		val = calcJ(A[i],i,y);
		ret += temp[val];

		// calc val which acts as a_i - xi for the upcoming indices
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
