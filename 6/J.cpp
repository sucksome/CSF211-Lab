#include <iostream>
#include <string>
#include <stack>

using namespace std;

int numOp(string s){
	int l = s.length();

	stack<char> stac;
	stac.push(s[0]);

	for (int i = 1; i < l; i++){
		if (stac.empty() || s[i] == stac.top() || stac.top() == ')')
			stac.push(s[i]);
		else{
			stac.pop();
		}
	}

	int count = 0;
	while(!stac.empty()){
		count++;
		stac.pop();
	}

	return count;
}

int main(){
	string s;
	getline(cin,s);
	cout << numOp(s) << endl;
	return 0;
}
