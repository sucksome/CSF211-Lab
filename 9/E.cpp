#include <iostream>
#include <map>

using namespace std;

void matMul(map<pair<int,int>,int> A, map<pair<int,int>,int> B){
	map<pair<int,int>,int> C;
	for (auto iterA : A){
		for (auto iterB : B){
			if (iterA.first.second == iterB.first.first){
				C[{iterA.first.first, iterB.first.second}] += iterA.second * iterB.second;
			}
		}
	}

	cout << C.size() << endl;
	for (auto iterC: C){
		cout << iterC.first.first << " " << iterC.first.second << " " << iterC.second << endl;
	}
}

int main(){
	int m, k, n;
	cin >> m >> k >> n;

	int p;
	cin >> p;
	map<pair<int,int>,int> A;
	for (int i = 0; i < p; i++){
		int x, y, val;
		cin >> x >> y >> val;
		A.insert({{x,y},val});
	}

	int q;
	cin >> q;
	map<pair<int,int>,int> B;
	for (int i = 0; i < q; i++){
		int x, y, val;
		cin >> x >> y >> val;
		B.insert({{x,y},val});
	}

	matMul(A,B);
	return 0;
}
