#include <bits/stdc++.h>

using namespace std;

int maxBottles(int n, int in[]){
	sort(in,in + n);
	
	int l = 0, r = n-1, score = 0;
	while (score >= 0 && l <= r){
		if (score + in[l] >= 0){
			score += in[l];
			l++;
		}
		else if (score + in[r] >= 0){
			score += in[r];
			r--;
		}
		else
			break;
	}
	return l + (n-r);
}

int main(){
	int n;
	cin >> n;
	int theLine[n];
	for (int i = 0; i < n; i++){
		cin >> theLine[i];
	}

	cout << maxBottles(n,theLine) << endl;
	return 0;
}
