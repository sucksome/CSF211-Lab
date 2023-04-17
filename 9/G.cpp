#include <bits/stdc++.h>

using namespace std;

int digits(int i){
	int d = 0;
	do{
		d++;
		i/=10;
	}while (i > 0);

	return d;
}

bool compare(pair<int,int> a, pair<int,int> b){
	while (a.second != b.second){
		if (a.second < b.second){
			a.first = a.first % 10 + a.first * 10;
			a.second++;
		}
		else{
			b.first = b.first % 10 + b.first * 10;
			b.second++;
		}
	}
	return b.first < a.first;
}

void largestInt(int n, int nums[]){
	pair<int,int> arr[n];

	for (int i = 0; i < n; i++)
		arr[i] = {nums[i],digits(nums[i])};
	
	sort(arr,arr+n,compare);

	for (int i = 0; i < n; i++)
		cout << arr[i].first;
	cout << endl;
}

int main(){
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	largestInt(n,nums);
	return 0;
}
