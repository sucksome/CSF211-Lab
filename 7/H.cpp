#include <iostream>

using namespace std;

int left(int i){
	return 2*i;
}

int right(int i){
	return 2*i +1;
}

int isLeaf(int i, int n){
	return (2*i > n);
}

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(): val(-1), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(int n, int *inpArr, int index){
	if (inpArr[index] == -1)
		return nullptr;

	TreeNode *node = new TreeNode();
	if (isLeaf(index,n) || inpArr[left(index)] == -1 && inpArr[right(index)] == -1){
		node->val = inpArr[index];
		return node;
	}
	node->left = buildTree(n,inpArr,left(index));
	node->val = inpArr[index];
	node->right = buildTree(n,inpArr,right(index));
	return node;
}

TreeNode *beautify(TreeNode *node, int l, int r){
	if (node == nullptr)
		return nullptr;

	node->left = beautify(node->left, l, r);
   	node->right = beautify(node->right, l, r);
 
   	if (node->val < l){
       		TreeNode *rN = node->right;
       		delete node;
       		return rN;
   	}
   	if (node->val > r){
      		TreeNode *lN = node->left;
       		delete node;
       		return lN;
   	}
   	return node;
}

void printPost(TreeNode *node){
	if (node){
		printPost(node->left);
		printPost(node->right);
		cout << node->val << " ";
	}
}

int main(){
	int n, l, r;
	cin >> n >> l >> r;
	int inpArr[n+1];
	for (int i = 1; i <= n; i++)
		cin >> inpArr[i];
	
	TreeNode *head;
	head = buildTree(n,inpArr,1);
	head = beautify(head,l,r);
	printPost(head);
	cout << endl;
	return 0;
}
