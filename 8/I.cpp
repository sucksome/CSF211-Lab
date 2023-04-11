// Use array instead of map for a faster solution
// I'm using map just for the sake of it

#include <iostream>
#include <map>

using namespace std;

void nextRound(int n, int k, pair<int,int> tuples[]){
	map<int,int> lostMatches; // <player, num of lost matches>

	for (int i = 0; i < n; i++){
		lostMatches[tuples[i].first]; //just so that winner is also present in map, not needed if a for loop (0 to k) is used in line 17 instead
		lostMatches[tuples[i].second]++;
	}

	for (auto iter : lostMatches){
		if (iter.second < 2)
			cout << iter.first << " ";
	}
	cout << endl;
}

int main(){
	int n, k;
	cin >> n >> k;
	pair<int,int> tuples[n];
	for (int i = 0; i < n; i++){
		cin >> tuples[i].first;
		cin >> tuples[i].second;
	}
	
	nextRound(n,k,tuples);
	return 0;
}
