#include <iostream>
#include <stack>

using namespace std;

int diff(int n, int prev, int next){
	if (prev > next)
		return n - prev + next;
	else
		return next - prev;
}

int next(int n, int &index){
	if (index == n-1)
		index = 0;
	else
		index++;
	return index;
}

void minRoom(int n, int maxindex,  int input[], int output[]){

	stack<int> elements, indices;
	elements.push(input[maxindex]);
	indices.push(maxindex);

	int index = next(n,maxindex);
	for (int i = 0; i < n; i++){
		if (elements.top() < input[index]){
			output[indices.top()] = diff(n,indices.top(),index);
			elements.pop(); indices.pop();
			i--;
			continue;
		}
		else{
			elements.push(input[index]);
			indices.push(index);
		}
		next(n,index);
	}

	while (!elements.empty()){
		output[indices.top()] = -1;
		indices.pop();
		elements.pop();
	}
}

int main(){
	int n;
	cin >> n;
	int input[n], max = -100, maxindex;
	for (int i = 0; i < n; i++){
		cin >> input[i];
		if (input[i] > max){
			max = input[i];
			maxindex = i;
		}
	}

	int output[n];
	minRoom(n,maxindex,input,output);

	for (int i = 0; i < n; i++)
		cout << output[i] << " ";
	cout << "\n";

	return 0;
}
