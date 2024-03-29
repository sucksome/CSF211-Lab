#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

void printEm(int n, int m, int k, vector<int> A){
	map<int,int> buff;	// <number, count>
	set<int> ks;		// set consisting of nums with count k
	
	for (int i = 0; i < m; i++)
		buff[A[i]]++;

	map<int,int>::iterator it = buff.begin();
	while (it != buff.end()){
		if (it->second == k)
			ks.insert(it->first);
		it++;
	}
	if (!ks.empty())
		cout << *ks.rbegin() << endl;	//print last element (largest) in set
	else
		cout << -1 << endl;

	// use a sliding window
	for (int i = m; i < n; i++){
		// remove from set if the incoming and outgoing elements were
		// already in the set

		if (buff[A[i-m]] == k){
			auto iter = ks.find(A[i-m]);
			ks.erase(iter);
		}
		if (buff[A[i]] == k){
			auto iter = ks.find(A[i]);
			ks.erase(iter);
		}
		
		// update counts
		buff[A[i-m]]--;
		buff[A[i]]++;

		// if counts equal k add the num to set
		if (buff[A[i-m]] == k)
			ks.insert(A[i-m]);
		if (buff[A[i]] == k)
			ks.insert(A[i]);

		if (!ks.empty())
			cout << *ks.rbegin() << endl;	//print max num
		else
			cout << -1 << endl;
	}
}

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	printEm(n,m,k,A);
	return 0;
}
