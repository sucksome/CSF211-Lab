#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int compare(int i, int a, int b){
	if (i){
		if (a < b)
			return 1;
		return 0;
	}
	else{
		if (a > b)
			return 1;
		return 0;
	}
}

int compSum(int n, vector<int> in, int c){
	stack<int> Stack;
	vector<int> left(n);
	vector<int> right(n);

	for (int i = 0; i < n; i++){
		if (Stack.empty() || compare(c,in[Stack.top()],in[i])){
			left[i] = Stack.empty() ? -1 : Stack.top();
			Stack.push(i);
		}
		else{
			while (!Stack.empty() && compare(c, in[i], in[Stack.top()]) ){
				right[Stack.top()] = i;
				Stack.pop();
			}
			left[i] = Stack.empty() ? -1 : Stack.top();
			Stack.push(i);
		}
	}
	while (!Stack.empty()){
		right[Stack.top()] = n;
		Stack.pop();
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += in[i]*(i-left[i])*(right[i]-i);

	return sum;
}

int sumRange(int n, vector<int> in){
	return compSum(n,in,0) - compSum(n,in,1);
}

int main(){
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; i++)
		cin >> input[i];
	
	cout << sumRange(n,input) << endl;
	return 0;
}
