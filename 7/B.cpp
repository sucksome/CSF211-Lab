#include <iostream>
#include <vector>

using namespace std;

int left(int i){
	return 2*i;
}

int right(int i){
	return 2*i +1;
}

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(-1), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(int *preOrder, int *inOrder, int n){
	if (n <= 0)
		return nullptr;
	TreeNode *node = new TreeNode();
	if (n == 1){
		node->val = preOrder[0];
		return node;
	}

	int i = 0;
	while (inOrder[i] != preOrder[0]){
		i++;
	}

	node->left = buildTree(preOrder+1,inOrder,i);
	node->val = preOrder[0];
	node->right = buildTree(preOrder+i+1,inOrder+i+1,n-i-1);
	return node;
}

void buildArr(TreeNode *outHead, vector<int> &outArr, int index){
	if (outHead == nullptr)
		return;
	buildArr(outHead->left,outArr,left(index));
	if (index >= outArr.size()){
		outArr.resize(index+1,-1);
	}
	outArr[index] = outHead->val;
	buildArr(outHead->right,outArr,right(index));
}

int main(){
	int n;
	cin >> n;
	int preOrder[n], inOrder[n];
	for (int i = 0; i < n; i++)
		cin >> preOrder[i];
	for (int i = 0; i < n; i++)
		cin >> inOrder[i];

	TreeNode *root;
	root = buildTree(preOrder,inOrder,n);

	vector<int> outArr(n,-1);
	buildArr(root, outArr, 1);

	for (int i = 1; i < outArr.size(); i++)
		cout << outArr[i] << " ";
	cout << endl;
	return 0;
}
