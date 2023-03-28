#include <iostream>

using namespace std;

int parent(int i){
	return i/2;
}

int latestAncestor(int n, int iX, int iY, int *inpArr){
	while (parent(iX) != parent(iY) && iX != parent(iY) && iY != parent(iX)){
		if (iX < iY)
			iY = parent(iY);
		else
			iX = parent(iX);
	}
	if (iX == parent(iY))
		return inpArr[iX];
	else if (iY == parent(iX))
		return inpArr[iY];
	else
		return inpArr[parent(iX)];
}

int main(){
	int n, x, y, iX, iY;
	cin >> n >> x >> y;
	int inpArr[n+1];
	for (int i = 1; i <= n; i++){
		cin >> inpArr[i];
		if (inpArr[i] == x)
			iX = i;
		if (inpArr[i] == y)
			iY = i;
	}
	
	cout << latestAncestor(n,iX,iY,inpArr) << endl;
	return 0;
}
