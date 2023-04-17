#include <iostream> 

using namespace std;

int minIndex(int n, int p[], int c[]){
	int diff[n], tc = 0, tp = 0;
	for (int i = 0; i < n; i++){
		diff[i] = p[i] - c[i];
		tp += p[i];
		tc += c[i];
	}
	if (tp < tc)
		return -1;
	
	int sum = 0, index = 0;
	for (int i = 0; i < n; i++){
		sum += diff[i];
		if (sum < 0){
			index = i + 1;
			sum = 0;
		}
	}
	return index;
}

int main(){
	int n;
	cin >> n;
	int petrol[n], consumption[n];
	for (int i = 0; i < n; i++)
		cin >> petrol[i];
	for (int i = 0; i < n; i++)
		cin >> consumption[i];

	cout << minIndex(n,petrol,consumption) << endl;
	return 0;
}
