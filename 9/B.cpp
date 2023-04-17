#include <iostream>
#include <string>

using namespace std;

void init(string table, int freq[], int nextCandle[], int n){
	int score = 0, f = 0;

	for (int i = 0; i < n; i++)
		freq[i] = 0;

	for (int i = 0; i < n; i++){
		if (table[i] == '|'){
			if (f){
				freq[i] = score;
				score = 0;
			}
			else
				f = 1;
		}
		else{
			if (f)
				score++;
		}
	}

	for (int i = 1; i < n; i++)
		freq[i] += freq[i-1];
	
	int index = n-1;
	f = 0;
	for (int i = n-1 ; i > 0; i--){
		if (table[i] == '|'){
			f = 1;
			index = i;
			nextCandle[i] = i;
		}
		else{
			nextCandle[i] = index;
			if (!f)
				index--;
		}
	}
}

int main(){
	int n, q;
	cin >> n >> q;
	cin.ignore();
	string table;
	getline(cin,table);

	int freq[n];
	int nextCandle[n];
	init(table,freq,nextCandle,n);

	for (int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		l = nextCandle[l] < r ? nextCandle[l] : l;
		cout << freq[r] - freq[l] << endl;
	}

	return 0;
}
