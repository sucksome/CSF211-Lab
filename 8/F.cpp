#include <iostream>
#include <map>
#include <vector>

using namespace std;

int numArr(int n, vector<int> A){
	int ret = 0;
	map<int,int> pXor; // <xor, count>
	vector<int> temp(n);
	temp[0] = A[0];
	for (int i = 1; i < n; i++)
		temp[i] = A[i] ^ temp[i-1];

	for (int i = 0; i < n; i++)
		pXor[temp[i]]++;

	map<int,int>::iterator it = pXor.begin();
	while (it != pXor.end()){
		if (it->first == 0 && it->second == 1)
			ret++;
		if (it->second > 1)
			ret += (it->second)*(it->second -1)/2;
		it++;
	}

	return ret;
}

int main(){
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	
	cout << numArr(n,A) << endl;
	return 0;
}
