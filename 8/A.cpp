// Words are anagrams if frequency arrays of their chars are identical
// We use a map to store <word, num of anagrams>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Returns a frequency array using ASCII values of characters
vector<int> genCountArr(string s){
	vector<int> freq(256);
	for (int i = 0; i < s.length(); i++)
		freq[s[i]]++;
	
	return freq;
}

int simScore(vector<string> inp, int n, int m){
	int ret = 0;
	map<vector<int>,int> daMap;	// <freq array of a word, count>
	vector<vector<int>> temp(n);	// stores freq arrays

	for (int i = 0; i < n; i++)
		temp[i] = genCountArr(inp[i]);
	
	for (int i = 0; i < n; i++)
		daMap[temp[i]]++;

	map<vector<int>,int>::iterator it = daMap.begin();
	while (it != daMap.end()){
		ret += (it->second)*(it->second - 1)/2;
		it++;
	}
	return ret;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<string> input(n);
	for (int i = 0; i < n; i++)
		cin >> input[i];
	
	cout << simScore(input,n,m) << endl;
	return 0;
}
