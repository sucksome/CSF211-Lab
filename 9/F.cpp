#include <bits/stdc++.h>

using namespace std;

int numOp(int n, int points[], int k){
	sort(points, points + n);

	int l = 0, r = n/2 +1;
	int mid, f;
	while (r - l > 1){
		f = 0;
		mid = (l+r)/2;
		for (int i = 0; i < mid; i++){
			if (points[n-mid+i] - points[i] < k){
				r = mid;
				f = 1;
				break;
			}
		}
		if (!f)
			l = mid;
	}
	return l;
}

int main(){
	int n, k;
	cin >> n >> k;
	int points[n];
	for (int i = 0; i < n; i++)
		cin >> points[i];
	
	cout << numOp(n,points,k) << endl;
	return 0;
}
