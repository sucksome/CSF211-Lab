#include <iostream>
#include <set>

using namespace std;

void type1(long long k, set<long long> &buff){
	auto it = buff.find(k);
	if (it != buff.end()){
		buff.erase(it);
	}
	else{
		buff.insert(k);
	}
}

void type3(long long k, set<long long> &buff){
	auto it = buff.find(k);
	if (it != buff.end()){
		cout << k << endl;
	}
	else{
		buff.insert(k);
		auto iter = buff.find(k);
		if (it != buff.begin()){
			iter--;
			cout << *(iter) << endl;
			iter++;
			buff.erase(iter);
		}
		else{
			cout << -1 << endl;
			buff.erase(iter);
		}
	}
}

void type2(long long k, set<long long> &buff){
	auto it = buff.find(k);
	if (it != buff.end())
		cout << k << endl;
	else{
		buff.insert(k);
		auto iter = buff.find(k);
		iter++;
		if (iter != buff.end())
			cout << *iter << endl;
		else
			cout << -1 << endl;
		iter--;
		buff.erase(iter);
	}	
}

void queryEngine(long long n, int q){
	int type;
	long long k;
	set<long long> buff;
	for (int i = 0; i < q; i++){
		cin >> type >> k;
		switch (type){
			case 1:
				type1(k,buff);
				break;
			case 2:
				type2(k,buff);
				break;
			case 3:
				type3(k,buff);
				break;
		}
	}
}

int main(){
	long long n;
	int q;
	cin >> n >> q;
	queryEngine(n,q);
	return 0;
}
