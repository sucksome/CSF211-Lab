#include <iostream>
#include <stack>
#include <string>

using namespace std;

string simplify(string s){
	stack<string> stac;

	string dir;

	string res;

	for (int i = 0; i < s.length(); i++){
		dir.clear();

		while (s[i] == '/')
			i++;

		while (i < s.length() && s[i]!='/'){
			dir.push_back(s[i]);
			i++;
		}

		if (dir.compare("..") == 0){
			if (!stac.empty())
				stac.pop();
		}
		else if (dir.compare(".") == 0)
			continue;
		else if (dir.length()!=0){
			stac.push(dir);
		}
	}

	stack<string> stac2;

	while (!stac.empty()){
		stac2.push(stac.top());
		stac.pop();
	}

	res.append("/");

	while (!stac2.empty()){
		if (stac2.size() > 1)
			res.append(stac2.top() + "/");
		else
			res.append(stac2.top());
		stac2.pop();
	}

	return res;
}

int main(){
	string s;
	getline(cin,s);
	cout << simplify(s) << endl;
	return 0;
}
