# include <iostream>

using namespace std;

bool works(int val, int n, int m, int books[]){
	int sum = 0, count = 0;
	for (int i = 0; i < n; i++){
		if (books[i] > val)
			return false;

		sum += books[i];
		if (sum > val){
			sum = books[i];
			count++;
		}
	}
	count++;
	if (count <= m)
		return true;
	return false;
}

int minMaxPages(int n, int m, int books[], int sum){
	int l = 0, r = sum, mid, ret = books[0];
	
	while (r - l > 1){
		mid = (l+r)/2;
		if (works(mid,n,m,books)){
			ret = mid;
			r = mid;
		}
		else
			l = mid;
	}

	return ret;
}

int main(){
	int n, m, sum = 0;
	cin >> n >> m;
	int books[n];
	for (int i = 0; i < n; i++){
		cin >> books[i];
		sum += books[i];
	}
	cout << minMaxPages(n,m,books,sum) << endl;
	return 0;
}
