#include <iostream>
#include <stack>

using namespace std;

int maxArea(int n, int hi[]){
	int maxArea = 0, height = 0, area = 0, his[n+2];
	stack<int> indices;
	indices.push(0);

	his[0] = 0;
	for (int i = 1; i <= n; i++){
		his[i] = hi[i-1];
	}
	his[n+1] = 0;

	for (int i = 0; i < n; i++){
		if (his[i] < his[indices.top()]){
			height = his[indices.top()];
			indices.pop();
			area = height * (i - indices.top() - 1);
			if (area > maxArea)
				maxArea = area;
			i--;
			continue;

		}
		indices.push(i);
	}
	return maxArea;
}

int main(){
	int n;
	cin >> n;
	int histogram[n];
	for (int i = 0; i < n; i++)
		cin >> histogram[i];
	cout << maxArea(n,histogram) << endl;
	return 0;
}
