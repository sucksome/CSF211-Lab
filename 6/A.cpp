#include <iostream>

using namespace std;

class MinStack{

public:
	
	int top_index, min;
	int A[1000];
	int mins[1000];
	MinStack(){
		top_index = -1;
		min = -1;
	}

	void push(int val){
		A[top_index+1] = val;
		if (top_index == -1 || val < min){
			min = val;
		}
		top_index++;
		mins[top_index] = min;
	}

	void pop(){
		if (A[top_index]==min)
			min = mins[top_index-1];
		top_index--;
	}

	int top(){
		return A[top_index];
	}

	int getMin(){
		return min;
	}

};

int main(){
	int n;
	cin >> n;
	MinStack stac;

	int inp;
	for (int i = 0; i < n; i++){
		cin >> inp;
		stac.push(inp);
	}
	
	int m;
	cin >> m;
	
	int choice;
	for (int i = 0; i < m; i++){
		cin >> choice;
		switch(choice){
			case 1:
				int x; cin >> x;
				stac.push(x);
				break;
			case 2:
				stac.pop();
				break;
			case 3:
				cout << stac.top() << endl;
				break;
			case 4:
				cout << stac.getMin() << endl;
		}
	}

	return 0;
}
