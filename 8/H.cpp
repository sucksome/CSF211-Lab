#include <iostream>
#include <set>
#include <vector>

using namespace std;

void printSeq(string s){
	vector<char> str(s.length());
	for (int i = 0; i < s.length(); i++)
		str[i] = s[i];
	
	set<vector<char>> S;
	set<vector<char>> buff;
	
	vector<char> temp(10);
	for (int i = 0; i < 10; i++)
		temp[i] = str[i];
	S.insert(temp);

	for (int i = 10; i < s.length(); i++){
		for (int ii = 0; ii < 10; ii++){
			temp[ii] = s[i-9+ii];
		}
		if (S.end() != S.find(temp)){
			buff.insert(temp);		
		}
		else{
			S.insert(temp);
		}
	}
	cout << buff.size() << endl;
	auto it = buff.begin();
	while (it != buff.end()){
		string st((*it).begin(), (*it).end());
		cout << st << endl;
		it++;
	}
}

int main(){
	string s;
	getline(cin,s);
	printSeq(s);
	return 0;
}
