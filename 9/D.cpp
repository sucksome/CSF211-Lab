// replace each element with ele - k and find num of subarr with sum = 0
// can be done in O(n) with array in place of map
#include <iostream>
#include <map>

using namespace std;

int numArr(int n, int arr[], int k){
	map<int,int> sumFreq;
	int res = 0, sum = 0;

	for (int i = 0; i < n; i++){
		sum += arr[i] - k;
		sumFreq[sum]++;
	}

	for (auto it : sumFreq)
		res += (it.second)*(it.second -1)/2;
	res += sumFreq[0];
	return res;
}

int main(){
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	cout << numArr(n,arr,k) << endl;
	return 0;
}
