#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, pair<int , int>> ord;

void mergeVec(int k, vector<vector<int>> inpVec, vector<int> &outVec){
	priority_queue <ord, vector<ord>, greater<ord> > minHeap;

	for (int i = 0; i < k; i++){
		minHeap.push({inpVec[i][0], {i , 0}});
	}

	int index, inIndex;
	while (!minHeap.empty()){
		ord minEle = minHeap.top();
		minHeap.pop();

		index = minEle.second.first;
		inIndex = minEle.second.second;

		outVec.push_back(minEle.first);

		if (inpVec[index].size() > inIndex+1){
			minHeap.push({inpVec[index][inIndex+1],{index , inIndex + 1}});
		}
	}
}

int main(){
	int k, count = 0;
	cin >> k;
	vector<vector<int>> inpVec(k);
	for (int i = 0; i < k; i++){
		int temp;
		cin >> temp;
		for (int j = 0; j < temp; j++){
			int temp2;
			cin >> temp2;
			inpVec[i].push_back(temp2);
		}
	}

	vector<int> outVec;
	mergeVec(k,inpVec,outVec);

	for (int i = 0; i < outVec.size(); i++)
		cout << outVec[i] << " ";
	cout << endl;
	return 0;
}
