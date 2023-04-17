#include <bits/stdc++.h>

using namespace std;

int minPlatforms(int n, pair<int,int> trains[]){
	sort(trains, trains + n);
	priority_queue<int, vector<int>, greater<int>> q;
	int count = 1;
	q.push(trains[0].second);
	for (int i = 1; i < n; i++){
		if (trains[i].first > q.top())
			q.pop();
		else
			count++;
		
		q.push(trains[i].second);
	}
	return count;
}

int main(){
	int n;
	cin >> n;
	pair<int,int> trains[n];
	int a, d;
	for (int i = 0; i < n; i++){
		cin >> a >> d;
		trains[i] = {a,d};
	}

	cout << minPlatforms(n,trains) << endl;
	return 0;
}
